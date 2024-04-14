find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(SequenceOfPackageModel STATIC SequenceOfPackageModel.cpp)

target_link_libraries(SequenceOfPackageModel PRIVATE Qt6::Core)
