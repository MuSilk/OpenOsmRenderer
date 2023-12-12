#include "objectmap.h"

ObjectMap::ObjectMap(){
    background=QVector3D(0.0f,0.0f,0.0f);
    pathcolor=QVector3D(1.0,1.0,1.0);
    //int priority,int type,string key,string value,QVector3D color
    //type为1时不填充，为0时填充
    //priority越大显示优先级越高
    //value=""时显示取决于way有无key标签，有具体值时取决于value值
    //背景颜色
    tags.push_back(Tag(0,0,"building","",QVector3D(0,1.0,0)));
    tags.push_back(Tag(0,0,"leisure","",QVector3D(1.0,0.0,0.0)));
    tags.push_back(Tag(0,0,"water","",QVector3D(0.0,0.0,1.00)));
    tags.push_back(Tag(0,1,"highway","",QVector3D(1.0,0.0,1.0)));
}

ObjectMap::~ObjectMap(){
    for(auto i:LinestripRendererGroup)delete i;
    for(auto i:PolygonRendererGroup)delete i;
    LinestripRendererGroup.clear();
    PolygonRendererGroup.clear();
}

void ObjectMap::Load(const char* file,Shader shader,QVector2D pos,QVector2D size){
    for(auto i:LinestripRendererGroup)delete i;
    for(auto i:PolygonRendererGroup)delete i;
    LinestripRendererGroup.clear();
    PolygonRendererGroup.clear();
    Position=pos;
    Size=size;
    FileName=file;
    Changed=true;
    this->shader=new Shader(shader);
    if(PathRenderer==nullptr)PathRenderer=new dynamicSpriteLineStripRenderer(shader,pathcolor);
}

void ObjectMap::LoadData(){
    reader.LoadFile(FileName.c_str());

    double scale=fmin(Size.x()/reader.Width,Size.y()/reader.Height);
    Size.setX(scale*reader.Width);
    Size.setY(scale*reader.Height);

    for(auto& i:reader.ways){
        auto& way=i.second;
        for(auto &j:tags){
            if(way.tags.find(j.key)!=way.tags.end()&&(j.value==""||way.tags[j.key]==j.value)){
                if(j.type==1)LinestripRendererGroup.push_back(new ObjectLineStrip(*shader,way,j.color,j.priority));
                else PolygonRendererGroup.push_back(new ObjectPolygon(*shader,way,j.color,j.priority));
                break;
            }
        }
    }
    sort(PolygonRendererGroup.begin(),PolygonRendererGroup.end());
    sort(LinestripRendererGroup.begin(),LinestripRendererGroup.end());
}

void ObjectMap::Render(){
    if(Changed)LoadData(),Changed=false;
    for(auto i:LinestripRendererGroup)i->Draw(Position,Size);
    for(auto i:PolygonRendererGroup)i->Draw(Position,Size);
    if(_renderpath)PathRenderer->Draw(Position,Size);
}

int ObjectMap::GetPath(string st,string ed){
    if(reader.table.find(st)==reader.table.end())return -1;
    if(reader.table.find(ed)==reader.table.end())return -2;
    vector<Node> ans;
    double d=reader.GetPath(st,ed,ans);
    vector<float> path;
    for(auto i:ans){
        path.push_back(i.normalized_lon);
        path.push_back(i.normalized_lat);
    }
    _renderpath=true;
    PathRenderer->UpdateData(path);
    return d;
}
