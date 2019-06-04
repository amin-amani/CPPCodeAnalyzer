#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include <QString>
#include <QPoint>
enum ObjectType{Class,Function,Comment,Include,Define};
class ParserObject
{
public:
QString Signature;
QString Body;
ObjectType Type;
QPoint Location;
};



#endif // OBJECTFACTORY_H
