// Multimedia.h
#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

class Multimedia {
private:
    std::string objectName{};
    std::string filePath{};

public:
    // Construtores
    Multimedia();
    Multimedia(std::string objectName, std::string filePath);
    virtual ~Multimedia();

    std::string getObjectName() const; 
    std::string getFilePath() const;

    void setObjectName(std::string objectName);
    void setFilePath(std::string filePath);    

    virtual void display(std::ostream& out) const; 
    virtual void play() const = 0;
};

#endif // MULTIMEDIA_H