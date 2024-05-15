#ifndef BinaryTreeNode_h
#define BinaryTreeNode_h
#include <iostream>
using namespace std;
template <class T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
};

#endif