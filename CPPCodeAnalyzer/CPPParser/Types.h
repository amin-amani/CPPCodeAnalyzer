#ifndef TYPES_H
#define TYPES_H
#include<QObject>
class CPPVariables
{
public:
    QString type;
    QString Name;
};
class CPPFunctions
{
public:
    QString Type;
    QString Name;
    CPPVariables Arguments;

};

class CPPClass
{
 public:
    QString Name;
    QList<QString> PulicParents;
    QList<CPPVariables> PublicVariables;
    QList<CPPVariables> PrivateVariables;
};
#endif // TYPES_H
