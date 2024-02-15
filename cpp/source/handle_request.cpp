#ifndef TRUC_VERSION
#define TRUC_VERSION

#include "handle_request.h"


#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Manager.h"



std::string handle_request(std::string request, Manager* manager)
{
  std::vector<std::string> requestVector; /* vector of words in the request */
  std::stringstream ss(request);
  std::string item;
  while (std::getline(ss, item, ' ')) {
    requestVector.push_back(item);
  }
  
  if (requestVector[0] == "create" && requestVector.size() > 1) {
    if (requestVector[1] == "photo" && requestVector.size() == 6) {
      std::string name = requestVector[2];
      std::string fileName = requestVector[3];
      int latitude = std::stoi(requestVector[4]);
      int longitude = std::stoi(requestVector[5]);
      if (manager->createPhoto(name, fileName, latitude, longitude)) {
        return "Photo created";
      }
      else {
        return "Error: Photo not created (might be missing parameters)";
      }
    }
    else if (requestVector[1] == "video" && requestVector.size() == 5) {
      std::string name = requestVector[2];
      std::string fileName = requestVector[3];
      int duration = std::stoi(requestVector[4]);
      if (manager->createVideo(name, fileName, duration)) {
        return "Video created";
      }
      else {
        return "Error: Video not created (might be missing parameters)";
      }
    }
    else if (requestVector[1] == "film" && requestVector.size() >= 5) {
      std::string name = requestVector[2];
      std::string filePath = requestVector[3];
      int duration = std::stoi(requestVector[4]);
      int chapters = std::stoi(requestVector[5]);
      int* chaptersDuration = new int[chapters];
      for (int i = 0; i < chapters; i++) {
        chaptersDuration[i] = std::stoi(requestVector[i + 6]);
       }
      if (manager->createFilm(name, filePath, duration, chapters, chaptersDuration)) {
        return "Film created";
      }
      else {
        return "Error: Film not created (might be missing parameters)";
      }
    }
    else if (requestVector[1] == "group" && requestVector.size() == 3) {
      std::string name = requestVector[2];
      if (manager->createGroup(name)) {
        return "Group created";
      }
      else {
        return "Error: Group not created (might be missing parameters)";
      }
    }
  }
  else if (requestVector[0] == "add" && requestVector.size() == 3) {
    std::string groupName = requestVector[1];
    std::string mediaName = requestVector[2];
    if (manager->addMediaToGroup(groupName, mediaName)) {
      return "Media added";
    }
    else {
      return "Error: Media not added (media or group might not exist)";
    }
  }
  else if (requestVector[0] == "delete" && requestVector.size() == 3) {
    if (requestVector[1] == "group") {
      std::string name = requestVector[2];
      if (manager->deleteGroup(name)) {
        return "Group deleted";
      }
      else {
        return "Error: Group not deleted (group might not exist)";
      }
    }
    else if (requestVector[1] == "media") {
      std::string name = requestVector[2];
      if (manager->deleteMultimedia(name)) {
        return "Media deleted";
      }
      else {
        return "Error: Media not deleted (media might not exist)";
      }
    }
  }
  else if (requestVector[0] == "display" && requestVector.size() == 3) {
    if (requestVector[1] == "group") {
      std::string groupName = requestVector[2];
      std::stringstream ss;
      manager->displayGroup(groupName, ss);
      return ss.str();
    }
    else if (requestVector[1] == "media") {
      std::string mediaName = requestVector[2];
      std::stringstream ss;
      manager->displayMultimedia(mediaName, ss);
      return ss.str();
    }
  }
  else if (requestVector[0] == "play" && requestVector.size() == 2) {
    std::string mediaName = requestVector[1];
    if (manager->playMultimedia(mediaName)) {
      return "Media played";
    }
    else {
      return "Error: Media not played (media might not exist)";
    }
  }
  return "Error: Invalid request format (missing parameters or wrong action)";
};

#endif
