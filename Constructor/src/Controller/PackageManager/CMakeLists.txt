find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(PackageManager STATIC PackageManager.cpp)

target_link_libraries(PackageManager PRIVATE Qt6::Core)

target_link_directories(PackageManager PUBLIC ../../Model)

target_link_libraries(PackageManager PUBLIC PackageModel)
