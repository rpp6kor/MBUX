#ifndef IWHETHER_FACTS_
#define IWHETHER_FACTS_

#include <string>

namespace weather_recognition
{

class IWeatherRecognition
{
    public:
        IWeatherRecognition() = default;
        IWeatherRecognition(const IWeatherRecognition&) = default;
        IWeatherRecognition(IWeatherRecognition&&) = default;
        virtual ~IWeatherRecognition() = default;

        virtual std::string GetWeatherRecognisedIntent(const std::string& question) = 0;
};

}

#endif