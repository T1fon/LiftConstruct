find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(VirtualPortModel STATIC VirtualPortModel.cpp)

target_link_libraries(VirtualPortModel PRIVATE Qt6::Core)
