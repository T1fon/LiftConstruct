find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(SequenceOfPackageManager STATIC SequenceOfPackageManager.cpp)

target_link_libraries(SequenceOfPackageManager PRIVATE Qt6::Core)

target_link_directories(SequenceOfPackageManager PUBLIC ../../Model)

target_link_libraries(SequenceOfPackageManager PUBLIC SequenceOfPackageModel)
