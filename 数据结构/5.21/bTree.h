//
//  bTree.h
//  5.21
//
//  Created by Loren on 2019/5/18.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#ifndef bTree_h
#define bTree_h
#include <iostream>

using namespace std;

class bTreeNode{
public:
    string data;
    int countNum;
    bTreeNode *lChild, *rChild;
};

class bTree{
private:
    string *data;
    string outputFilePath;
    
public:
    bTreeNode* tree;
    bTree();
    bTree(string* words, int* countN);
    void writeRePreO(); //Boundary line
    void writeReInO();  //Boundary line
    void writeRePoO();  //Boundary line
    void rePreOrder(bTreeNode *p);  //recursive pre-order
    void reInOrder(bTreeNode *p);   //recursive in-order
    void rePostOrder(bTreeNode *p); //recursive post-order
    void nrPreOrder();  //non-recursive pre-order
    void nrInOrder();   //non-recursive in-order
    void nrPostOrder(); ////non-recursive post-order
};

#endif /* bTree_h */
