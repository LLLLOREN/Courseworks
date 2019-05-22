//
//  main.cpp
//  5.9作业
//
//  Created by Loren on 2019/5/9.
//  Copyright © 2019 咕咕咕. All rights reserved.
//
#include "queue.h"
#include "List.h"
#include <iostream>


int main(int argc, const char * argv[]) {
    // insert code here...
    List* list = new List();
    string nums;
    int n = 100;
    unsigned long coNum = 0;
    unsigned long inNum = 0;
    
    for(int i = 0; i < 10; i++){
        list->append(i, n);
    }
    cout<<"Please enter a string of numbers:"<<endl;
    cin>>nums;
    inNum = nums.size();
    //检查是否为数字
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= '0' && nums[i]<='9'){
            nums[i] = nums[i] - 48;
            coNum++;
        }else{
            cout<<"input error"<<endl;
            break;
        }
    }
    if(inNum == coNum){
        for(int i = 0; i < inNum; i++){
            list->Write(nums[i]);
        }
        list->printall();
        cout<<endl;
    }
    return 0;
}
