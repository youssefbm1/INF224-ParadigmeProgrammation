#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia
{
private:
    float latitude;
    float longitude;

public:
    Photo();
    Photo(std::string name, std::string pathname,
          float latitude, float longitude);
    Photo(std::string name, std::string pathname);

    void setLatitude(float latitude);
    void setLongitude(float longitude);

    float getLatitude() const;
    float getLongitude() const;

    void describe(std::ostream& stream = std::cout) const override;
    void playMedia() const override;

};

#endif // PHOTO_H
