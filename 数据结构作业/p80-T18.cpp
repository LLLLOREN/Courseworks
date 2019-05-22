//
//  main.cpp
//  P80_18
//
//  Created by Loren on 2019/5/17.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#include <iostream>

using namespace std;

int *getFeature(string str){
    unsigned long m = str.size();
    if(m){
        int *featureVector = new int[m];
        featureVector[0] = 0;
        for(int i = 0; i < m; i++){
            int k = featureVector[i - 1];
            while(k > 0 && str[i] != str[k]){
                k = featureVector[k - 1];
            }
            if(str[i] == str[k]){
                featureVector[i] = k + 1;
            }else{
                featureVector[i] = 0;
            }
        }
        return featureVector;
    }else{
        int *wrongR = new int[1];
        wrongR[0] = 1;
        cout<<"Wrong input."<<endl;
        return wrongR;      //输入字符串为空时报错
    }
}

int KMP(string patternArray, string targetArray, int* featureV, int stardIndex){
    unsigned long len_p, len_t;
    int j = 0;  //目标T的游标
    bool count = false;
    int bgin_match = stardIndex;
    len_p = patternArray.size();
    len_t = targetArray.size();
    if(len_p - len_t < stardIndex){
        cout<<"Wrong stard address."<<endl;
        return -1;
    }
    for(int i = stardIndex; i < len_p; i++){
        while(targetArray[j] != patternArray[i] && j > 0){
            j = featureV[j - 1];
        }   //如果和下一个不匹配，则将匹配的后移feature位
        if(targetArray[j] == patternArray[i]){
            j++;
        }
        if(j == len_t){
            bgin_match = i - j + 1;
            count = true;
            return bgin_match;
        }
    }
    if(count){
        cout<<bgin_match<<endl;
        return bgin_match;
    }else{
        cout<<"A string segment that does not have an exact match"<<endl;
        return -2;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string pArray, tArray;
    cout << "Please input the pattern array:"<<endl;
    cin>>pArray;
    cout<<"Please input the target array:"<<endl;
    cin>>tArray;
    int *fTargetVector = new int[tArray.size()]();
    fTargetVector = getFeature(tArray);
    KMP(pArray, tArray, fTargetVector, 0);
    return 0;
}
