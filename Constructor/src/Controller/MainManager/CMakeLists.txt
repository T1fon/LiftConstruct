find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)

add_library(MainManager STATIC MainManager.cpp)

target_link_libraries(MainManager PRIVATE Qt6::Core)
target_link_libraries(MainManager PRIVATE Qt6::Gui)
target_link_libraries(MainManager PRIVATE Qt6::SerialPort)
