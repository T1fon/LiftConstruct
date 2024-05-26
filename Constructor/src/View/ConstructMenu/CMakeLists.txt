find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(Qt6 6.2 COMPONENTS Core REQUIRED)

add_library(ConstructView
    STATIC
    ConstructView.cpp
)


target_link_libraries(ConstructView PRIVATE Qt6::Quick)
target_link_libraries(ConstructView PRIVATE Qt6::Core)
target_include_directories(ConstructView INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


target_link_directories(ConstructView PUBLIC ../../Controller)
target_link_libraries(ConstructView PUBLIC MainManager)
