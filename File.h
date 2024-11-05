#ifndef FILE_H
#define FILE_H
using namespace std;
#include <iostream>
#include "NodeRecord.h"
#include <string>

class File : public NodeRecord<string> {
private:
    string name;//name of the file
    string content;//the content of the file

public:
   explicit  File(const string& name1);//constructor
    ~File() ;
    string getKey() const override ;
    string getType() const override;
    string getContent() const;

    bool canHaveChildren() const override;
    void appendContent(const string& newContent);//add content to the end of the file
    bool deleteSubstring(const string& toDelete);
};

#endif  // FILE_H
