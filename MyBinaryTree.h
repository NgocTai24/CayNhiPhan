#ifndef MyBinaryTree_h
#define MyBinaryTree_h
#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
template <class T>
class MyBinaryTree{
private:
    BinaryTreeNode<T> *root;
    // ham duyet tien thu tu;
    void PrintPreOrder( BinaryTreeNode<T> *p) const {
        if (p == NULL) return;
        cout <<p->data<< " ";
        PrintPreOrder(p->left);
        PrintPreOrder(p->right); 
    }
    // ham duyet trung to
    void PrintMiddleOrder( BinaryTreeNode<T> *p) const {
        if (p == NULL) return;
        PrintMiddleOrder(p->left);
        cout << p->data << " ";
        PrintMiddleOrder(p->right); 
    }
    // ham duyet hau to
    void PrintPostOrder( BinaryTreeNode<T> *p) const {
        if (p == NULL) return;
        PrintPostOrder(p->left);
        PrintPostOrder(p->right); 
        cout << p->data << " ";
    }
    // ham dem so node cua cay
    void CountNode(BinaryTreeNode<T> *p)const{
        if( p == NULL) return 0;
        int countleft = CountNode(p->left);
        int countright = CountNode(p->right);
        return countleft + countright + 1;
    }
    // ham dem so node la  cua cay
    void CountLeaves(BinaryTreeNode<T> *p)const{
        if(p == NULL) return 0; 
        if(p->left == NULL || p->right == NULL){return 1;}
        int countleft = CountLeaves(p->left);
        int countright = CountLeaves(p->right);
        return countleft + countright ;
    }
    // ham dem so node noi cua cay
    void CountInNode(BinaryTreeNode<T> *p)const{
        return CountNode(p) - CountLeaves(p) ;
    }
    // ham Clear
    void Clear(BinaryTreeNode<T> *p ){
        if(p == NULL) return;
        Clear(p->left);
        Clear(p->right);
        delete p;
    }
    void AddNode(BinaryTreeNode<T> *p, T val){
        if (root == NULL){
            BinaryTreeNode<T> *NewNode = new BinaryTreeNode<T>;
            NewNode ->data = val;
            NewNode ->left = NULL;
            NewNode ->right = NULL;
            root = NewNode;
        }
        else{
            if(p->data > val){
                AddNode(p->left, val);
            }
            if (p->data < val ){
                AddNode(p->right , val);
            }
        }
    }
    
public:
    MyBinaryTree(){
        root == NULL;
    }
    void PrintPreOrder()const{
        PrintPreOrder(root);
    }
    void PrintMiddleOrder()const{
        PrintMiddleOrder(root);
    }
    void PrintPostOrder()const{
        PrintPostOrder(root);
    }
    void AddNode(T val){
        AddNode(root, val);
    }
    int CountNode()const{
        return CountNode(root);
    }
    int CountLeaves()const{
        return CountLeaves(root);
    }
    int CountInNode()const{
        return CountInNode(root);
    }
    void Clear(){
        Clear(root);
        root = NULL;
    }
};
#endif