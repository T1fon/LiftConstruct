find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

add_library(PackageZoneView
    STATIC
    PackageZoneView.cpp
)



target_link_libraries(PackageZoneView PRIVATE Qt6::Quick)
target_include_directories(PackageZoneView INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


target_link_directories(PackageZoneView PUBLIC ../../Controller)
target_link_libraries(PackageZoneView PUBLIC MainManager)
