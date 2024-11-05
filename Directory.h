#ifndef DIRECTORY_H
#define DIRECTORY_H
using namespace std;

#include "NodeRecord.h"
#include <string>

class Directory : public NodeRecord<string> {
private:
    string name;

public:
    Directory(const string& name);
    ~Directory();

    string getKey() const override;
    string getType() const override;
};

#endif  // DIRECTORY_H
