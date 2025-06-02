file(GLOB AST_SOURCES "src/*.cc")

add_library(Ast STATIC ${AST_SOURCES})

target_include_directories(Ast PUBLIC include)

target_link_libraries(Ast PUBLIC Moc)
