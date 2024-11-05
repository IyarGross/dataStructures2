#ifndef TREELIST_H
#define TREELIST_H

#include "MultiTree.h"
#include <list>
#include <memory>

template <typename T>
class TreeList {
private:
    std::list<MultiTree<T> *> trees;

public:
    TreeList();  // Constructor
    ~TreeList(); // Destructor

    NodeRecord<T>* search(const T& key) const;
    void addTree(NodeRecord<T>* rootRecord);
    bool addRecord(const T& parentKey, NodeRecord<T>* record);
    bool removeRecord(const T& key);
    void printAllTrees() const;
};

// Implementation
template <typename T>
TreeList<T>::TreeList() {
    // TODO: complete
}

template <typename T>
TreeList<T>::~TreeList() {
    // TODO: complete
}

template <typename T>
void TreeList<T>::addTree(NodeRecord<T>* rootRecord) {
    // TODO: complete
}

template <typename T>
bool TreeList<T>::addRecord(const T& parentKey, NodeRecord<T>* record) {
    // TODO: complete
    return false;
}

template<typename T>
bool TreeList<T>::removeRecord(const T& key) {
    // TODO: complete
    return false;
}

template <typename T>
void TreeList<T>::printAllTrees() const {
    // TODO: complete
}

template <typename T>
NodeRecord<T>* TreeList<T>::search(const T& key) const { 
    // TODO: complete
    return nullptr;
}

#endif  // TREELIST_H
