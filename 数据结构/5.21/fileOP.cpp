//File operations
//  fileOP.cpp
//  5.21
//
//  Created by Loren on 2019/5/18.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
const int maxWords = 1024;  //Maximum number of stored strings.
using namespace std;
bool isWord(char x){
    if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ||( x >= '0' && x <= '9')){
        return true;
    }else{
        return false;
    }
}
string readFile(string datapath){
    ifstream file;
    file.open(datapath);
    string temp, content;
    while(getline(file,temp))
    {
        content += temp;
    }
    file.close();
    return content;
}

string* words(string content){
    string* words = new string[maxWords];
    transform(content.begin(), content.end(), content.begin(),::tolower);
    int flagW = 0;
    for(int i = 0; i < content.size(); i++){
        if(isWord(content[i])){
            string tempS;
            
            tempS += content[i];
            
            while (isWord(content[++i])) {
                tempS += content[i];
            }
            words[flagW] = tempS;
            flagW++;
            tempS.clear();
        }
    }
    return words;
}

int *countNum(string* str){
    int countStr = 0;
    while(str[countStr] != ""){
        countStr++;
    }
    int *preCount = new int [countStr];
    //Initialize pre
    for(int i = 0; i < countStr; i++){
        preCount[i] = 0;
    }
    for(int i = 0; i < countStr; i++){
        //Delete the current repeated word
        for(int j = i + 1; j < countStr; j++){
            if(str[i] == str[j]){
                preCount[i]++;
                for(int k = j; k < countStr; k++){
                    str[k] = str[k+1];
                }
                countStr--;
            }
        }
    }
    int *countNum = new int[countStr];
    //Initialize countNum
    for(int i = 0; i < countStr; i++){
        countNum[i] = 0;
    }
    
    for(int i = 0; i < countStr; i++){
        countNum[i] = preCount[i] + 1;
    }
    
    return countNum;
}
