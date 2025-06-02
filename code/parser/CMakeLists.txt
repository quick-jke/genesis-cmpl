file(GLOB PARSER_SOURCES "src/*.cc")

add_library(Parser STATIC ${PARSER_SOURCES})

target_include_directories(Parser PUBLIC include)

target_link_libraries(Parser PRIVATE Ast)
