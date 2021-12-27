#include "mock_intent_recognition.h"
#include "speech_service.h"
#include <fstream>
#include <gtest/gtest.h>
#include <memory>
#include <string>

namespace intent_recognition {

using ::testing::AtLeast;

TEST(TestSpeechService, TestAdditionOfIntents) {
  std::unique_ptr<IntentRecognitionMock> intent_recogniser =
      std::make_unique<IntentRecognitionMock>();
  auto intent_recogniser_ptr = intent_recogniser.get();
  std::atomic_bool exit_requested{false};
  EXPECT_CALL(*intent_recogniser_ptr, AddIntents).Times(AtLeast(18));

  SpeechService speech_service{exit_requested, std::move(intent_recogniser)};
}

TEST(TestSpeechService, TestGetIntent) {
  std::unique_ptr<IntentRecognitionMock> intent_recogniser =
      std::make_unique<IntentRecognitionMock>();
  auto intent_recogniser_ptr = intent_recogniser.get();
  std::atomic_bool exit_requested{true};
  std::fstream fs;

  EXPECT_CALL(*intent_recogniser_ptr, AddIntents).Times(AtLeast(1));
  EXPECT_CALL(*intent_recogniser_ptr, FindIntent).Times(0);
  SpeechService speech_service{exit_requested, std::move(intent_recogniser)};
  speech_service.GetIntent(fs);
}

} // namespace intent_recognition
