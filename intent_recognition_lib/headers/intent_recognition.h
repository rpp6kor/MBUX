#ifndef INTENT_RECOGNITION_LIB_HEADERS_INTENT_RECOGNITION_
#define INTENT_RECOGNITION_LIB_HEADERS_INTENT_RECOGNITION_

#include "iintent_recognition.h"
#include <map>

namespace intent_recognition {

class IntentRecognition final : public IIntentRecognition {
public:
  IntentRecognition() = default;
  IntentRecognition(const IntentRecognition &) = default;
  IntentRecognition &operator=(const IntentRecognition &) = default;
  IntentRecognition(IntentRecognition &&) = default;
  IntentRecognition &operator=(IntentRecognition &&) = default;
  ~IntentRecognition() = default;

  void AddIntents(const std::string &intent_varitions,
                  const std::string &intent) override;
  std::string FindIntent(const std::string &question) override;

private:
  std::map<std::string, std::string> intent_variations{};
};

} // namespace intent_recognition

#endif
