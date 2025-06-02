#ifndef QUICK_GENESIS_CLI_HPP
#define QUICK_GENESIS_CLI_HPP
#include <iostream>
#include <utility>


void hello(){
    std::cout << "hello from hpp" << std::endl;
}

struct config{
    std::string def_path;
    std::string out_path;
};

config get_cmd_path(int argc, char* argv[]){
    config cfg;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.find("--def_path=") == 0) {
            cfg.def_path = arg.substr(11); // lenght "--def_path="
        } else if (arg.find("--cpp_out=") == 0) {
            cfg.out_path = arg.substr(10); // lenght "--cpp_out="
        }
    }

    return cfg;
}

#endif

// ./genesis --def_path=../examples/library --cpp_out=library