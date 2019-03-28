#include "parser.h"

Parser::Parser()
{

}
Parser::Parser(QString fileName)
{
   _fileName=fileName;
   QFile file;
   file.setFileName(_fileName);
if(!file.open(QFile::ReadOnly))
    return;
_fileContent= file.readAll();

file.close();

}
void Parser::SetFileName(QString fileName)
{
   _fileName=fileName;
   QFile file;
   file.setFileName(_fileName);
if(!file.open(QFile::ReadOnly))
    return;
_fileContent= file.readAll();



}
QStringList Parser::GetIncludes()
{

    QRegExp reg("^#include.*>");
    reg.indexIn(_fileContent);
    return reg.capturedTexts();


}
QStringList Parser::GetBraces(QString input)
{
QStringList result;
if(input.isEmpty())return result;


QVector<int> braceStarts,braceEnds;
int index=0;
while (index>=0) {
index=input.indexOf("{",index);
if(index<0)break;
braceStarts.append(index);
index++;
}

index=0;
while (index>=0) {
index=input.indexOf("}",index);
if(index<0)break;
braceEnds.append(index);
index++;
}

for (int i=0;i<braceStarts.count();i++) {
   result.append(input.mid(braceStarts[i]+1,braceEnds[i]-braceStarts[i]-1));
}
//while (true) {
//    int startIndex=input.indexOf("{",lastIndex++);
//    int endIndex=input.indexOf("}",startIndex+1);
//    result.append(input.mid(startIndex+1,endIndex-startIndex-1));
//    if(startIndex<0)break;
//}

return  result;
}
QStringList Parser::GetFunctionName()
{
QStringList result;
QString text;

if(_fileContent.isNull())return result;
if(_fileContent.isEmpty())return result;
text=_fileContent;

QStringList Includes= GetIncludes();
foreach (QString include, Includes) {
text.replace(include,"");
}


//regex for{}-> \{\s*}
//between two()-> \((.*?)\)

//result.append("amin");
return  result;
}

