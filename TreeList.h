#ifndef TREELIST_H
#define TREELIST_H

#include "MultiTree.h"
#include <list>
#include <memory>

template <typename T>
class TreeList {
private:
    std::list<MultiTree<T>*> trees;

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
    
}

template <typename T>
TreeList<T>::~TreeList() {
    if (!trees.empty())
    {
        for (auto it = trees.begin(); it != trees.end(); it++)
            if (*it)
                delete (*it);
        trees.clear();
    }
}

template <typename T>
void TreeList<T>::addTree(NodeRecord<T>* rootRecord) {
    trees.push_back(new MultiTree<T>(rootRecord));
}

template <typename T>
bool TreeList<T>::addRecord(const T& parentKey, NodeRecord<T>* record) {
    bool flage;
    for (auto it = trees.begin(); it != trees.end() && !flage; it++)

        flage = (*it)->addRecord(parentKey,record);
    return flage;
  /*  auto it = search(parentKey);
    if (!it)
    {
        it.addRecord(record);
        eturn true;
    }
    return false;*/
}

template<typename T>
bool TreeList<T>::removeRecord(const T& key) {
    auto it = search(key);
    if (!it)
    {
        delete it;
        return true;
        
    }
    return false;
}

template <typename T>
void TreeList<T>::printAllTrees() const {
    for (auto it = trees.begin(); it != trees.end(); it++)
    {
        (*it)->print();
        cout<< endl;
    }
}
template <typename T>
NodeRecord<T>* TreeList<T>::search(const T& key) const {
    
    for (auto it = trees.begin(); it != trees.end(); it++)
    {
        auto it1 = (*it)->searchRecord(key);
        if (it1 != nullptr)
            return it1;
    }

    return nullptr;
}

#endif  // TREELIST_H
