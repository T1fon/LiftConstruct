find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)

add_executable(VirtualPortModelTest VirtualPortModelTest.cpp)
add_test(NAME VirtualPortModelTest COMMAND VirtualPortModelTest)

add_library(VirtualPortModel STATIC ../../../../src/Model/VirtualPortModel/virtualportmodel.cpp)
target_link_libraries(VirtualPortModel PRIVATE Qt6::Core)
target_link_libraries(VirtualPortModel PRIVATE Qt6::SerialPort)

target_link_libraries(VirtualPortModelTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(VirtualPortModelTest PRIVATE VirtualPortModel)
