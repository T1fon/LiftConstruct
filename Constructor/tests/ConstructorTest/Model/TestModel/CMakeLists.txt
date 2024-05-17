find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(TestModelTest TestModelTest.cpp)
add_test(NAME TestModelTest COMMAND TestModelTest)

add_library(TestModel STATIC ../../../../src/Model/TestModel/TestModel.cpp)
add_library(SequenceOfPackageManager STATIC ../../../../src/Controller/SequenceOfPackageManager/sequenceofpackagemanager.cpp)
add_library(SequenceOfPackageModel STATIC ../../../../src/Model/SequenceOfPackageModel/sequenceofpackagemodel.cpp)
target_link_libraries(SequenceOfPackageManager PRIVATE Qt6::Core)
target_link_libraries(SequenceOfPackageModel PRIVATE Qt6::Core)
target_link_libraries(TestModel PRIVATE Qt6::Core)

target_link_libraries(TestModelTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(TestModelTest PRIVATE TestModel)
target_link_libraries(TestModelTest PRIVATE SequenceOfPackageManager)
target_link_libraries(TestModelTest PRIVATE SequenceOfPackageModel)
target_link_libraries(TestModelTest PRIVATE Qt6::Core)

