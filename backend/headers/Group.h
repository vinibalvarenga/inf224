#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include "Multimedia.h"

class Group : public std::list<Multimedia*> {
private:
    std::string name;

public:
    Group(std::string name) : name(name) {}

    const std::string getName() const {
        return name;
    }

    void display(std::ostream& stream) const {
        for (const auto& item : *this) {
            item->display(stream);
        }
    }
};

#endif // GROUP_H