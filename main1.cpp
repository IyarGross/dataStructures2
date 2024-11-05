//
// Created by Iyar Gross on 05/11/2024.
//
#include<iostream>
#include<File.h>
#include<string>
#include<MultiTree.h>
using namespace std;
int main() {
 File a("hello");
 File * record=&a;
 MultiTreeNode<File> b(record);

}