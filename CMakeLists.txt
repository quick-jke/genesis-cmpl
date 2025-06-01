cmake_minimum_required(VERSION 3.20)
project(genesis)
add_executable(${PROJECT_NAME} src/cli/main.cc)

add_subdirectory(src/parser)
add_subdirectory(src/ast)
add_subdirectory(src/codegen)
add_subdirectory(src/utils)
add_subdirectory(src/moc)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Parser
        Ast
        Generator
        Utils
)   