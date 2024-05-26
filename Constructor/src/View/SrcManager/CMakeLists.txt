find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(SRCManager STATIC SRCManager.cpp)

target_link_libraries(SRCManager PRIVATE Qt6::Core)
target_link_libraries(SRCManager PRIVATE Qt6::Gui)
