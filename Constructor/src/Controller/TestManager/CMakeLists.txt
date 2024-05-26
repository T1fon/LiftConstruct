find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(TestManager STATIC TestManager.cpp)

target_link_libraries(TestManager PRIVATE Qt6::Core)

target_link_directories(TestManager PUBLIC ../../Model)

target_link_libraries(TestManager PUBLIC TestModel)
