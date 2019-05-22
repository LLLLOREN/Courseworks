#include <iostream>
#include "bTree.h"
#include <fstream>
using namespace std;

string readFile(string datapath);
string* words(string content);
int *countNum(string* str);

int main(int argc, const char * argv[]) {
    // insert code here...
    string datapath = "/Users/luoyongjia/Program/C++/数据结构/数据结构上机/5.21/5.21/";
    string dataF1, dataF2, allwords;
    string* word;
    int *countN;
    dataF1 = datapath + "1.txt";
    dataF2 = datapath + "2.txt";
    allwords += readFile(dataF1);
    allwords += readFile(dataF2);
    word = words(allwords);
    countN = countNum(word);
    
    bTree test(word, countN);
    test.writeRePreO();
    test.rePreOrder(test.tree);
    test.writeReInO();
    test.reInOrder(test.tree);
    test. writeRePoO();
    test.rePostOrder(test.tree);
    test.nrPreOrder();
    test.nrInOrder();
    test.nrPostOrder();
    return 0;
}


