#include "intent_recognition.h"
#include <gtest/gtest.h>
#include <memory>
#include <string>

namespace intent_recognition {

class IntentRecognitionFixture : public testing::Test {
public:
  void SetUp() override {
    intent_recogniser_ = std::make_unique<IntentRecognition>();
  }

  void TearDown() override {}

protected:
  std::unique_ptr<IIntentRecognition> intent_recogniser_;
};

TEST_F(IntentRecognitionFixture,
       TestIntentRecognition_WrongQuestionAsked_OutputsWrongIntent) {
  const std::string intent{"Try something else ..."};
  std::string question = "sdsd";
  std::string output = intent_recogniser_->FindIntent(question);

  EXPECT_TRUE(intent.compare(output) == 0);
}

TEST_F(IntentRecognitionFixture,
       TestIntentRecognition_WeatherIntent_OutputsWeatherIntent) {
  const std::string intent{"Intent: Get Weather"};
  std::string question = "What is the weather like today?";
  intent_recogniser_->AddIntents(question.c_str(), intent.c_str());
  std::string output = intent_recogniser_->FindIntent(question);

  EXPECT_TRUE(intent.compare(output) == 0);
}

TEST_F(IntentRecognitionFixture,
       TestIntentRecognition_CityWeatherIntent_OutputsCityWeatherIntent) {
  const std::string intent{"Intent: Get Weather City"};
  std::string question = "What is the weather like in Paris today?";
  intent_recogniser_->AddIntents(question.c_str(), intent.c_str());
  std::string output = intent_recogniser_->FindIntent(question);

  EXPECT_TRUE(intent.compare(output) == 0);
}

TEST_F(
    IntentRecognitionFixture,
    TestIntentRecognition_InterestingFactsIntent_OutputsInterestingFactsIntent) {
  const std::string intent{"Intent: Get Fact"};
  std::string question = "Tell me an interesting fact";
  intent_recogniser_->AddIntents(question.c_str(), intent.c_str());
  std::string output = intent_recogniser_->FindIntent(question);

  EXPECT_TRUE(intent.compare(output) == 0);
}

} // namespace intent_recognition
