find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(CRCModelTest CRCModelTest.cpp)
add_test(NAME CRCModelTest COMMAND CRCModelTest)

add_library(CRCModel STATIC ../../../../src/Model/CRCModel/crcmodel.hpp)
target_link_libraries(CRCModel PRIVATE Qt6::Core)

target_link_libraries(CRCModelTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(CRCModelTest PRIVATE Logger)
