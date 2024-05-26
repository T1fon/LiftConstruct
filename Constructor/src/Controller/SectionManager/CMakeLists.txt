find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(SectionManager STATIC SectionManager.cpp)

target_link_libraries(SectionManager PRIVATE Qt6::Core)

target_link_directories(SectionManager PUBLIC ../)

target_link_libraries(SectionManager PUBLIC SectionModel)
