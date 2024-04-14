find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(TestModel STATIC TestModel.cpp)

target_link_libraries(TestModel PRIVATE Qt6::Core)
