#ifndef MULTITREENODE_H
#define MULTITREENODE_H

#include "NodeRecord.h"
#include <list>
#include <memory>
#include <iostream>  // Include the necessary header for std::cout
using namespace std;
template <typename T>
class MultiTreeNode {
private:
    NodeRecord<T>* record;
    list<MultiTreeNode<T>*> children;

public:
    list<MultiTreeNode<T>*>& getChildren() { return children; }
    string getKey() const;
    NodeRecord<T>* getRecord() const;
    MultiTreeNode(NodeRecord<T>* record);
    bool addChild(NodeRecord<T>* newRecord);
    bool removeChild(const T& key);
    void print() const;
    ~MultiTreeעNode();
    void deleteAllSubTree(MultiTreeNode<T> *t);
};

#endif  // MULTITREENODE_H