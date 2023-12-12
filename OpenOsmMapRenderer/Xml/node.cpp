#include "node.h"

#include <QtMath>

Node::Node()
{

}

double NodeDis(const Node& a,const Node& b){
    const double EARTH_RADIUS=6378137;
    double lat1=qDegreesToRadians(a.lat);
    double lat2=qDegreesToRadians(b.lat);

    double lon1=qDegreesToRadians(a.lon);
    double lon2=qDegreesToRadians(b.lon);

    double dlat=lat1-lat2;
    double dlon=lon1-lon2;

    double s=2*asin(sqrt(pow(sin(dlat/2),2)+cos(lat1)*cos(lat2)*pow(sin(dlon/2),2)));
    return s*EARTH_RADIUS;
}
