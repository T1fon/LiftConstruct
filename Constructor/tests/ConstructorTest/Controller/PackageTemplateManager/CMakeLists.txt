find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(PackageTemplateManagerTest PackageTemplateManagerTest.cpp)
add_test(NAME PackageTemplateManagerTest COMMAND PackageTemplateManagerTest)

add_library(PackageTemplateManager STATIC ../../../../src/Controller/PackageTemplateManager/packagetemplatemanager.cpp)
add_library(PackageTemplateModel STATIC ../../../../src/Model/PackageTemplateModel/packagetemplatemodel.cpp)
add_library(SectionManager STATIC ../../../../src/Controller/SectionManager/sectionmanager.cpp)
add_library(SectionModel STATIC ../../../../src/Model/SectionModel/sectionmodel.cpp)
target_link_libraries(PackageTemplateManager PRIVATE Qt6::Core)
target_link_libraries(PackageTemplateModel PRIVATE Qt6::Core)
target_link_libraries(SectionManager PRIVATE Qt6::Core)
target_link_libraries(SectionModel PRIVATE Qt6::Core)

target_link_libraries(PackageTemplateManagerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(PackageTemplateManagerTest PRIVATE PackageTemplateManager)
target_link_libraries(PackageTemplateManagerTest PRIVATE PackageTemplateModel)
target_link_libraries(PackageTemplateManagerTest PRIVATE SectionManager)
target_link_libraries(PackageTemplateManagerTest PRIVATE SectionModel)
target_link_libraries(PackageTemplateManagerTest PRIVATE Qt6::Core)

