find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(SectionModel STATIC SectionModel.cpp)

target_link_libraries(SectionModel PRIVATE Qt6::Core)
