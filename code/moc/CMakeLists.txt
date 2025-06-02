file(GLOB MOC_SOURCES "src/*.cc")

add_library(Moc STATIC ${MOC_SOURCES})

target_include_directories(Moc PUBLIC include)

