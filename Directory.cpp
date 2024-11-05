#include "Directory.h"
using namespace std;

Directory::Directory(const string& name) : name(name) {}

Directory::~Directory() {}

string Directory::getKey() const {
    return name;
}

string Directory::getType() const {
    return "Directory";
}


