#ifndef GROUPE_H
#define GROUPE_H

#include "Multimedia.h"
#include <list>
#include <string>
#include <memory>


class Groupe : public std::list<std::shared_ptr<Multimedia>>
{

private:
    std::string groupname;


public:
    Groupe();
    Groupe(const std::string groupname);
    //Groupe(const std::string groupname, Multimedia** media, const int n); // NOT A GOOD IDEA
    Groupe(const std::string groupname,std::initializer_list<std::shared_ptr<Multimedia>> il);
    //    Groupe(const std::string groupname,std::initializer_list<Multimedia*> il);

    std::string getGroupName() const;
    void describe(std::ostream& stream = std::cout) const;

    virtual ~Groupe();
};

#endif // GROUPE_H
