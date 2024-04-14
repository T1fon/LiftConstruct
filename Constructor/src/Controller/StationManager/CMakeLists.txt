find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(StationManager STATIC StationManager.cpp)

target_link_libraries(StationManager PRIVATE Qt6::Core)
