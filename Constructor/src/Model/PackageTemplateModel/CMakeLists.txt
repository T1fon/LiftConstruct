find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(PackageTemplateModel STATIC PackageTemplateModel.cpp)

target_link_libraries(PackageTemplateModel PRIVATE Qt6::Core)
