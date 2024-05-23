find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(ProjectManager STATIC ProjectManager.cpp)

target_link_libraries(ProjectManager PRIVATE Qt6::Core)
target_link_libraries(ProjectManager PRIVATE Qt6::Gui)
