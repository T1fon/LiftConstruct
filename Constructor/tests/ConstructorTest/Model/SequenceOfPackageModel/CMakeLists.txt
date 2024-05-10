find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(SequenceOfPackageModelTest SequenceOfPackageModelTest.cpp)
add_test(NAME SequenceOfPackageModelTest COMMAND SequenceOfPackageModelTest)

add_library(SequenceOfPackageModel STATIC ../../../../src/Model/SequenceOfPackageModel/SequenceOfPackageModel.cpp)
target_link_libraries(SequenceOfPackageModel PRIVATE Qt6::Core)

target_link_libraries(SequenceOfPackageModelTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(SequenceOfPackageModelTest PRIVATE SequenceOfPackageModel)
