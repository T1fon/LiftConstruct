find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(PackageManagerTest PackageManagerTest.cpp)
add_test(NAME PackageManagerTest COMMAND PackageManagerTest)

add_library(PackageManager STATIC ../../../../src/Controller/PackageManager/PackageManager.cpp)
add_library(PackageModel STATIC ../../../../src/Model/PackageModel/PackageModel.cpp)
target_link_libraries(PackageManager PRIVATE Qt6::Core)
target_link_libraries(PackageModel PRIVATE Qt6::Core)

target_link_libraries(PackageManagerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(PackageManagerTest PRIVATE PackageManager)

target_link_libraries(PackageManagerTest PRIVATE PackageModel)
