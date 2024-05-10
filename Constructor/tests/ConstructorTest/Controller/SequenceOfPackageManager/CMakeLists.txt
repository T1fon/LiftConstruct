find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(SequenceOfPackageManagerTest SequenceOfPackageManagerTest.cpp)
add_test(NAME SequenceOfPackageManagerTest COMMAND SequenceOfPackageManagerTest)

add_library(SequenceOfPackageManager STATIC ../../../../src/Controller/SequenceOfPackageManager/sequenceofpackagemanager.cpp)
#add_library(SequenceOfPackageModel STATIC ../../../../src/Model/SequenceOfPackageModel/sequenceofpackagemodel.cpp)
target_link_libraries(SequenceOfPackageManager PRIVATE Qt6::Core)

target_link_libraries(SequenceOfPackageManagerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(SequenceOfPackageManagerTest PRIVATE SequenceOfPackageManager)
