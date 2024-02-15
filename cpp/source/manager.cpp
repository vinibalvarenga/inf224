#include "Manager.h"

// Creates

Manager::Manager() {
}

MultimediaPtr Manager::createPhoto(std::string objectName, std::string filePath, int latitude, int longitude){
    MultimediaPtr photo = std::make_shared<Photo>(objectName, filePath, latitude, longitude);
    multimediaMap[objectName] = photo;
    return photo;
}

MultimediaPtr Manager::createVideo(std::string objectName, std::string filePath, int duration){
    MultimediaPtr video = std::make_shared<Video>(objectName, filePath, duration);
    multimediaMap[objectName] = video;
    return video;
}

MultimediaPtr Manager::createFilm(std::string objectName, std::string filePath, int duration, int chapters, const int * chaptersDuration){
    MultimediaPtr film = std::make_shared<Film>(objectName, filePath, duration, chapters, chaptersDuration);
    multimediaMap[objectName] = film;
    return film;
}

GroupPtr Manager::createGroup(std::string name){
    GroupPtr group = std::make_shared<Group>(name);
    groupMap[name] = group;
    return group;
}

// add media to a group
bool Manager::addMediaToGroup(std::string mediaName, std::string groupName){
    auto itMedia = multimediaMap.find(mediaName);
    auto itGroup = groupMap.find(groupName);
    if(itMedia != multimediaMap.end() && itGroup != groupMap.end()){
        itGroup->second->push_back(itMedia->second);
        return true;
    } else {
        return false;
    }
}

// Displays

bool Manager::displayMultimedia(std::string objectName, std::ostream& os) const{
    auto it = multimediaMap.find(objectName);
    if(it != multimediaMap.end()){
        it->second->display(os);
        return true;
    } else {
        std::cerr << "Multimedia object not found" << std::endl;
        return false;
    }
}

bool Manager::displayGroup(std::string name, std::ostream& os) const{
    auto it = groupMap.find(name);
    if(it != groupMap.end()){
        it->second->display(os);
        return true;
    } else {
        std::cerr << "Group not found" << std::endl;
        return false;
    }
}

// Plays

bool Manager::playMultimedia(std::string objectName) const{
    auto it = multimediaMap.find(objectName);
    if(it != multimediaMap.end()){
        it->second->play();
        return true;
    } else {
        std::cerr << "Multimedia object not found" << std::endl;
        return false;
    }
}

// Deletes

bool Manager::deleteMultimedia(std::string objectName){
    auto it = multimediaMap.find(objectName);
    if(it != multimediaMap.end()){
        multimediaMap.erase(it);
        return true;
    } else {
        std::cerr << "Multimedia object not found" << std::endl;
        return false;
    }
}

bool Manager::deleteGroup(std::string name){
    auto it = groupMap.find(name);
    if(it != groupMap.end()){
        groupMap.erase(it);
        return true;
    } else {
        std::cerr << "Group not found" << std::endl;
        return false;
    }
}




