find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(PackageTemplateManager STATIC PackageTemplateManager.cpp)

target_link_libraries(PackageTemplateManager PRIVATE Qt6::Core)

target_link_directories(PackageTemplateManager PUBLIC ../../Model)
target_link_directories(PackageTemplateManager PUBLIC ../)

target_link_libraries(PackageTemplateManager PUBLIC PackageTemplateModel)
target_link_libraries(PackageTemplateManager PUBLIC SectionManager)
