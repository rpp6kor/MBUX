add_library(intent_recognition sources/intent_recognition.cpp)
target_include_directories(intent_recognition PUBLIC headers/)
target_compile_options(intent_recognition PUBLIC -Wall -Wextra -Wpedantic -Werror)

add_library(speech_services sources/speech_service.cpp)
target_link_libraries(speech_services intent_recognition)
target_include_directories(speech_services PUBLIC headers/)
target_compile_options(speech_services PUBLIC -Wall -Wextra -Wpedantic -Werror)
