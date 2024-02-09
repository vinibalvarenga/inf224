#include "Manager.h"

// Creates

MultimediaPtr createPhoto(std::string objectName, std::string filePath, int latitude, int longitude){
    MultimediaPtr photo = std::make_shared<Photo>(objectName, filePath, latitude, longitude);
    multimediaMap[objectName] = photo;
    return photo;
}

MultimediaPtr createVideo(std::string objectName, std::string filePath, int duration){
    MultimediaPtr video = std::make_shared<Video>(objectName, filePath, duration);
    multimediaMap[objectName] = video;
    return video;
}

MultimediaPtr createFilm(std::string objectName, std::string filePath, int duration, int chapters, const int * chaptersDuration){
    MultimediaPtr film = std::make_shared<Film>(objectName, filePath, duration, chapters, chaptersDuration);
    multimediaMap[objectName] = film;
    return film;
}

GroupPtr createGroup(std::string name){
    GroupPtr group = std::make_shared<Group>(name);
    groupMap[name] = group;
    return group;
}

// Displays

void displayMultimedia(std::string objectName) const{
    auto it = multimediaMap.find(objectName);
    if(it != multimediaMap.end()){
        it->second->display(std::cout);
    } else {
        std::cerr << "Multimedia object not found" << std::endl;
    }
}

void displayGroup(std::string name) const{
    auto it = groupMap.find(name);
    if(it != groupMap.end()){
        it->second->display(std::cout);
    } else {
        std::cerr << "Group not found" << std::endl;
    }
}

// Plays

void playMultimedia(std::string objectName) const{
    auto it = multimediaMap.find(objectName);
    if(it != multimediaMap.end()){
        it->second->play();
    } else {
        std::cerr << "Multimedia object not found" << std::endl;
    }
}

// Deletes

void deleteMultimedia(std::string objectName){
    auto it = multimediaMap.find(objectName);
    if(it != multimediaMap.end()){
        multimediaMap.erase(it);
    } else {
        std::cerr << "Multimedia object not found" << std::endl;
    }
}

void deleteGroup(std::string name){
    auto it = groupMap.find(name);
    if(it != groupMap.end()){
        groupMap.erase(it);
    } else {
        std::cerr << "Group not found" << std::endl;
    }
}




