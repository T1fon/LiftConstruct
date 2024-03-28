find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(LoggerTest LoggerTest.cpp)
add_test(NAME LoggerTest COMMAND LoggerTest)

add_library(Logger STATIC ../../../../src/Model/Logger/Logger.cpp)
target_link_libraries(Logger PRIVATE Qt6::Core)

target_link_libraries(LoggerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(LoggerTest PRIVATE Logger)
