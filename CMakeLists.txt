cmake_minimum_required(VERSION 3.5)

################################
# E164 normalising utility
################################
project(normalise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(normalise normalise.cpp
    utils.h utils.cpp)

include(GNUInstallDirs)
install(TARGETS normalise
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

################################
# Unit Tests
################################
enable_testing()
find_package(GTest REQUIRED)
add_executable(normalise_unittest normalise_unittest.cpp utils.h utils.cpp)
target_link_libraries(normalise_unittest GTest::gtest GTest::gtest_main)

add_test(normalise_unittest normalise_unittest)