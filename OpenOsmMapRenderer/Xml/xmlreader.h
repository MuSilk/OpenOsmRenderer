#ifndef XMLREADER_H
#define XMLREADER_H

#include <string>
#include <map>

#include "Xml/way.h"
#include "Xml/node.h"

using std::string;

class xmlReader
{
public:
    double minlat,maxlat,minlon,maxlon;
    double Width,Height;
    xmlReader();
    std::map<long long,Node> nodes;
    std::map<long long,Way> ways;
    void LoadFile(const char*);
    void PrintNodes();
    void PrintWays();
};

#endif // XMLREADER_H
