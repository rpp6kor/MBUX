#include "intent_recognition.h"
#include <gmock/gmock.h>

namespace intent_recognition {

class IntentRecognitionMock final : public IIntentRecognition {
public:
  IntentRecognitionMock() = default;
  IntentRecognitionMock(const IntentRecognitionMock &) = default;
  IntentRecognitionMock &operator=(const IntentRecognitionMock &) = default;
  IntentRecognitionMock(IntentRecognitionMock &&) = default;
  IntentRecognitionMock &operator=(IntentRecognitionMock &&) = default;
  virtual ~IntentRecognitionMock() = default;

  MOCK_METHOD(void, AddIntents,
              (const std::string &intent_varitions, const std::string &intent),
              (override));
  MOCK_METHOD(std::string, FindIntent, (const std::string &question),
              (override));
};

} // namespace intent_recognition
