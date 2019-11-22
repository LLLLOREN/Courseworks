#include <iostream>
#include "Map.h"
#include "graphNode.h"

int main() {
    //矩阵
    cMap *pMap = new cMap(8);
    Node *pNodeA = new Node('r');
    Node *pNodeB = new Node('s');
    Node *pNodeC = new Node('t');
    Node *pNodeD = new Node('u');
    Node *pNodeE = new Node('v');
    Node *pNodeF = new Node('w');
    Node *pNodeG = new Node('x');
    Node *pNodeH = new Node('y');

    pMap->addNode(pNodeA);
    pMap->addNode(pNodeB);
    pMap->addNode(pNodeC);
    pMap->addNode(pNodeD);
    pMap->addNode(pNodeE);
    pMap->addNode(pNodeF);
    pMap->addNode(pNodeG);
    pMap->addNode(pNodeH);

    pMap->connectForUnDirectedGraph(0, 1);
    pMap->connectForUnDirectedGraph(0, 4);
    pMap->connectForUnDirectedGraph(1, 5);
    pMap->connectForUnDirectedGraph(2, 3);
    pMap->connectForUnDirectedGraph(2, 5);
    pMap->connectForUnDirectedGraph(2, 6);
    pMap->connectForUnDirectedGraph(3, 7);
    pMap->connectForUnDirectedGraph(5, 6);
    pMap->connectForUnDirectedGraph(6, 7);

    pMap->showMatrix();
    cout << endl;

    cout<<endl<<"深度优先遍历:"<<endl;
    pMap->DFT(1);
    cout << endl;

    pMap->resetNode();

    cout<<endl<<"广度优先遍历:"<<endl;
    pMap->BFT(1);
    cout << endl;

    //邻接链表
    char a[8] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
    lMap ListMap(a, 8, 9);
    ListMap.connect(0, 1);
    ListMap.connect(0, 4);
    ListMap.connect(1, 5);
    ListMap.connect(2, 3);
    ListMap.connect(2, 5);
    ListMap.connect(2, 6);
    ListMap.connect(3, 7);
    ListMap.connect(5, 6);
    ListMap.connect(6, 7);
    ListMap.connect(1, 0);
    ListMap.connect(4, 0);
    ListMap.connect(5, 1);
    ListMap.connect(3, 2);
    ListMap.connect(5, 2);
    ListMap.connect(6, 2);
    ListMap.connect(7, 3);
    ListMap.connect(6, 5);
    ListMap.connect(7, 6);

    ListMap.show();

    cout<<endl<<"深度优先遍历:"<<endl;
    ListMap.DFS(1);
    cout<<endl;
    ListMap.resetNode();
    cout<<endl<<"广度优先遍历:"<<endl;
    ListMap.BFS(1);
    cout<<endl;

    return 0;
}