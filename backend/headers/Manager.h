#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <map>
#include <memory>

#include "Group.h"
#include "Multimedia.h"
#include "Film.h"
#include "Video.h"
#include "Photo.h"

class Manager;

typedef std::shared_ptr<Group> GroupPtr;
typedef std::shared_ptr<Multimedia> MultimediaPtr;
typedef std::shared_ptr<Film> FilmPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Photo> PhotoPtr;

class Manager {
    std::map<std::string, MultimediaPtr> multimediaMap;
    std::map<std::string, GroupPtr> groupMap;

public:
    Manager();
    ~Manager();

    // Creates
    MultimediaPtr createPhoto(std::string objectName, std::string filePath, int latitude, int longitude);
    MultimediaPtr createVideo(std::string objectName, std::string filePath, int duration);
    MultimediaPtr createFilm(std::string objectName, std::string filePath, int duration, int chapters, const int * chaptersDuration);
    GroupPtr createGroup(std::string name);

    // Displays
    bool displayGroup(std::string name, std::ostream& os) const;
    bool displayMultimedia(std::string objectName, std::ostream& os) const;

    // adds
    bool addMediaToGroup(std::string mediaName, std::string groupName);

    // Plays
    bool playMultimedia(std::string objectName) const;

    // Deletes
    bool deleteMultimedia(std::string objectName);
    bool deleteGroup(std::string name);
};


#endif // MANAGER_H