//
//  main.cpp
//  5.7作业
//
//  Created by Loren on 2019/5/8.
//  Copyright © 2019 咕咕咕. All rights reserved.
//
//转为2-9任意进制数字

#include <iostream>
#include "stack.h"
bool isnumber(char x){
    if (x >= '0' && x <= '9')
        return true;
    return false;
}

int conversion(int n, string snum){
    int num = 0;
    int temp;
    //转换为十进制整数
    for(int i = 0; i < snum.size(); i++){
        if(isnumber(snum[i])){
            num += num * 10 + snum[i] - 48;
        }else{
            cout<<"Wrong input!"<<endl;
            return 1;
        }
    }
    //转制
    if(n==0){
        cout<<"输入了错误的进制数，请输入2-9之间的整数。"<<endl;
        return 1;
    }
    stack<int> s;
    while(num){
        temp = num % n;
        s.push(temp);
        num /= n;
    }
    
    while(!s.empty()){
        int top;
        s.get_top(top);
        cout<<top;
        s.pop();
    }
    cout<<endl;
    return 0;
}

bool isop(char x){
    if(x == '(' || x == '[' || x == '{' || x == ')' || x == ']' || x == '}'){
        return true;
    }
    return false;
}
int priority(char x){
    if(x == '('){
        return 3;
    }else if(x == '['){
        return 2;
    }else if(x == '{'){
        return 1;
    }
    return 0;
}

int normal_match(string equation){
    char top;
    stack<char> operate;
    for(int i = 0; i < equation.size(); i++){
        if(isop(equation[i])){
            if(operate.empty()){
                operate.push(equation[i]);
                operate.get_top(top);
                continue;
            }//唯空时压入第一个
            if((top == '(' && equation[i] == ')') || (top == '[' && equation[i] == ']') || (top == '{' && equation[i] == '}')){
                operate.pop();
                operate.get_top(top);
            }else{
                if(priority(equation[i]) == priority(top)){
                    operate.push(equation[i]);
                    operate.get_top(top);
                }else if(priority(equation[i]) > priority(top)){
                    operate.push(equation[i]);
                    operate.get_top(top);
                }else{
                    cout<<"配对不正确！"<<endl;
                    return 1;
                }//错误的顺序
            }
        }
    }
    if(operate.empty()){
        cout<<"匹配正确"<<endl;
        return 0;
    }else{
        cout<<"匹配不正确！b"<<endl;
        return 1;
    }//错误的对数
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string equation;
    cout<<"请输入算式："<<endl;
    cin>>equation;
    normal_match(equation);
    return 0;
}
