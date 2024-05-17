find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_executable(ZonePackageModelTest ZonePackageModelTest.cpp)
add_test(NAME ZonePackageModelTest COMMAND ZonePackageModelTest)

add_library(ZonePackageModel STATIC ../../../../src/Model/ZonePackageModel/ZonePackageModel.cpp)
target_link_libraries(ZonePackageModel PRIVATE Qt6::Core)
target_link_libraries(ZonePackageModel PRIVATE Qt6::Gui)
target_link_libraries(ZonePackageModelTest PRIVATE Qt6::Gui)

target_link_libraries(ZonePackageModelTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(ZonePackageModelTest PRIVATE ZonePackageModel)
