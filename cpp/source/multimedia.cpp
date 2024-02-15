// Multimedia.cpp
#include "Multimedia.h"

// Construtores
Multimedia::Multimedia() : objectName(""), filePath("") {}
Multimedia::Multimedia(std::string objectName, std::string filePath) : objectName(objectName), filePath(filePath) {}

// Destruidor
Multimedia::~Multimedia() {}

// Acessores
std::string Multimedia::getObjectName() const { return objectName; }
std::string Multimedia::getFilePath() const { return filePath; }

// Modificadores
void Multimedia::setObjectName(std::string objectName) { this->objectName = objectName; }
void Multimedia::setFilePath(std::string filePath) { this->filePath = filePath; }

// Método de exibição
void Multimedia::display(std::ostream& out) const {
    out << "Nome do Objeto: " << objectName << "\n";
    out << "Caminho do Arquivo: " << filePath << "\n";
}