//
//  stack.h
//  5.7作业
//
//  Created by Loren on 2019/5/8.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <iostream>
using namespace std;

const int maxlen = 100;//栈的最大存储量

template <typename elementType>
class stack {
public:
    stack();//构造函数，用于初始化
    bool empty();//判断栈是否为空
    bool full();//判断栈是否为满
    bool get_top(elementType &x);//取栈顶元素
    bool push(elementType x);//元素入栈
    bool pop();//删除栈顶
private:
    int count;//元素的计数器
    elementType data[maxlen];//顺序存储结构
};

template <typename elementType>
stack<elementType>::stack() {
    count = 0;
}

template <typename elementType>
bool stack<elementType>::empty() {
    if (count == 0)
        return true;
    return false;
}

template <typename elementType>
bool stack<elementType>::full() {
    if (count == maxlen)
        return true;
    return false;
}

template <typename elementType>
bool stack<elementType>::get_top(elementType &x) {
    if (!empty()) {
        x = data[count - 1];
        return true;
    }
    return false;
}

template <typename elementType>
bool stack<elementType>::push(elementType x) {
    if (!full()) {
        data[count++] = x;
        return true;
    }
    return false;
}

template <typename elementType>
bool stack<elementType>::pop() {
    if (!empty()) {
        --count;
        return true;
    }
    return false;
}
#endif /* stack_h */
