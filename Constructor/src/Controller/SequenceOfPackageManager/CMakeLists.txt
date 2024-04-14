find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(SequenceOfPackageManager STATIC SequenceOfPackageManager.cpp)

target_link_libraries(SequenceOfPackageManager PRIVATE Qt6::Core)
