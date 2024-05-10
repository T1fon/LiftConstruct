find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(PackageTemplateModelTest PackageTemplateModelTest.cpp)
add_test(NAME PackageTemplateModelTest COMMAND PackageTemplateModelTest)

add_library(PackageTemplateModel STATIC ../../../../src/Model/PackageTemplateModel/PackageTemplateModel.cpp)
target_link_libraries(PackageTemplateModel PRIVATE Qt6::Core)

target_link_libraries(PackageTemplateModelTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(PackageTemplateModelTest PRIVATE PackageTemplateModel)
