find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(MainManager STATIC MainManager.cpp)

target_link_libraries(MainManager PRIVATE Qt6::Core)
