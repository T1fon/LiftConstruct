find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(PackageModel STATIC PackageModel.cpp)

target_link_libraries(PackageModel PRIVATE Qt6::Core)
