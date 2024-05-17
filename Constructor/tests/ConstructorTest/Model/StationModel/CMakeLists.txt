find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)

add_executable(StationModelTest StationModelTest.cpp)
add_test(NAME StationModelTest COMMAND StationModelTest)

add_library(StationModel STATIC ../../../../src/Model/StationModel/stationmodel.cpp)
add_library(PackageTemplateManager STATIC ../../../../src/Controller/PackageTemplateManager/packagetemplatemanager.cpp)
add_library(PackageTemplateModel STATIC ../../../../src/Model/PackageTemplateModel/packagetemplatemodel.cpp)
add_library(SectionManager STATIC ../../../../src/Controller/SectionManager/sectionmanager.cpp)
add_library(SectionModel STATIC ../../../../src/Model/SectionModel/sectionmodel.cpp)
add_library(CRCModel STATIC ../../../../src/Model/CRCModel/crcmodel.cpp)
add_library (VirtualPortModel STATIC ../../../../src/Model/VirtualPortModel/virtualportmodel.cpp)


target_link_libraries(StationModel PRIVATE Qt6::Core)
target_link_libraries(PackageTemplateManager PRIVATE Qt6::Core)
target_link_libraries(PackageTemplateModel PRIVATE Qt6::Core)
target_link_libraries(SectionManager PRIVATE Qt6::Core)
target_link_libraries(SectionModel PRIVATE Qt6::Core)
target_link_libraries(CRCModel PRIVATE Qt6::Core)
target_link_libraries(VirtualPortModel PRIVATE Qt6::Core)
target_link_libraries(VirtualPortModel PRIVATE Qt6::SerialPort)


target_link_libraries(StationModelTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(StationModelTest PRIVATE StationModel)
target_link_libraries(StationModelTest PRIVATE PackageTemplateManager)
target_link_libraries(StationModelTest PRIVATE PackageTemplateModel)
target_link_libraries(StationModelTest PRIVATE SectionManager)
target_link_libraries(StationModelTest PRIVATE SectionModel)
target_link_libraries(StationModelTest PRIVATE VirtualPortModel)
target_link_libraries(StationModelTest PRIVATE CRCModel)
target_link_libraries(StationModelTest PRIVATE Qt6::Core)

