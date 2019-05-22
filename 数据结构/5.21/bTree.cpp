//
//  createBTree.cpp
//  5.21
//
//  Created by Loren on 2019/5/18.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "bTree.h"
#include "stack.h"

using namespace std;
const string outFilePath ="/Users/luoyongjia/Program/C++/数据结构/数据结构上机/5.21/5.21/outPut.txt";
using namespace std;

bTree::bTree(){
    cout<<"Wrong."<<endl;
}
//Create a complete binary tree from an array
bTree::bTree(string* words, int* countN){
    int countWords = 0;
    outputFilePath = "/Users/luoyongjia/Program/C++/数据结构/数据结构上机/5.21/5.21/outPut.txt";
    fstream outputFile(outputFilePath, ios::out);
    outputFile.close();
    while(words[countWords] != ""){
        countWords++;
    }
    
    tree = new bTreeNode [countWords];
    for(int i = 0; i < countWords; i++){
        tree[i].data = words[i];
        tree[i].countNum = countN[i];
        tree[i].lChild = NULL;
        tree[i].rChild = NULL;
    }
    
    for(int i = 0; i < (countWords) / 2 ; i++){
        if(2 * i + 2 <= countWords){
            tree[i].lChild = &(tree[2 * i + 1]);
        }
        if(2 * i + 3 <= countWords){
            tree[i].rChild = &(tree[2 * i + 2]);
        }
    }
}
//recursive pre-order
void bTree::writeRePreO(){
    ofstream outputFile(outputFilePath, ios::app);
    outputFile<<"****************************************\n";
    outputFile<<"         recursive pre-order\n";
    outputFile<<"****************************************\n";
    outputFile.close();
}
void bTree::rePreOrder(bTreeNode *p){
    fstream outputFile(outFilePath, ios::app);
    
    if(p == NULL){
        return;
    }
    outputFile<<p->countNum<<" "<< p->data<<endl;
    rePreOrder(p->lChild);
    rePreOrder(p->rChild);
}
//recursive in-order
void bTree::writeReInO(){
    fstream outputFile(outputFilePath, ios::app);
    outputFile<<"****************************************"<<endl;
    outputFile<<"         recursive in-order"<<endl;
    outputFile<<"****************************************"<<endl;
    outputFile.close();
}
void bTree::reInOrder(bTreeNode *p){
    fstream outputFile(outFilePath, ios::app);
    
    if(p == NULL){
        return;
    }
    this->reInOrder(p->lChild);
    outputFile<< p->countNum<<" "<<p->data<<endl;
    this->reInOrder(p->rChild);
}
//recursive post-order
void bTree::writeRePoO(){
    fstream outputFile(outputFilePath, ios::app);
    outputFile<< "****************************************"<<endl;
    outputFile<<"         recursive post-order"<<endl;
    outputFile<<"****************************************"<<endl;
    outputFile.close();
}

void bTree::rePostOrder(bTreeNode *p){
    fstream outputFile(outFilePath, ios::app);
    
    if(p == NULL){
        return;
    }
    this->rePostOrder(p->lChild);
    this->rePostOrder(p->rChild);
    outputFile<<p->countNum<<" "<<p->data<<endl;
}

//non-recursive pre-order
void bTree::nrPreOrder(){
    //DLR;R要在L的下面
    ofstream outputFile(outputFilePath, ios::app);
    outputFile<<"****************************************\n";
    outputFile<<"         non-recursive pre-order\n";
    outputFile<<"****************************************\n";
    bTreeNode *p = tree;
    if(p == NULL){
        return;
    }
    stack<bTreeNode* > stackBTree;
    stackBTree.push(p);
    while(!stackBTree.empty()){
        bTreeNode *temp;
        stackBTree.get_top(temp);
        outputFile<<temp->countNum<<" "<<temp->data<<endl;
        stackBTree.pop();
        //R在L的下面
        if(temp->rChild){
            stackBTree.push(temp->rChild);
        }
        if(temp->lChild){
            stackBTree.push(temp->lChild);
            
        }
    }
    
}
//non-recursive in-order
void bTree::nrInOrder(){
    //L, D, R
    ofstream outputFile(outputFilePath, ios::app);
    outputFile<<"****************************************\n";
    outputFile<<"         non-recursive in-order\n";
    outputFile<<"****************************************\n";
    stack<bTreeNode* > stackBTree;
    bTreeNode* temp = tree;
    while(temp|| !stackBTree.empty()){
        if(temp){
            stackBTree.push(temp);
            temp = temp->lChild;
        }else{
            stackBTree.get_top(temp);
            outputFile<<temp->countNum<<" "<<temp->data<<endl;
            stackBTree.pop();
            temp = temp->rChild;
        }
    }
}

//non-recursive post-order
void bTree::nrPostOrder(){
    //D, R, L
    ofstream outputFile(outputFilePath, ios::app);
    outputFile<<"****************************************\n";
    outputFile<<"         non-recursive post-order\n";
    outputFile<<"****************************************\n";
    if(tree == NULL){
        return;
    }
    stack<bTreeNode*> stackBTree;   //临时的栈，存放当前结点的LR
    stack<bTreeNode*> stackBTree2;
    bTreeNode* temp;
    stackBTree.push(tree);
    while(!stackBTree.empty()){
        stackBTree.get_top(temp);
        stackBTree.pop();
        stackBTree2.push(temp); //当前结点压入输出栈
        if(temp->lChild){
            stackBTree.push(temp->lChild);//临时栈压入当前结点的左子
        }
        if(temp->rChild){
            stackBTree.push(temp->rChild);//LR
        }
    }
    while(!stackBTree2.empty()){
        stackBTree2.get_top(temp);
        outputFile<<temp->countNum<<" "<<temp->data<<endl;
        stackBTree2.pop();
    }
}
