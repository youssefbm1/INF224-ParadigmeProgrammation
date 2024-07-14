#ifndef MANAGER_H
#define MANAGER_H

#include "Multimedia.h"
#include "Groupe.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include <string>
#include <memory>
#include <map>

class Manager
{

private:
    std::map<std::string,std::shared_ptr<Multimedia>> multimediaMap;
    std::map<std::string,std::shared_ptr<Groupe>> groupeMap;

public:
    Manager();

    std::shared_ptr<Photo> createPhoto(std::string name, std::string pathname);
    std::shared_ptr<Photo> createPhoto(std::string name, std::string pathname, float latitude, float longitude);


    std::shared_ptr<Video> createVideo(std::string name, std::string pathname);
    std::shared_ptr<Video> createVideo(std::string name, std::string pathname, int duration);

    std::shared_ptr<Film> createFilm(std::string name, std::string pathname);
    std::shared_ptr<Film> createFilm(std::string name, std::string pathname, int duration, int chaptersNumber, int* chaptersDurations);

    void describeMedia(std::string, std::ostream& stream = std::cout) const;
    void playMedia(std::string, std::ostream& stream = std::cout) const;

    Groupe createGroup();
    Groupe createGroup(const std::string groupname);
    Groupe createGroup(const std::string groupname,std::initializer_list<std::shared_ptr<Multimedia>> il);
    void describeGroup(std::string, std::ostream& stream = std::cout) const;

    void listGroups(std::ostream& stream = std::cout) const;
    void listMedia(std::ostream& stream = std::cout) const;
};

#endif // MANAGER_H
