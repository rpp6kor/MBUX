#ifndef INTENT_RECOGNITION_LIB_HEADERS_IINTENT_RECOGNITION_
#define INTENT_RECOGNITION_LIB_HEADERS_IINTENT_RECOGNITION_

#include <string>

namespace intent_recognition {

class IIntentRecognition {
public:
  IIntentRecognition() = default;
  IIntentRecognition(const IIntentRecognition &) = default;
  IIntentRecognition &operator=(const IIntentRecognition &) = default;
  IIntentRecognition(IIntentRecognition &&) = default;
  IIntentRecognition &operator=(IIntentRecognition &&) = default;
  virtual ~IIntentRecognition() = default;

  virtual void AddIntents(const std::string &intent_varitions,
                          const std::string &intent) = 0;
  virtual std::string FindIntent(const std::string &question) = 0;
};

} // namespace intent_recognition

#endif
