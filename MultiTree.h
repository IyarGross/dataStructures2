#ifndef MULTITREE_H
#define MULTITREE_H

#include "MultiTreeNode.h"
#include <memory>

template <typename T>
class MultiTree {
private:
    MultiTreeNode<T>* root;//root, a node from type t

public:
    MultiTree(NodeRecord<T>* rootRecord);//constructor
    ~MultiTree();//distructor
    T getRootKey() { return root->getKey(); }
    NodeRecord<T>* searchRecord(const T& key);//
    bool addRecord(const T& parentKey, NodeRecord<T>* record);
    bool removeRecord(const T& key);
    void print(MultiTreeNode<T>* current,int level) const;
};
#endif  // MULTITREE_H