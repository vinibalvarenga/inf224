// Multimedia.h
#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

class Multimedia {
private:
    std::string objectName;
    std::string filePath;

public:
    // Construtores
    Multimedia();
    Multimedia(const std::string& objectName, const std::string& filePath);

    // Destruidor
    virtual ~Multimedia();

    // Acessores
    std::string getObjectName() const;
    std::string getFilePath() const;

    // Modificadores
    void setObjectName(const std::string& objectName);
    void setFilePath(const std::string& filePath);

    // Método de exibição
    virtual void display(std::ostream& out) const;

    // Método de reprodução
    virtual void play() const = 0;
};

#endif // MULTIMEDIA_H