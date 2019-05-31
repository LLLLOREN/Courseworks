//
//  main.cpp
//  6.4
//
//  Created by Loren on 2019/5/31.
//  Copyright © 2019 咕咕咕. All rights reserved.
//

#include <iostream>
#include <vector>
#include "BST.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    BST testBST;
    vector<int> insertNum = {50, 72, 43, 85, 75, 20, 35, 45, 65, 30};
    for(int i = 0; i < insertNum.size(); i++){
        testBST.createBST(insertNum[i]);
    }
    
    return 0;
}
