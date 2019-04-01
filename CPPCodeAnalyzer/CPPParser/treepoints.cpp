#include "treepoints.h"
#include <QtAlgorithms>
//============================================================================
//static bool TreePoints::FirstTreeLessThan(CodeTreeNode first, CodeTreeNode second)
//{
//    if((first.Node.End-first.Node.Start)>(second.Node.End-second.Node.Start))return true;
//    return  false;
//}
bool TreePoints::FirstIsPartOfSecond(CodeTreeNode first, CodeTreeNode second){
     if(first.Node.Start>second.Node.Start && first.Node.End<second.Node.End )
         return  true;
     return false;

}
bool TreePoints::FirstTreeLessThan(CodeTreeNode first, CodeTreeNode second){
    if((first.Node.End-first.Node.Start)>(second.Node.End-second.Node.Start))return true;
    return  false;


}
bool TreePoints::SecondTreeLessThan(CodeTreeNode first, CodeTreeNode second){
    if((first.Node.End-first.Node.Start)<(second.Node.End-second.Node.Start))return true;
    return  false;


}
TreePoints::TreePoints()
{

}
//============================================================================
void TreePoints::AddPoint(int start, int end)
{
    InputCodeLocations.append(CodeLocation(start,end));
}
//============================================================================
CodeTreeNode TreePoints::GetTree()
{
CodeTreeNode result;
QVector<CodeTreeNode> nodePool;
 QVector<CodeLocation> tempChilds;
if(InputCodeLocations.count()<2)
{
    result.Node=InputCodeLocations[0];
    return  result;
}

SortCodePhrasesFirsIsGreater();

tempChilds.append(CodeLocation(InputCodeLocations[0]));

for (int i=0;i<InputCodeLocations.count();i++)
{
  nodePool.append(CodeTreeNode(InputCodeLocations[i]));

}
for(int j=0;j<nodePool.count();j++){
int count=nodePool.count()-1;
while (count-->0) {
if(FirstIsPartOfSecond(nodePool[j+count+1].Node,nodePool[j].Node))
nodePool[j].Childs.append(nodePool[j+count+ 1]);
nodePool.removeAt(j+count+1);
}
}//j
int k=0;
k++;

//if(FirstIsPartOfSecond(InputCodeLocations[0],InputCodeLocations[1]))
//{
//    result.Node=InputCodeLocations[1];
//    result.Childs=tempChilds;

//}

//for (int i=0;i<InputCodePhrases.count();i++) {
//CodePhrase node=CodePhrase(InputCodePhrases[0].Start,InputCodePhrases[0].End);
//}


//result.Node=node;
return  result;
}
//============================================================================

void TreePoints::SortCodePhrasesFirsIsSmaller()
{
    std::sort(InputCodeLocations.begin(),InputCodeLocations.end(),SecondTreeLessThan);

}
//============================================================================
void TreePoints::SortCodePhrasesFirsIsGreater()
{
    std::sort(InputCodeLocations.begin(),InputCodeLocations.end(),FirstTreeLessThan);

}

//============================================================================
