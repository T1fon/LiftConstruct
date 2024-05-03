find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(SectionModelTest SectionModelTest.cpp)
add_test(NAME SectionModelTest COMMAND SectionModelTest)

add_library(SectionModel STATIC ../../../../src/Model/SectionModel/SectionModel.cpp)
target_link_libraries(SectionModel PRIVATE Qt6::Core)

target_link_libraries(SectionModelTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(SectionModelTest PRIVATE Logger)
