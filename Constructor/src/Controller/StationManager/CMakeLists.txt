find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)

add_library(StationManager STATIC StationManager.cpp)

target_link_libraries(StationManager PRIVATE Qt6::Core)
target_link_libraries(StationManager PRIVATE Qt6::SerialPort)

target_link_directories(StationManager PUBLIC ../../Model)

target_link_libraries(StationManager PUBLIC StationModel)
