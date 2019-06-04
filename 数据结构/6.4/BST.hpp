//
//  BST.hpp
//  6.4
//
//  Created by Loren on 2019/5/31.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class treeNode{
public:
    int data;
    int countNum;
    treeNode *lChild, *rChild;
    treeNode *parent;
    treeNode(){
        lChild = NULL;
        rChild = NULL;
        parent = NULL;
    }
};

class BST{
public:
    BST();
    bool createBST(int num);
    bool Insert(int num);
    bool Delete(int num);
    treeNode* BSTSearch(int num);
    int getMinNum();
    int getMaxNum();
    treeNode* successor(treeNode * presentPoint);
    treeNode* Predecessor(treeNode *presentPoint);
    
private:
    treeNode* tree;
    bool isHead;
};
#endif /* BST_hpp */
