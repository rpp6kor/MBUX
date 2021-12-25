#include <iostream>
#include <memory>
#include "weather_facts.h"


int main()
{
    std::string question;
    std::cout << "Enter question" << std::endl;
    std::getline(std::cin, question);

    std::unique_ptr<weather_recognition::IWeatherRecognition> whether_recogniser = std::make_unique<weather_recognition::WeatherRecognition>();
    std::cout << whether_recogniser->GetWeatherRecognisedIntent(question) << std::endl;

    return 0;
}