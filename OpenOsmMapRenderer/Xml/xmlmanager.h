#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "Xml/xmlreader.h"
#include "Functions/graph.h"

class xmlManager:public xmlReader
{
public:
    xmlManager();
    void LoadFile(const char*);
    void Search(const Node& node,double dis,std::vector<Node>& ans);
    void Search(const Way& way,double dis,std::vector<Node>& ans);
    double GetPath(const Way& st,const Way& ed,std::vector<Node>& ans);
    double GetPath(const Node& st,const Way& ed,std::vector<Node>& ans);
    double GetPath(const Way& st,const Node& ed,std::vector<Node>& ans);
    double GetPath(const Node& st,const Node& ed,std::vector<Node>& ans);
    double GetPath(const string& st,const string& ed,std::vector<Node>& ans);
    std::map<std::string,int> table;
private:
    Graph graph;
};

#endif // XMLMANAGER_H
