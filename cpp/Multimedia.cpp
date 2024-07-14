#include "Multimedia.h"

Multimedia::Multimedia(): name(""), pathname(""){}

Multimedia::Multimedia(std::string name, std::string pathname):
    name(name), pathname(pathname) {}

Multimedia::~Multimedia()
{
    std::cout << "Multimedia object __ " << this->getName() << " __ was destroyed !" << std::endl;
}

void Multimedia::setName(std::string name)
{
    this->name = name;
}

void Multimedia::setPathname(std::string pathname)
{
    this->pathname = pathname;
}

std::string Multimedia::getName() const
{
    return name;
}

std::string Multimedia::getPathname() const
{
    return pathname;
}

void Multimedia::describe(std::ostream& stream) const
{
    stream << "The name of this multimedia file is : "
           << name << std::endl;
    stream << "The pathname of this multimedia file is : "
           << pathname << std::endl;
}

// pas d'implémentation pour Multimedia::playMedia







