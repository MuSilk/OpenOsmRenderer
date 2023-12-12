#ifndef WAY_H
#define WAY_H

#include <vector>
#include <map>
#include <string>

using std::string;

#include "Xml/node.h"

class Way{
public:
    Way();
    long long id;
    std::vector<Node> nodes;
    Node AveNode;
    std::map<string,string> tags;
    double minlon,minlat,maxlon,maxlat;
    double normalized_minlon,normalized_minlat,normalized_maxlon,normalized_maxlat;

    friend std::ostream& operator<<(std::ostream& out,const Way& way){
        out << "Way id:" << way.id << std::endl;
        //        out << "\tnodes: ";
        //        for (Node node : way.nodes) {
        //            out << node << ",";
        //        }
        out << std::endl;
        out << "\ttags:";
        for (const auto &tag : way.tags) {
            out << tag.first << ":" << tag.second << ",";
        }
        out << std::endl;
        return out;
    }
    void InitAveNode(){
        AveNode.lon=0;
        AveNode.lat=0;
        for(auto& i:nodes){
            AveNode.lon+=i.lon;
            AveNode.lat+=i.lat;
        }
        AveNode.lon/=nodes.size();
        AveNode.lat/=nodes.size();
    }
};

#endif // WAY_H
