#include "Photo.h"

Photo::Photo():
    latitude(0), longitude(0)
{}

Photo::Photo(std::string name, std::string pathname,
             float latitude, float longitude):
    Multimedia(name, pathname), latitude(latitude),
    longitude(longitude)
{}

Photo::Photo(std::string name, std::string pathname):
    Multimedia(name, pathname), latitude(0),
    longitude(0)
{}

void Photo::setLatitude(float latitude)
{
    this->latitude = latitude;
}

void Photo::setLongitude(float longitude)
{
    this->longitude = longitude;
}

float Photo::getLatitude() const
{
    return this->latitude;
}

float Photo::getLongitude() const
{
    return this->longitude;
}

void Photo::describe(std::ostream& stream) const
{
    stream << "This multimedia file is a photo " << std::endl;
    Multimedia::describe(stream);
    stream << "The longitude of this photo is : "
           << longitude << std::endl;
    stream << "The latitude of this photo is : "
           << latitude << std::endl;
}

void Photo::playMedia() const
{
    std::string command = "mpv "+ Multimedia::pathname + " &";//imagej or gnome-open alternatively
    char* c_command = new char [command.length()+1];
    std::strcpy (c_command, command.c_str());
    std::cout << "Executing command: " << c_command << std::endl;
    std::system(c_command);
}
