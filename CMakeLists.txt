cmake_minimum_required(VERSION 3.25.0)

project(linalg_cpp)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)
# add_subdirectory(external)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} linalg)

# set_target_properties(linalg PROPERTIES PUBLIC_HEADER matrix.h)

# install(TARGETS linalg DESTINATION lib PUBLIC_HEADER DESTINATION include)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )

# enable_testing()

# add_executable(
#   hello_test
#   hello_test.cpp)
# target_link_libraries(
#   hello_test
#   GTest::gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(hello_test)
