#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia
{

protected:
    int duration;

public:
    Video();
    Video(std::string name, std::string pathname, int duration);
    Video(std::string name, std::string pathname);

    void setDuration(int duration);
    int getDuration() const;

    virtual void describe(std::ostream& stream = std::cout) const override;
    void playMedia() const override;

};

#endif // VIDEO_H
