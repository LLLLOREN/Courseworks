//矩阵
// Created by 罗咏佳 on 2019/11/22.
//

#include "Map.h"
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
//矩阵图操作
cMap::cMap(int capacity)
{
    len = capacity;
    m_iNodeCount = 0;
    m_pNodeArray = new Node[len];
    m_pMatrix = new int[len * len];
    memset(m_pMatrix, 0, len * len * sizeof(int));
}


cMap::~cMap()
{
    delete[]m_pNodeArray;
    delete[]m_pMatrix;
}

bool cMap::addNode(Node *pNode)
{
    m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
    m_iNodeCount++;
    return true;
}

void cMap::resetNode()
{
    for (int i = 0; i < m_iNodeCount; i++)
    {
        m_pNodeArray[i].m_bIsVisited = false;
    }
}

bool cMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
    m_pMatrix[row * len + col] = val;
    return true;
}

bool cMap::connectForUnDirectedGraph(int row, int col, int val)
{
    m_pMatrix[row * len + col] = val;
    m_pMatrix[col * len + row] = val;
    return true;
}

void cMap::showMatrix()
{
    for (int i = 0; i < len; i++)
    {
        for (int k = 0; k < len; k++)
        {
            cout << m_pMatrix[i * len + k] << " ";
        }
        cout << endl;
    }

}
bool cMap::getValueFromMatrix(int row, int col, int&val)
{
    if (row < 0 || row >= len)
        return false;
    if (col < 0 || col >= len)
        return false;

    val = m_pMatrix[row * len + col];
    return true;
}

void cMap::DFT(int nodeIndex)
{
    int value;
    cout << m_pNodeArray[nodeIndex].m_cData << " ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;
    for (int i = 0; i < len; i++)
    {
        getValueFromMatrix(nodeIndex, i, value);
        if (value)
        {
            if (m_pNodeArray[i].m_bIsVisited)
                continue;
            else
                DFT(i);
        }
        else
            continue;
    }
}

void cMap::BFT(int nodeIndex)
{
    cout << m_pNodeArray[nodeIndex].m_cData << " ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;
//    vector<int> curVec;
//    curVec.push_back(nodeIndex);
//    breadthFirstTraverseImpl(curVec);
    int value = 0;
    queue<int> que;
    que.push(nodeIndex);
    while(!que.empty()){
        nodeIndex = que.front();
        que.pop();
        for(int i = 0; i < len; i++){
            getValueFromMatrix(nodeIndex, i, value);
            if (value != 0)
            {
                if (m_pNodeArray[i].m_bIsVisited)
                {
                    continue;
                }
                else
                {
                    cout << m_pNodeArray[i].m_cData << " ";
                    m_pNodeArray[i].m_bIsVisited = true;
                    que.push(i);
                }
            }
        }
    }
}

//邻接表图操作
lMap::lMap(char *a, int n, int e) {
    vertexNum = n;
    arcNum = e;
    for(int i = 0; i < vertexNum; i++){
        VertexNode* pNode = new VertexNode();
        pNode->vertex = a[i];
        pNode->firstedge = NULL;
        adjList.push_back(pNode);
    }
    visited = new int[vertexNum];
    memset(visited, 0, vertexNum * sizeof(int));
}

lMap::~lMap() {
    delete[] visited;
}

void lMap::resetNode() {
    for(int i = 0; i < vertexNum; i++) {
        visited[i] = 0;
    }
}

void lMap::connect(int vertex, int arcNode) {
    ArcNode *pArc = new ArcNode();
    pArc->adjvex = arcNode;
    if(adjList[vertex]->firstedge == NULL)
        adjList[vertex]->firstedge = pArc;
    else{
        ArcNode *p = adjList[vertex]->firstedge;
        while(p->next != NULL)
            p = p->next;
        p->next = pArc;
    }
}

void lMap::show() {
    cout<<"邻接表为："<<endl;
    for(int i = 0; i < vertexNum; i++){
        cout<<adjList[i]->vertex;
        ArcNode *p = adjList[i]->firstedge;
        while(p != NULL){
            cout<<"->"<<adjList[p->adjvex]->vertex;
            p = p->next;
        }
        cout<<"->NULL"<<endl;
    }
}

void lMap::DFS(int nodeIndex) {
    cout<<adjList[nodeIndex]->vertex<<" ";
    visited[nodeIndex] = 1;
    ArcNode *p = adjList[nodeIndex]->firstedge;
    while(p != NULL){
        int j = p->adjvex;
        if(visited[j] == 0)
            DFS(j);
        p = p->next;
    }
}
void lMap::BFS(int nodeIndex) {
    for(int i =0; i < vertexNum; i++){
        visited[i] = 0;
    }
    cout<<adjList[nodeIndex]->vertex<<" ";
    visited[nodeIndex] = 1;
    que.push(nodeIndex);
    while(!que.empty()){
        nodeIndex = que.front();
        que.pop();
        ArcNode *p = adjList[nodeIndex]->firstedge;
        while(p != NULL){
            int j = p->adjvex;
            if(visited[j] == 0){
                cout<<adjList[j]->vertex<<" ";
                visited[j] = 1;
                que.push(j);
            }
            p = p->next;
        }
    }
}