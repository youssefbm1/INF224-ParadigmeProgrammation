//
//  main.cpp
//  

#include <iostream>
#include "Multimedia.h"
#include "Manager.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Groupe.h"
#include <vector>
#include <map>
#include <memory>

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
using namespace std;
using namespace cppu;

const int PORT = 3331;

#define so std::cout

void replaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace);

class MyBase : public Manager{
public:

    bool processRequest(TCPConnection& cnx, const string& request, string& response)
    {
        cerr << "\nRequest: '" << request << "'" << endl;

        // 1) pour decouper la requête:
        size_t f = request.find(" ");
        string instruct = request.substr(0,f);

        // 2) faire le traitement:
        if ( request.compare("lgroup") == 0)
        {
            std::ostringstream osstr;
            listGroups(osstr);

            string result = osstr.str();
            replaceStringInPlace(result,"\n",";");
            replaceStringInPlace(result,"\r",";");
            response = result;
        }
        else if ( request.compare("lmedia") == 0)
        {
            std::ostringstream osstr;
            listMedia(osstr);

            string result = osstr.str();
            replaceStringInPlace(result,"\n",";");
            replaceStringInPlace(result,"\r",";");
            response = result;
        }
        else if ( instruct.compare("dgroup") == 0)
        {
            string groupName = request.substr(f+1);

            std::ostringstream osstr;
            describeGroup(groupName,osstr);

            string result = osstr.str();
            replaceStringInPlace(result,"\n",";");
            replaceStringInPlace(result,"\r",";");
            response = result;
        }
        else if ( instruct.compare("dmedia") == 0 )
        {
            string mediaName = request.substr(f+1);

            std::ostringstream osstr;
            describeMedia(mediaName,osstr);

            string result = osstr.str();
            replaceStringInPlace(result,"\n",";");
            replaceStringInPlace(result,"\r",";");
            response = result;
        }
        else if ( instruct.compare("play") == 0 )
        {
            string mediaName = request.substr(f+1);
            std::ostringstream osstr;
            playMedia(mediaName,osstr);

            string result = osstr.str();
            replaceStringInPlace(result,"\n",";");
            replaceStringInPlace(result,"\r",";");
            response = result;
        }
        else
        {
            string result = "Error request";
            response = result;

        }

        // 3) retourner la reponse au client:


        cerr << "response: " << response << endl;

        // renvoyer false si on veut clore la connexion avec le client
        return true;
    }
};

int main(int argc, char* argv[]) {

    //___________________________________________________________________ Hello
    std::cout << "\n_____________________ INF224 __________________________\n" << std::endl;

    //___________________________________________________________________ ETAPE 8 ___
    std::cout << "_____________________ QUESTION 10 : ____________________" << std::endl;
    // cree l'objet qui gère les données
    shared_ptr<MyBase> manager(new MyBase());

    //Manager manager = Manager();

    int dur [] = { 10, 20, 30 };
    std::shared_ptr<Film> film = manager->createFilm("myFilm","./media/video.mp4",1256,3,dur);
    film->describe(so);
    std::shared_ptr<Photo> photo = manager->createPhoto("myImage","./media/walle.jpeg",5,15);
    photo->describe(so);
    std::shared_ptr<Video> video = manager->createVideo("myVideo","./media/video.mp4", 548);
    // if we're adding remove we need to care for shared paths
    manager->describeMedia("MyVideo",so);
    Groupe grp = manager->createGroup("MyGroup",{film,video});
    manager->describeGroup("MyGroup",so);

    // Constructors set to Private, we can no longer access them from outside
    //    Video* illegalVideo = new Video("unlistedVideo","PathToUnlistedVideo");
    //    illegalVideo->describe();
    //    manager.describeMedia("unlistedVideo",so);

    so << "____ Listing Groups ____";
    manager->listGroups(so);
    so << "____ Listing Media ____";
    manager->listMedia(so);

    std::cout << "\n_____________________ LAUNCHING SERVER __________________________" << std::endl;

    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());



    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*manager, &MyBase::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return 1;
    }

    return 0;


}


// utils
void replaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}
