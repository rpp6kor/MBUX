#ifndef WHETHER_FACTS_
#define WHETHER_FACTS_

#include "iweather_facts.h"

namespace weather_recognition
{

class WeatherRecognition final: public IWeatherRecognition
{
    public:
        WeatherRecognition() = default;
        WeatherRecognition(const WeatherRecognition&) = default;
        //WeatherRecognition operator=(const WeatherRecognition&) = default;
        WeatherRecognition(WeatherRecognition&&) = default;
        //WeatherRecognition operator=(const WeatherRecognition&&) = default;
        ~WeatherRecognition() = default;

        std::string GetWeatherRecognisedIntent(const std::string& question);
};

}

#endif

