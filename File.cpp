#include "File.h"

File::File(const string& name) : name(name), content("") {}

File::~File() {}
void File::appendContent(const string& newContent) {
    content += newContent;

}
string File::getKey() const {
    return name;
}

string File::getType() const {
    return "File";
}

bool File::canHaveChildren() const {
    return false;
}


bool File::deleteSubstring(const string& toDelete) 
{  
    // ����� ������ ����� ����� ������� �����
    size_t pos = content.find(toDelete); // ����� ������ �� ������ �������
    if (pos != std::string::npos) {  // �� ������ �����
        content.erase(pos, toDelete.length());
        return true;
    }// ����� ������ �������
    return false;
 };



