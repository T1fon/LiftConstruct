find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(TestManagerTest TestManagerTest.cpp)
add_test(NAME TestManagerTest COMMAND TestManagerTest)

add_library(TestModel STATIC ../../../../src/Model/TestModel/TestModel.cpp)
add_library(SequenceOfPackageManager STATIC ../../../../src/Controller/SequenceOfPackageManager/sequenceofpackagemanager.cpp)
add_library(SequenceOfPackageModel STATIC ../../../../src/Model/SequenceOfPackageModel/sequenceofpackagemodel.cpp)
add_library(TestManager STATIC ../../../../src/Controller/TestManager/testmanager.cpp)
target_link_libraries(SequenceOfPackageManager PRIVATE Qt6::Core)
target_link_libraries(SequenceOfPackageModel PRIVATE Qt6::Core)
target_link_libraries(TestModel PRIVATE Qt6::Core)
target_link_libraries(TestManager PRIVATE Qt6::Core)

target_link_libraries(TestManagerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(TestManagerTest PRIVATE TestModel)
target_link_libraries(TestManagerTest PRIVATE TestManager)
target_link_libraries(TestManagerTest PRIVATE SequenceOfPackageManager)
target_link_libraries(TestManagerTest PRIVATE SequenceOfPackageModel)
target_link_libraries(TestManagerTest PRIVATE Qt6::Core)

