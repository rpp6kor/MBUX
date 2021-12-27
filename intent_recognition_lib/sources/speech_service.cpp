#include "speech_service.h"
#include <string>

namespace intent_recognition {

SpeechService::SpeechService(
    const std::atomic_bool &exit_requested,
    std::unique_ptr<IIntentRecognition> intent_recogniser)
    : exit_requested_{exit_requested}, intent_recogniser_{
                                           std::move(intent_recogniser)} {
  // Register different variations for todays weather
  intent_recogniser_->AddIntents("What is the weather like today?",
                                 "Intent: Get Weather");
  intent_recogniser_->AddIntents(
      "What will be the weather like today whole day?", "Intent: Get Weather");
  intent_recogniser_->AddIntents("Weather today?", "Intent: Get Weather");
  intent_recogniser_->AddIntents("Todays weather?", "Intent: Get Weather");
  intent_recogniser_->AddIntents("How is the weather going to be today?",
                                 "Intent: Get Weather");
  intent_recogniser_->AddIntents("What do you think about todays weather?",
                                 "Intent: Get Weather");

  // Register different variations for cities weather
  intent_recogniser_->AddIntents("What is the weather like in Paris today?",
                                 "Intent: Get Weather City");
  intent_recogniser_->AddIntents("What is the weather like in Delhi today?",
                                 "Intent: Get Weather City");
  intent_recogniser_->AddIntents("What is the weather like in Frankfurt today?",
                                 "Intent: Get Weather City");
  intent_recogniser_->AddIntents("What is the weather like in Tokyo today?",
                                 "Intent: Get Weather City");
  intent_recogniser_->AddIntents(
      "What is the weather like in Washington today?",
      "Intent: Get Weather City");
  intent_recogniser_->AddIntents("What is the weather like in Berlin today?",
                                 "Intent: Get Weather City");

  // Register different varitions for interesting facts
  intent_recogniser_->AddIntents("Tell me an interesting fact",
                                 "Intent: Get Fact");
  intent_recogniser_->AddIntents("Tell me a fact", "Intent: Get Fact");
  intent_recogniser_->AddIntents("Interesting fact please?",
                                 "Intent: Get Fact");
  intent_recogniser_->AddIntents("Tell me yesterdays interesting fact",
                                 "Intent: Get Fact");
  intent_recogniser_->AddIntents("Do you have any interesting fact?",
                                 "Intent: Get Fact");
  intent_recogniser_->AddIntents("More intersting facts please",
                                 "Intent: Get Fact");
}

void SpeechService::GetIntent(std::istream &stream) const {
  std::string question{};
  std::cout << "Hello !!!!, how may i help you?" << std::endl;

  while (exit_requested_.load() != true) {
    std::getline(stream, question);
    std::cout << intent_recogniser_->FindIntent(question) << std::endl;
  }

  std::cout << "Time to close the speech services ...." << std::endl;
}

} // namespace intent_recognition
