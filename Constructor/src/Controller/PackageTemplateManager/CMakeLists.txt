find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(PackageTemplateManager STATIC PackageTemplateManager.cpp)

target_link_libraries(PackageTemplateManager PRIVATE Qt6::Core)
