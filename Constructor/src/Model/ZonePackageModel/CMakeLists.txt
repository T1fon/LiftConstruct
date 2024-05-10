find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(ZonePackageModel STATIC ZonePackageModel.cpp)

target_link_libraries(ZonePackageModel PRIVATE Qt6::Core)
target_link_libraries(ZonePackageModel PRIVATE Qt6::Gui)
