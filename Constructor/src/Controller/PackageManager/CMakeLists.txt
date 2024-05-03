find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(PackageManager STATIC PackageManager.cpp)

target_link_libraries(PackageManager PRIVATE Qt6::Core)
