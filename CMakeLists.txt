cmake_minimum_required(VERSION 3.20)
project(genesis)
add_executable(${PROJECT_NAME} code/cli/main.cc)

add_subdirectory(code/parser)
add_subdirectory(code/ast)
add_subdirectory(code/codegen)
add_subdirectory(code/utils)
add_subdirectory(code/moc)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Parser
        Ast
        Generator
        Utils
)   