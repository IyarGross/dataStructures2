//
// Created by Iyar Gross on 03/11/2024.
#include <MultiTree.h>
#include<MultiTreeNode.h>
#include<iostream>
using namespace std;
// Implementation

template <typename T>
MultiTree<T>::~MultiTree() {
    // TODO: complete
}

template <typename T>
bool MultiTree<T>::addRecord(const T& parentKey, NodeRecord<T>* record) {
    // TODO: complete
    return false;
}


template <typename T>
bool MultiTree<T>::removeRecord(const T& key) {
    // TODO: complete
    return false;
}


template <typename T>
NodeRecord<T>* MultiTree<T>::searchRecord(const T& key) {
    // TODO: complete
    return nullptr;  // Return nullptr if not found
}


template <typename T>
void MultiTree<T>::print(MultiTreeNode<T>* current,int level) const {
    for (int i = 0; i < level; i++)
        cout << "   ";
    cout << current->content;
    for (auto it = current->responses.begin(); it != current->responses.end(); it++)
        print(*it, level + 1);
}