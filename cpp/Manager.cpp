#include "Manager.h"

Manager::Manager()
{

}

std::shared_ptr<Photo> Manager::createPhoto(std::string name, std::string pathname)
{
    std::shared_ptr<Photo> photo_shPtr = std::make_shared<Photo>(name,pathname);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Photo> >(name,photo_shPtr));
    return photo_shPtr;
}

std::shared_ptr<Photo> Manager::createPhoto(std::string name, std::string pathname,float latitude, float longitude)
{
    std::shared_ptr<Photo> photo_shPtr = std::make_shared<Photo>(name,pathname,latitude,longitude);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Photo> >(name,photo_shPtr));
    return photo_shPtr;
}

std::shared_ptr<Video> Manager::createVideo(std::string name, std::string pathname)
{
    std::shared_ptr<Video> video_shPtr = std::make_shared<Video>(name, pathname);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Video> >(name,video_shPtr));
    return video_shPtr;
}

std::shared_ptr<Video> Manager::createVideo(std::string name, std::string pathname, int duration)
{
    std::shared_ptr<Video> video_shPtr = std::make_shared<Video>(name, pathname, duration);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Video> >(name,video_shPtr));
    return video_shPtr;
}

std::shared_ptr<Film> Manager::createFilm(std::string name, std::string pathname)
{
    std::shared_ptr<Film> film_shPtr = std::make_shared<Film>(name, pathname);
    multimediaMap.insert(std::pair< std::string, std::shared_ptr<Film> >(name,film_shPtr));
    return film_shPtr;
}

std::shared_ptr<Film> Manager::createFilm(std::string name, std::string pathname, int duration, int chaptersNumber, int* chaptersDurations)
{
    std::shared_ptr<Film> film_shPtr = std::make_shared<Film>(name, pathname, duration, chaptersNumber, chaptersDurations);
    multimediaMap.insert(std::pair< std::string, std::shared_ptr<Film> >(name,film_shPtr));
    return film_shPtr;
}

void Manager::describeMedia(std::string nameIndex, std::ostream& stream) const
{
    if ( this->multimediaMap.count(nameIndex) )
    {
        this->multimediaMap.at(nameIndex)->describe(stream);
    }
    else
    {
        stream << "ERROR: Requested media doesn't exist !" << std::endl;
    }
}

void Manager::playMedia(std::string nameIndex, std::ostream& stream) const
{
    if ( this->multimediaMap.count(nameIndex) )
    {
        stream << "Playing media : " << nameIndex << "." << std::endl;
        this->multimediaMap.at(nameIndex)->playMedia();
    }
    else
    {
        stream << "ERROR: Requested media (" << nameIndex << ") doesn't exist !" << std::endl;
    }
}

Groupe Manager::createGroup()
{
    std::shared_ptr<Groupe> grp_shPtr = std::make_shared<Groupe>();
    this->groupeMap.insert(std::pair< std::string, std::shared_ptr<Groupe> >(grp_shPtr->getGroupName(),grp_shPtr));
    return *(grp_shPtr.get());
}

Groupe Manager::createGroup(const std::string groupname)
{
    std::shared_ptr<Groupe> grp_shPtr = std::make_shared<Groupe>(groupname);
    this->groupeMap.insert(std::pair< std::string, std::shared_ptr<Groupe> >(groupname,grp_shPtr));
    return *(grp_shPtr.get());
}

Groupe Manager::createGroup(const std::string groupname,std::initializer_list<std::shared_ptr<Multimedia>> il)
{
    std::shared_ptr<Groupe> grp_shPtr = std::make_shared<Groupe>(groupname,il);
    this->groupeMap.insert(std::pair< std::string, std::shared_ptr<Groupe> >(groupname,grp_shPtr));
    return *(grp_shPtr.get());
}

void Manager::describeGroup(std::string nameIndex, std::ostream& stream) const
{
    if ( this->groupeMap.count(nameIndex) )
    {
        this->groupeMap.at(nameIndex)->describe(stream);
    }
    else
    {
        stream << "ERROR: Requested group (" << nameIndex << ") doesn't exist !" << std::endl;
    }
}

void Manager::listGroups(std::ostream& stream) const
{
    for(auto it = this->groupeMap.begin(); it != this->groupeMap.end(); ++it) {
        stream << it->first << ";";
    }
    stream << "\n";
}

void Manager::listMedia(std::ostream& stream) const
{
    for(auto it = this->multimediaMap.begin(); it != this->multimediaMap.end(); ++it) {
        stream << it->first << ";";
    }
    stream << "\n";
}















