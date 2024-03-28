add_library(Logger STATIC Logger.cpp)

find_package(Qt6 REQUIRED COMPONENTS Core)
target_link_libraries(Logger PRIVATE Qt6::Core)
