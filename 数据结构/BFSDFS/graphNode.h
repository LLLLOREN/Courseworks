//
// Created by 罗咏佳 on 2019/11/22.
//

#ifndef TEST_GRAPHNODE_H
#define TEST_GRAPHNODE_H
//矩阵点
class Node
{
public:
    Node(char data=0);
    char m_cData;
    bool m_bIsVisited;
};
//边表节点
struct ArcNode{
    int adjvex;     //指向的顶点
    ArcNode* next;  //指向表头节点的下一条邻接的边
};
//顶点节点
struct VertexNode{
    char vertex;
    ArcNode* firstedge;     //接上的第一个边
};
#endif //TEST_GRAPHNODE_H
