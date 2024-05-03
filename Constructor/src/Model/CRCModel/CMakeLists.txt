find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

add_library(CRCModel STATIC CRCModel.cpp)

target_link_libraries(CRCModel PRIVATE Qt6::Core)
