#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>
#include <cstring>

class Multimedia
{
protected:
    std::string name;
    std::string pathname;

public:
    Multimedia();
    Multimedia(std::string name, std::string pathname);

    virtual ~Multimedia();

    void setName(std::string name);
    void setPathname(std::string pathname);

    std::string getName() const;
    std::string getPathname() const;

    virtual void describe(std::ostream& stream = std::cout) const;

    virtual void playMedia() const = 0; //fonction abstraite ou virtuelle pure
};

#endif // MULTIMEDIA_H
