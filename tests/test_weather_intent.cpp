#include <gtest/gtest.h>
#include "weather_facts.h"
#include <memory>
#include <string>

class WeatherIntentFixture : public testing::Test
{
    public:
        void SetUp() override
        {
            whether_recogniser_ = std::make_unique<weather_recognition::WeatherRecognition>();
        }

        void TearDown() override
        {}


    protected:
        std::unique_ptr<weather_recognition::IWeatherRecognition> whether_recogniser_;
};

TEST_F(WeatherIntentFixture, TestWeatherIntent_WrongQuestionAsked_OutputsWrongIntent)
{
const std::string str{"Better luck next time"};
std::string question = "sdsd";
std::string output = whether_recogniser_->GetWeatherRecognisedIntent(question);

EXPECT_TRUE(str.compare(output) == 0);
}

TEST_F(WeatherIntentFixture, TestWeatherIntent_TodaysWeatherAsked_OutputsTodaysWeatherIntent)
{
const std::string str{"Intent:Get Weather"};
std::string question = "What is the weather like today?";
std::string output = whether_recogniser_->GetWeatherRecognisedIntent(question);

std::cout << output << std::endl;

EXPECT_TRUE(str.compare(output) == 0);
}

TEST_F(WeatherIntentFixture, TestWeatherIntent_TodaysCityWeatherAsked_OutputsTodaysCityWeatherIntent)
{
const std::string str{"Intent: Get Weather City"};
std::string question = "What is the weather like in Paris today?";
std::string output = whether_recogniser_->GetWeatherRecognisedIntent(question);

std::cout << output << std::endl;

EXPECT_TRUE(str.compare(output) == 0);
}
