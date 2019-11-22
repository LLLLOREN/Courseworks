//矩阵
// Created by 罗咏佳 on 2019/11/22.
//

#ifndef TEST_MAP_H
#define TEST_MAP_H

#include "graphNode.h"
#include <vector>
#include <queue>
using namespace std;

//矩阵图操作
class cMap
{
private:
    int len;                                                    // 图中最多可以容纳的定点数
    int m_iNodeCount;                                                   // 已经添加的顶点个数
    Node *m_pNodeArray;                                                 // 用来存放顶点数组
    int *m_pMatrix;                                                     // 用来存放邻接矩阵

public:
    cMap(int capacity);
    ~cMap();
    bool addNode(Node *pNode);                                           // 向图中添加顶点
    void resetNode();                                                    // 重置
    bool setValueToMatrixForDirectedGraph(int row, int col, int val=1);  // 设置有向图的顶点信息
    bool connectForUnDirectedGraph(int row, int col, int val=1);// 设置无向图的顶点信息
    void showMatrix();
    bool getValueFromMatrix(int row, int col, int&val);                  // 访问邻接矩阵的值
    void DFT(int nodeIndex);                                            // 深度优先搜索
    void BFT(int nodeIndex);                                            // 广度优先搜索

};
//邻接表图操作
class lMap{
private:
    int m_iCapacity;
    vector<VertexNode*> adjList;
    int vertexNum, arcNum;
    int* visited;
    queue<int> que;
public:
    lMap(char* a, int n, int e);
    ~lMap();
    void resetNode();
    void DFS(int nodeIndex);
    void BFS(int nodeIndex);
    void connect(int a, int b);      //插入边
    void show();
};
#endif //TEST_MAP_H
