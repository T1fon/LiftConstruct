find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)

add_library(StationModel STATIC StationModel.cpp)

target_link_libraries(StationModel PRIVATE Qt6::Core)
target_link_libraries(StationModel PRIVATE Qt6::SerialPort)
