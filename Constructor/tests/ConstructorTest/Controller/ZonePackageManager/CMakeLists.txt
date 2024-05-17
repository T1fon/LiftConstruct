find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_executable(ZonePackageManagerTest ZonePackageManagerTest.cpp)
add_test(NAME ZonePackageManagerTest COMMAND ZonePackageManagerTest)

add_library(ZonePackageManager STATIC ../../../../src/Controller/ZonePackageManager/ZonePackageManager.cpp)
add_library(ZonePackageModel; STATIC ../../../../src/Model/ZonePackageModel/ZonePackageModel.cpp)
target_link_libraries(ZonePackageManager PRIVATE Qt6::Core)
target_link_libraries(ZonePackageManager PRIVATE Qt6::Gui)
target_link_libraries(ZonePackageModel PRIVATE Qt6::Core)
target_link_libraries(ZonePackageModel PRIVATE Qt6::Gui)

target_link_libraries(ZonePackageManagerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(ZonePackageManagerTest PRIVATE ZonePackageModel)
target_link_libraries(ZonePackageManagerTest PRIVATE ZonePackageManager)
target_link_libraries(ZonePackageManagerTest PRIVATE Qt6::Gui)
target_link_libraries(ZonePackageManagerTest PRIVATE Qt6::Core)

