#include "graph.h"
#include <QDebug>

Graph::Graph() {}

void Graph::insertPath(Node a,Node b){
    //实现在节点a与节点b间加边(可以自己增加变量)
}
double Graph::FindPath(Node start,Node end,std::vector<long long>& ans){
    //要求给定起点和终点，输出路径(经过Node的id编号，并存在ans中，返回距离，若路径不存在，返回-1)
    return -1;
}
double Graph::FindPath(std::vector<Node> start,std::vector<Node> end,std::vector<long long>& ans){
    //要求给定起点和终点数组，输出路径(经过Node的id编号，并存在ans中，返回距离，若路径不存在，返回-1)
    return -1;
}
void Graph::Clear(){
    //用于切换文件时清除数据
}
