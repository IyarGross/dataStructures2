#include "File.h"
//
// Created by Iyar Gross on 03/11/2024.
//
using namespace std;
#include<MultiTreeNode.h>
// Implementation
template <typename T>
MultiTreeNode<T>::MultiTreeNode(NodeRecord<T>* record) : record(record) {}
//constructor
template <typename T>
bool MultiTreeNode<T>::addChild(NodeRecord<T>* childRecord) {
 if (record()->canHaveChildren())///check if can have children
     {
     children.push_back(new MultiTreeNode<T>(childRecord));
     return true;
     }///if can, push to the children list a new child with the key of rhe record given
return false;//if cant add child return false
}//adds record to the children


template <typename T>
bool MultiTreeNode<T>::removeChild(const T& key) {
    auto it = this->children.begin();
    for (; it != this->children.end(); it++) {//go over children with it
        if(*it.getKey()==key) {//if the child key= to the key given
      it.deleteAllSubTrees();//delete the node
            return true;
        }
    }
    return false;//if didnt delete/found
}//delete a child if exsist

template <typename T>
NodeRecord<T>* MultiTreeNode<T>::getRecord() const {
    return record;
}

template <typename T>
std::string MultiTreeNode<T>::getKey() const {
    return record->getKey();
}

template <typename T>
void MultiTreeNode<T>::print() const {
     cout<<this->getRecord()->getKey();
}//print the key of this record

template <typename T>
MultiTreeNode<T>::~MultiTreeNode() {
 this->deleteAllSubTree();
}

// for( auto it = children.begin(); it != children.end();it++) {

template <typename T>
 void MultiTreeNode<T>::deleteAllSubTree(MultiTreeNode<T> *t) {
     if (t == nullptr) return;
     // if (t->isLeaf) delete t;
     for (auto it = t->children.begin(); it != t->children.end(); it++)
         deleteAllSubTree(*it);
     delete t;
    // if(children.isempty())
    //     delete record;
    // auto it = this->children.begin();
    // for (; it != this->children.end(); it++) {
    //     it->children->~MultiTreeNode();
    // };
 }