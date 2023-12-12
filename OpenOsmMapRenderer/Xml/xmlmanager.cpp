#include "xmlmanager.h"

#include <QDebug>

xmlManager::xmlManager() {}

void xmlManager::LoadFile(const char* path){
    table.clear();
    graph.Clear();
    xmlReader::LoadFile(path);
    for(auto &i:ways){
        if(i.second.tags.find("name")!=i.second.tags.end()){
            table[i.second.tags["name"]]=i.first;
            std::cout<<i.second.tags["name"]<<std::endl;
        }
        if(i.second.tags.find("highway")!=i.second.tags.end()){
            for(size_t j=0;j<i.second.nodes.size()-1;j++)graph.insertPath(i.second.nodes[j],i.second.nodes[j+1]);
        }
    }
}

void xmlManager::Search(const Node& node,double dis,std::vector<Node>& ans){
    ans.clear();
    for(auto &i:nodes){
        if(NodeDis(node,i.second)<=dis)ans.push_back(i.second);
    }
}

void xmlManager::Search(const Way& way,double dis,std::vector<Node>& ans){
    Search(way.AveNode,dis,ans);
}

double xmlManager::GetPath(const string& st,const string& ed,std::vector<Node>& ans){
    return GetPath(ways[table[st]],ways[table[ed]],ans);
}
double xmlManager::GetPath(const Way& st,const Way& ed,std::vector<Node>& ans){
    return GetPath(st.AveNode,ed.AveNode,ans);
}
double xmlManager::GetPath(const Node& st,const Way& ed,std::vector<Node>& ans){
    return GetPath(st,ed.AveNode,ans);
}
double xmlManager::GetPath(const Way& st,const Node& ed,std::vector<Node>& ans){
    return GetPath(st.AveNode,ed,ans);
}
double xmlManager::GetPath(const Node& st,const Node& ed,std::vector<Node>& ans){
    std::vector<long long> tmp;
    double dis=1,d;
    while(true){
        std::vector<Node> s,e;
        Search(st,dis,s);
        Search(ed,dis,e);
        d=graph.FindPath(s,e,tmp);
        //qDebug()<<dis<<" "<<d<<" "<<s.size()<<" "<<e.size()<<"\n";
        if(d>-0.5)break;
        dis*=2;
    }
    ans.clear();
    for(auto i:tmp)ans.push_back(nodes[i]);
    return d;
}
