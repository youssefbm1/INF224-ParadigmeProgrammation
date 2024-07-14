#include "Groupe.h"

Groupe::Groupe()
//implicit call to the constructor of list
{}

Groupe::Groupe(const std::string groupname):
    groupname(groupname)
{}

Groupe::Groupe(const std::string groupname, std::initializer_list<std::shared_ptr<Multimedia>> il):
    std::list<std::shared_ptr<Multimedia>>(il), groupname(groupname)
{}

//Groupe(const std::string groupname,std::initializer_list<Multimedia*> il):
//    std::list<std::shared_ptr<Multimedia>>(il), groupname(groupname)
//{
//     std::shared_ptr<Photo> image_shPtr(image);
//}

Groupe::~Groupe()
{
    std::cout << "Groupe object __ " << this->getGroupName() << " __ was destroyed !" << std::endl;
}

std::string Groupe::getGroupName() const
{
    return this->groupname;
}

void Groupe::describe(std::ostream& stream) const
{
    stream << "Multimedia group description : " << this->getGroupName() << std::endl;
    for (auto it : *this)
    {
        it->describe(stream);
    }
}
