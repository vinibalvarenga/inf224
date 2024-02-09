#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <memory>
#include "Multimedia.h"

class Group : public std::list<std::shared_ptr<Multimedia>> {
private:
    std::string name;

public:
    Group(std::string name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

    void addElement(const std::shared_ptr<Multimedia>& element) {
        this->push_back(element);
    }

    void display(std::ostream& stream) const {
        for (const auto& item : *this) {
            item->display(stream);
        }
    }
};

#endif // GROUP_H