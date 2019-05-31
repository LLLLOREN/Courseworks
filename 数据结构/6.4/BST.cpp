//
//  BST.cpp
//  6.4
//
//  Created by Loren on 2019/5/31.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#include "BST.hpp"
#include <iostream>
using namespace std;

BST::BST(){
    tree = new treeNode;
    tree->countNum = -1;
}

bool BST::createBST(int num){
    if(tree->countNum == -1){
        tree->countNum = num;
        return true;
    }else{
        while(Insert(num)){
            return true;
        }
        return false;
    }
}

bool BST::Insert(int num){
    treeNode* p;
    treeNode* parentp;
    int lr = 0;
    p = tree;
    parentp = NULL;
    if(num == p->countNum){
        cout<<"The num has already in this tree."<<endl;
        return false;
    }
    while(p){
        if(num > p->countNum){
            parentp = p;
            lr = 1;
            p = p->rChild;
        }else{
            parentp = p;
            lr = 0;
            p = p->lChild;
        }
    }
    p = new treeNode;
    p->countNum = num;
    if(parentp){
        p->parent = parentp;
        if(lr == 0){
            parentp->lChild = p;
        }else{
            parentp->rChild = p;
        }
    }
    return true;
}

bool BST::Delete(int num){
    treeNode *deleteNode = BSTSearch(num);
    if(deleteNode == NULL){
        cout<<"Data not fond."<<endl;
        return false;
    }else{
        treeNode* x = 0;
        treeNode* xChilds = 0;
        
        if(deleteNode->lChild == NULL || deleteNode->rChild == NULL){
            x = deleteNode;
        }else{
            x = successor(deleteNode);
        }
        if(x->lChild != NULL){
            xChilds = x->lChild;
        }else{
            xChilds = x->rChild;
        }
        if(xChilds != NULL){
            xChilds->parent = x->parent;
        }
        if(x->parent == NULL){
            tree = xChilds;
        }else if(x->parent->lChild == x){
            x->parent->lChild = xChilds;
        }else{
            x->parent->rChild = xChilds;
        }
        if(x != deleteNode){
            deleteNode->countNum = x->countNum;
        }
        return true;
    }
}

bool BST::Alter(int oriNum, int altNum){
    treeNode *oriNode = BSTSearch(oriNum);
    if(oriNode == NULL){
        cout<<"Data not fount."<<endl;
        return false;
    }else{
        Delete(oriNum);
        Insert(altNum);
        return true;
    }
}

treeNode* BST::BSTSearch(int num){
    treeNode* ptemp;
    ptemp = tree;
    while (ptemp) {
        if(ptemp->countNum == num){
            return ptemp;
        }else if(num > ptemp->countNum){
            ptemp = ptemp->rChild;
        }else{
            ptemp = ptemp->lChild;
        }
    }
    return NULL;
}

int BST::getMinNum(){
    treeNode* ptemp;
    ptemp = tree;
    while(ptemp->lChild){
        ptemp = ptemp->lChild;
    }
    return ptemp->countNum;
}

int BST::getMaxNum(){
    treeNode* ptemp;
    ptemp = tree;
    while(ptemp->rChild){
        ptemp = ptemp->rChild;
    }
    return ptemp->countNum;
}

treeNode* BST::successor(treeNode * presentPoint){
    treeNode* ptemp;
    ptemp = presentPoint->rChild;
    while(ptemp->lChild){
        ptemp = ptemp->lChild;
    }
    return ptemp;
}

treeNode* BST::Predecessor(treeNode *presentPoint){
    treeNode* ptemp;
    ptemp = presentPoint->lChild;
    while(ptemp->rChild){
        ptemp = ptemp->rChild;
    }
    return ptemp;
}
