find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(PackageModelTest PackageModelTest.cpp)
add_test(NAME PackageModelTest COMMAND PackageModelTest)

add_library(PackageModel STATIC ../../../../src/Model/PackageModel/PackageModel.cpp)
target_link_libraries(PackageModel PRIVATE Qt6::Core)

target_link_libraries(PackageModelTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(PackageModelTest PRIVATE PackageModel)
