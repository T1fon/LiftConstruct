find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(SectionManagerTest SectionManagerTest.cpp)
add_test(NAME SectionManagerTest COMMAND SectionManagerTest)

add_library(SectionManager STATIC ../../../../src/Controller/SectionManager/SectionManager.cpp)
add_library(SectionModel STATIC ../../../../src/Model/SectionModel/sectionmodel.cpp)
target_link_libraries(SectionManager PRIVATE Qt6::Core)
target_link_libraries(SectionModel PRIVATE Qt6::Core)

target_link_libraries(SectionManagerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(SectionManagerTest PRIVATE SectionManager)

#target_link
