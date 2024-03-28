cmake_minimum_required(VERSION 3.5)

project(ConstructorTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Model)

#add_executable(LoggerTest tst_loggertest.cpp)
#add_test(NAME LoggerTest COMMAND LoggerTest)

#target_link_libraries(LoggerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)

