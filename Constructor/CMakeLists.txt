cmake_minimum_required(VERSION 3.16)

project(Constructor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appConstructor
    src/main.cpp
)

qt_add_qml_module(appConstructor
    URI Constructor
    VERSION 1.0
    QML_FILES src/Main.qml
    RESOURCES
    QML_FILES src/View/ConstructMenu/ConstructMenu.qml
    QML_FILES src/View/PackageZoneMenu/PackageZoneMenu.qml
    QML_FILES src/View/StationMenu/StationMenu.qml
    QML_FILES src/View/PackageConstructMenu/PackageConstructMenu.qml
)

set_target_properties(appConstructor PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appConstructor
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appConstructor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
