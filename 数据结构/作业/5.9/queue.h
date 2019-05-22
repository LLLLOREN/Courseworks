//
//  queue.h
//  5.9作业
//
//  Created by Loren on 2019/5/9.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#ifndef queue_h
#define queue_h
#include <iostream>

using namespace std;


class queue{
private:
    int maxSize;
    int front;
    int rear;
    int *data_queue;
    int tag;
    
public:
    queue(int size);
    ~queue();
    bool empty();
    bool full();
    void clear();
    bool enQueue(int item);
    bool deQueue();
    bool get_front(int &x);
    void coutQueue();
};

queue::queue(int size){
    maxSize = size;
    data_queue = new int[maxSize];
    front = rear = 0;
    tag = 0;
}

queue::~queue(){
    delete [] data_queue;
}

bool queue::empty(){
    if(front == rear){
        tag = 0;
        return true;
    }
    tag = 1;
    return false;
}

bool queue::full(){
    if(((rear + 1)%maxSize) == front){
        return true;
    }
    return false;
}

void queue::clear(){
    front = rear;
}

bool queue::enQueue(int item){
    if(full()){
        return false;
    }
    tag = 1;
    data_queue[rear] = item;
    rear = (rear + 1) % maxSize;
    
    return true;
}
bool queue::deQueue(){
    if(empty()){
        return false;
    }
    front = (front + 1) % maxSize;
    return true;
}

bool queue::get_front(int &x){
    if(empty()){
        return false;
    }
    x = data_queue[front];
    return true;
}

void queue::coutQueue(){
    int temp = front;
    if(!empty()){
        while(temp != rear){
            cout<<data_queue[temp];
            temp++;
        }
    }
}

#endif /* queue_h */
