add_library(intent_recognition_test test_weather_intent.cpp)
target_include_directories(intent_recognition PUBLIC headers/)
target_compile_options(intent_recognition_test PUBLIC -Wall -Wextra -Wpedantic -Werror)

add_library(speech_service_test test_speech_service.cpp mock_intent_recogition.h)
target_include_directories(speech_services PUBLIC headers/)
target_compile_options(speech_service_test PUBLIC -Wall -Wextra -Wpedantic -Werror)
