//
//  List.h
//  5.9作业
//
//  Created by Loren on 2019/5/12.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#ifndef List_h
#define List_h

#include <iostream>
#include "queue.h"

class node{
public:
    queue *data;
    node *next;
    int sequence;
    
    node(int seq, int n, node* nextPtr = NULL){
        sequence = seq;
        data = new queue(n);
        next = nextPtr;
    }
};

class List{
public:
    List();
    ~List();
    void append(int seq, int n);
    void printall();
    void Write(int num);
private:
    node* head;
    node* tail;
    int number;
};

List::List(){
    head = NULL;
    tail = NULL;
    number = 0;
}

List::~List(){
    node* temp = NULL;
    while(head->next){
        temp = head->next;
        delete head;
        head = temp;
    }
    delete head;
}

void List::append(int seq, int n){
    node* node = new class node(seq, n);
    if(!head){
        head = node;
        tail = node;
        number++;
    }else{
        tail->next = node;
        tail = node;
        number++;
    }
}

void List::printall(){
    node* p = head;
    while(p->next){
        p->data->coutQueue();
        p = p->next;
    }
    
    p->data->coutQueue();
}

void List::Write(int num){
    node* p = head;
    while(p->next){
        if(num == p->sequence){
            p->data->enQueue(num);
            break;
        }else{
            p = p->next;
        }
        if (num == tail->sequence) {
            tail->data->enQueue(num);
        }
    }
}

#endif /* List_h */
