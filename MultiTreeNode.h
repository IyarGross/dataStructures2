#ifndef MULTITREENODE_H
#define MULTITREENODE_H

#include "NodeRecord.h"
#include <list>
#include <memory>
#include <iostream>  // Include the necessary header for std::cout

template <typename T>
class MultiTreeNode {
private:
    NodeRecord<T>* record;
    list<MultiTreeNode<T>*> children;

public:
    list<MultiTreeNode<T>*>& getChildren() { return children; }
    std::string getKey() const;
    NodeRecord<T>* getRecord() const;
    MultiTreeNode(NodeRecord<T>* record);
    bool addChild(NodeRecord<T>* newRecord);
    bool removeChild(const T& key);
    void print() const;
 //   void deleteAllSubTree(NodeRecord<T>* record);
 //   bool isLeaf() { return childe.isempty(); }
    ~MultiTreeNode();
};
// Implementation
template <typename T>
MultiTreeNode<T>::MultiTreeNode(NodeRecord<T>* record) : record(record) {}

template <typename T>
bool MultiTreeNode<T>::addChild(NodeRecord<T>* childRecord)
{
    if (record->canHaveChildren())///check if can have children
      {
        children.push_back(new MultiTreeNode<T>(childRecord));
         return true;
      }///if can, push to the children list a new child with the key of rhe record given
    return false;//if cant add child return false
}

template <typename T>
bool MultiTreeNode<T>::removeChild(const T& key)
{
   
    for (auto it = children.begin(); it != children.end(); ++it)
    {
        if ((*it)->key == key)
        {
            delete* it; // שחרור הזיכרון
            children.erase(it); // הסרת הבן מרשימת הבנים
            return true;
        }
        if ((*it)->removeChild(key))
            return true;
        return false;
    } 
}

template <typename T>
NodeRecord<T>* MultiTreeNode<T>::getRecord() const {
    // TODO: complete
    return record;
}

template <typename T>
std::string MultiTreeNode<T>::getKey() const {
    return record->getKey();
}

template <typename T>
void MultiTreeNode<T>::print() const {
    cout << record->getKey() << endl;
}

template <typename T>
MultiTreeNode<T>::~MultiTreeNode() {
    for (auto iter = children.begin(); iter != children.end(); iter++)
        delete* iter;
    delete record;
}

//    deleteAllSubTree(record);
//    delede record;
//}
//template <typename T>
//void MultiTreeNode<T>::deleteAllSubTree(NodeRecord<T>* t)
//{
//    if (!t->isLeaf())
//    {
//        if (!t->isLeaf())
//        {
//            // ניגש לכל ילד של t באמצעות לולאת for רגילה
//            for (size_t i = 0; i < t->children.size(); ++i) {
//                NodeRecord<T>* node = t->children[i];
//                deleteAllSubTree(node);  // קריאה רקורסיבית למחיקת תת-העץ של הילד
//            }
//       /* for (NodeRecord<T>* node : t->cildren) {
//            deleteAllSubTree(node);
//            node->isLeaf() = true;*/
//        }
//        delete t;
//    }
//}


#endif  // MULTITREENODE_H