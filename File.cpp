#include "File.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
File::File(const string& name) : name(name), content("") {}///constructor

File::~File() {}///destructor

string File::getKey() const {
    return name;
}

string File::getType() const {
    return "File";
}

bool File::canHaveChildren() const {
    return false;
}

void File::appendContent(const string& newContent) {
content += newContent;

}///add content to the end of the file

bool File::deleteSubstring(const string& toDelete) {
    size_t position = content.find(toDelete);
    if (position != std::string::npos) {
        std::string modified = content;
        modified.erase(position, toDelete.length());
        content= modified;
        return true;
    }
return false;
};

string File::getContent() const {
    return content;
}
