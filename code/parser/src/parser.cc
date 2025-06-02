#include "parser.hpp"



namespace quick{
namespace genesis{

std::string trims(const std::string& s) {
    size_t first = s.find_first_not_of(" \t\n\v\f\r");
    if (first == std::string::npos) return "";
    size_t last = s.find_last_not_of(" \t\n\v\f\r");
    return s.substr(first, last - first + 1);
}

void process_field(const std::string& line, quick::genesis::MocClass& moc_class) {
    std::string field_str = trims(line);
    if (field_str.empty()) return;

    size_t semicolon_pos = field_str.find(';');
    if (semicolon_pos != std::string::npos) {
        field_str = field_str.substr(0, semicolon_pos);
    }

    field_str = trims(field_str);
    if (!field_str.empty()) {
        moc_class.push_private_field(MocField(field_str));
    }
}

const AST Parser::parse(const std::string& content) {
    std::istringstream iss(content);
    std::string line;

    std::vector<std::string> global_imports;
    std::vector<MocClass> classes;
    quick::genesis::MocClass current_class;
    bool in_table = false;

    while (std::getline(iss, line)) {
        line = trims(line);
        if (line.empty()) continue;

        if (in_table) {
            if (line == "}") {
                classes.push_back(std::move(current_class));
                current_class = quick::genesis::MocClass();
                in_table = false;
                continue;
            }

            size_t brace_pos = line.find('}');
            if (brace_pos != std::string::npos) {
                std::string field_part = line.substr(0, brace_pos);
                process_field(field_part, current_class);

                classes.push_back(std::move(current_class));
                current_class = quick::genesis::MocClass();
                in_table = false;
                continue;
            }

            process_field(line, current_class);
        } else {
            if (line.find("import") != std::string::npos) {
                size_t pos = line.find("import");
                std::string import_path = line.substr(pos + 6);
                import_path = trims(import_path);
                if (!import_path.empty() && import_path.front() == '"' && import_path.back() == '"') {
                    import_path = import_path.substr(1, import_path.size() - 2);
                }
                global_imports.push_back(import_path);
            } else if (line.find("table") != std::string::npos) {
                size_t pos = line.find("table");
                std::string table_rest = line.substr(pos + 5);
                size_t brace_pos = table_rest.find('{');
                if (brace_pos == std::string::npos) continue;

                std::string class_name = table_rest.substr(0, brace_pos);
                class_name = trims(class_name);

                current_class.set_class_name(class_name);
                current_class.set_imports(global_imports);
                
                global_imports.clear();

                std::string remaining = table_rest.substr(brace_pos + 1);
                if (!remaining.empty()) {
                    size_t next_brace = remaining.find('}');
                    if (next_brace != std::string::npos) {
                        std::string field_part = remaining.substr(0, next_brace);
                        process_field(field_part, current_class);
                        classes.push_back(std::move(current_class));
                        current_class = quick::genesis::MocClass();
                        in_table = false;
                    } else {
                        process_field(remaining, current_class);
                        in_table = true;
                    }
                } else {
                    in_table = true;
                }
            }
        }
    }

    // Если таблица не закрыта
    if (!current_class.class_name().empty()) {
        classes.push_back(std::move(current_class));
    }

    return AST(classes);
}

}
}