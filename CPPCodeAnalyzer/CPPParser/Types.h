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
  //  int privateInt;
protected:
   // int protectedInt;

 public:
    // int publicInt;
    QString Name;
    QList<QString> PulicParents;
    QList<QString> PrivateParents;
      QList<QString> ProtectedParents;
    QList<CPPVariables> PublicVariables;
    QList<CPPVariables> PrivateVariables;
};
//class test:public CPPFunctions,public CPPClass
//{
//    void p1(){
//        publicInt=0;
////        privateInt=0;
//      protectedInt=0;
//    }
//};
//class tw
//{
//    void t2()
//    {
//    test t;
//    t.publicInt=0;
//    //        privateInt=0;
////    t.protectedInt=0;
//    }
//};

#endif // TYPES_H
