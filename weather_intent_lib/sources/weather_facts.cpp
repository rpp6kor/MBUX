#include "weather_facts.h"

namespace weather_recognition
{

std::string WeatherRecognition::GetWeatherRecognisedIntent(const std::string& question)
{
    std::string answer{};
    if(question.compare("What is the weather like today?") == 0)
    {
        answer = "Intent:Get Weather";
    }else if(question.compare("What is the weather like in Paris today?") == 0){
        answer = "Intent: Get Weather City";
    }else if(question.compare("Tell me an interesting fact") == 0){
        answer = "Intent: Get Fact";
    }else{
        answer = "Better luck next time";
    }

    return answer;
}

}