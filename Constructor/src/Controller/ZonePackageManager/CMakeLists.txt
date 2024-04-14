find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(ZonePackageManager STATIC ZonePackageManager.cpp)
target_link_directories(ZonePackageManager PRIVATE ../ZonePackageModel)

target_link_libraries(ZonePackageManager PRIVATE Qt6::Core)
target_link_libraries(ZonePackageManager PRIVATE Qt6::Gui)
target_link_libraries(ZonePackageManager PRIVATE ZonePackageModel)
