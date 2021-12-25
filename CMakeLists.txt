cmake_minimum_required(VERSION 3.12.4)

project(MBITION)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_directories(${PROJECT_NAME} PUBLIC intent_recognition_lib)
add_subdirectory(intent_recognition_lib)

target_link_libraries(${PROJECT_NAME} speech_services Threads::Threads)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  intent_recognition_test
  tests/test_intent_recognition.cpp
)

add_executable(
  speech_service_test
  tests/test_speech_service.cpp
)

include_directories(intent_recognition_lib)

target_link_libraries(
  intent_recognition_test
  gtest_main
  intent_recognition
)

target_link_libraries(
  speech_service_test
  gtest_main
  gmock_main
  speech_services
)

include(GoogleTest)
gtest_discover_tests(intent_recognition_test)

