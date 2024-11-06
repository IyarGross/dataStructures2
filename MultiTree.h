#ifndef MULTITREE_H
#define MULTITREE_H

#include "MultiTreeNode.h"
#include <memory>

template <typename T>
class MultiTree {
private:
    MultiTreeNode<T>* root;

public:
    MultiTree(NodeRecord<T>* rootRecord);
    ~MultiTree();
    T getRootKey() { return root->getKey(); }
    NodeRecord<T>* searchRecord(const T& key);
    NodeRecord<T>* searchChild(MultiTreeNode<T>*child,const T & key);
    MultiTreeNode<T>* searchParent(MultiTreeNode<T>* child, const T& key);
    bool addRecord(const T& parentKey, NodeRecord<T>* record);
    bool removeRecord(const T& key);
    void print() const;
    void print(MultiTreeNode<T>* current, int level) const;
};

// Implementation
template <typename T>
MultiTree<T>::MultiTree(NodeRecord<T>* rootRecord) : root(new MultiTreeNode<T>(rootRecord)) {}

template <typename T>
MultiTree<T>::~MultiTree() {
    if (root != nullptr)
    {
        delete root;
        root = nullptr;
    }

}

template <typename T>
bool MultiTree<T>::addRecord(const T& parentKey, NodeRecord<T>* record) {
    // TODO: complete
    auto it = searchParent(root,parentKey);//אם לא טוב לחפש רק בשורוש כמו ילין
    if (it == nullptr)
        return false;
    return it->addChild(record);
   // return true;
}

template <typename T>
bool MultiTree<T>::removeRecord(const T& key) {
    // TODO: complete
    auto it = searchRecord(key);
    if (it == nullptr||it==root)
        return false;
    delete it;
    return true;
  
}


template <typename T>
NodeRecord<T>* MultiTree<T>::searchRecord(const T& key) {
    
    if (root->getKey() == key)
        return root->getRecord(); 
      return searchChild(root, key);
      return nullptr;
}

template <typename T>
NodeRecord<T>* MultiTree<T>::searchChild(MultiTreeNode<T>* child, const T& key)
{
    if ( child.getRecord() == key)
        return child.getRecord();
    for (auto it = child->getChildren().begin(); it != child->getChildren().end(); it++)
        searchChild(it, key);
    return nullptr;
}
template <typename T>
MultiTreeNode<T>* MultiTree<T>::searchParent(MultiTreeNode<T>* child, const T& key)
{
    if (child.getRecord() == key)
        return child;
    for (auto it = child->getChildren().begin(); it != child->getChildren().end(); it++)
        searchParent(it, key);
    return nullptr;
}
template <typename T>
void MultiTree<T>::print() const {
    print(root, 0);
}



template <typename T>
void MultiTree<T>::print(MultiTreeNode<T>* current, int level) const {
    for (int i = 0; i < level; i++)
        cout << "   ";
   // cout << current->content;
    current-> print();
    cout << endl;
 //   for (auto it = current->responses.begin(); it != current->responses.end(); it++)
    for (auto it = current->getChildren().begin(); it != current->getChildren().end(); it++)
        print(*it, level + 1);
}


#endif  // MULTITREE_H
