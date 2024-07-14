#include "Video.h"

Video::Video():
    duration(0)
{}

Video::Video(std::string name, std::string pathname,
             int duration):
    Multimedia(name, pathname), duration(duration)
{}

Video::Video(std::string name, std::string pathname):
    Multimedia(name, pathname), duration(0)
{}

void Video::setDuration(int duration)
{
    this->duration = duration;
}

int Video::getDuration() const
{
    return this->duration;
}

void Video::describe(std::ostream& stream) const
{
    stream << "This multimedia file is a video " << std::endl;
    Multimedia::describe(stream);
    stream << "The duration of this video file is : "
           << duration << std::endl;
}

void Video::playMedia() const
{
    std::string command = "mpv "+ Multimedia::pathname + " &" ;
    char* command_mpv = new char [command.length()+1];
    std::strcpy (command_mpv, command.c_str());
    std::cout << "Executing command: " << command_mpv << std::endl;
    std::system(command_mpv);
}
