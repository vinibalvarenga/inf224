#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include <string>
#include <iostream>

class Film : public Video {
private:
    int chapters;
    int* chaptersDuration;

public:
    Film(std::string objectName, std::string filePath, int duration, int chapters, const int * chaptersDuration)
        : Video(objectName, filePath, duration), chapters(chapters){
            this->chaptersDuration = new int[chapters];
            for (int i = 0; i < chapters; i++) {
                this->chaptersDuration[i] = chaptersDuration[i];
            }
        }

    Film& operator=(const Film& other) {
        if (this != &other) {
            delete[] chaptersDuration;  // delete current chaptersDuration

            chapters = other.chapters;
            chaptersDuration = new int[chapters];
            for (int i = 0; i < chapters; i++) {
                chaptersDuration[i] = other.chaptersDuration[i];
            }
        }
        return *this;
    }   

    ~Film() {
        delete[] this->chaptersDuration;
        std::cout << "Destrutor de Film chamado para " << getObjectName() << std::endl;

    }

    int getChapters() const { return chapters; }
    int* getChaptersDuration() const { 
        int* chaptersDurationCopy = new int[chapters];
        for (int i = 0; i < chapters; i++) {
            chaptersDurationCopy[i] = chaptersDuration[i];
        }
        return chaptersDurationCopy;
    }
    int getChapterDuration(int chapter) const { return chaptersDuration[chapter]; }

    void setChapters(int chapters) { this->chapters = chapters; }
    void setChaptersDuration(int* chaptersDuration, int chapters) {
        this->chapters = chapters;
        delete[] this->chaptersDuration;
        this->chaptersDuration = new int[chapters];
        for (int i = 0; i < chapters; i++) {
            this->chaptersDuration[i] = chaptersDuration[i];
        }
    }

    void display(std::ostream& out) const override {
        Video::display(out);
        out << "Chapters: " << chapters << "\n";
        out << "Chapters duration: ";
        for (int i = 0; i < chapters; i++) {
            out << chaptersDuration[i] << " ";
        }
        out << "\n";
    }

};

#endif // FILM_H