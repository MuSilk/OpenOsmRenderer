#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Xml/node.h"

class Graph
{
public:
    Graph();
    void insertPath(Node a,Node b);
    double FindPath(Node start,Node end,std::vector<long long>& ans);
    double FindPath(std::vector<Node> start,std::vector<Node> end,std::vector<long long>& ans);
    void Clear();
private:
};

#endif // GRAPH_H
