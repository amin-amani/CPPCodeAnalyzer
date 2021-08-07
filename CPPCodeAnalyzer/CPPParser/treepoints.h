#ifndef TREEPOINTS_H
#define TREEPOINTS_H
#include <QVector>
#include <algorithm>
#include <QList>
class CodeLocation
{

public:
    int Start;
    int End;
    CodeLocation(){}
    CodeLocation(int start,int end):Start(start),End(end)
    {

    }

};

class CodeTreeNode
{
public:
    CodeLocation Node;

   QVector<CodeTreeNode> Childs;
   CodeTreeNode(){}
   CodeTreeNode(CodeLocation node):Node(node){}
   CodeTreeNode(CodeLocation node, QVector<CodeTreeNode>childs):Node(node),Childs(childs)
   {

   }
};


class TreePoints
{

    static bool FirstTreeLessThan(CodeTreeNode first,CodeTreeNode second);
    static bool SecondTreeLessThan(CodeTreeNode first, CodeTreeNode second);
public:
    QList<CodeLocation> InputCodeLocations;
    TreePoints();
    void AddPoint(int start,int end);
    CodeTreeNode GetTree();
    void SortCodePhrasesFirsIsSmaller();
    void SortCodePhrasesFirsIsGreater();



    bool FirstIsPartOfSecond(CodeTreeNode first, CodeTreeNode second);
};




#endif // TREEPOINTS_H
