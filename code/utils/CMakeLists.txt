file(GLOB UTILS_SOURCES "src/*.cc")

add_library(Utils STATIC ${UTILS_SOURCES})

target_include_directories(Utils PUBLIC include)
