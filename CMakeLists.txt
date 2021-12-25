cmake_minimum_required(VERSION 3.12.4)

project(MBITION)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)
target_link_directories(${PROJECT_NAME} PUBLIC weather_intent_lib)
add_subdirectory(weather_intent_lib)
target_link_libraries(${PROJECT_NAME} weather_intent)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  weather_intent_test
  tests/test_weather_intent.cpp
)

include_directories(weather_intent_lib)

target_link_libraries(
  weather_intent_test
  gtest_main
  weather_intent
)

include(GoogleTest)
gtest_discover_tests(weather_intent_test)