#include "intent_recognition.h"
#include <iostream>

namespace intent_recognition {

void IntentRecognition::AddIntents(const std::string &intent_varitions,
                                   const std::string &intent) {
  intent_variations.emplace(std::make_pair(intent_varitions, intent));
}

std::string IntentRecognition::FindIntent(const std::string &question) {
  std::string intent{};
  intent = intent_variations[question.c_str()];

  if (intent.empty()) {
    intent = "Try something else ...";
  }

  return intent;
}

} // namespace intent_recognition
