#ifndef NODE_H
#define NODE_H

#include <iostream>


class Node{
public:
    Node();
    long long id;
    double lon,lat;
    double normalized_lon,normalized_lat;

    friend std::ostream& operator<<(std::ostream& out,const Node& node){
        out<<"Node id:" << node.id << "\tlon:" << node.normalized_lon << "\tlat:" << node.normalized_lat << std::endl;
        return out;
    }
    friend double NodeDis(const Node& a,const Node& b);
};

#endif // NODE_H
