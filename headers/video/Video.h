// Video.h
#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"
#include <string>

class Video : public Multimedia {
private:
    int duration;

public:
    Video(const std::string& objectName, const std::string& filePath, int duration)
        : Multimedia(objectName, filePath), duration(duration) {}

    int getDuration() const { return duration; }

    void setDuration(int duration) { this->duration = duration; }

    void display(std::ostream& out) const override {
        Multimedia::display(out);
        out << "Duration: " << duration << "\n";
    }

    void play() const override{
        std::string command = "open " + getFilePath() + " &";
        system(command.data());
    }
};

#endif // VIDEO_H