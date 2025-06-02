file(GLOB CODE_GEN_SOURCES "src/*.cc")

add_library(Generator STATIC ${CODE_GEN_SOURCES})

target_include_directories(Generator PUBLIC include)

target_link_libraries(Generator PRIVATE Ast)
