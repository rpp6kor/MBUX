#ifndef INTENT_RECOGNITION_LIB_HEADERS_SPEECH_SERVICE_
#define INTENT_RECOGNITION_LIB_HEADERS_SPEECH_SERVICE_

#include "intent_recognition.h"
#include <atomic>
#include <iostream>
#include <memory>

namespace intent_recognition {

class SpeechService final {
public:
  SpeechService(const std::atomic_bool &exit_requested,
                std::unique_ptr<IIntentRecognition> intent_recogniser =
                    std::make_unique<IntentRecognition>());
  SpeechService(const SpeechService &) = default;
  SpeechService &operator=(const SpeechService &) = default;
  SpeechService(SpeechService &&) = default;
  SpeechService &operator=(SpeechService &&) = default;
  ~SpeechService() = default;

  void GetIntent(std::istream &stream = std::cin) const;

private:
  const std::atomic_bool &exit_requested_;
  std::unique_ptr<IIntentRecognition> intent_recogniser_{nullptr};
};

} // namespace intent_recognition

#endif
