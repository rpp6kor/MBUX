cmake_minimum_required(VERSION 3.12.4)

project(MBITION)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PUBLIC weather_intent_lib)

add_subdirectory(weather_intent_lib)

target_link_libraries(${PROJECT_NAME} weather_intent)
