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
QVector<QPoint> posPoints;
int index=0;
while (index>=0) {
index=input.indexOf("{",index);
if(index<0)break;
braceStarts.append(index);
index++;
}
//qDebug()<<"input="<<input;
index=0;
while (index>=0) {
index=input.indexOf("}",index);
if(index<0)break;

braceEnds.append(index);
index++;
}

for (int j=0;j<braceStarts.count();j++) {


int currentStartBrace=braceStarts[braceStarts.count()-j-1];
//qDebug()<<"bracestart["<<j<<"]="<<braceStarts[j];
for (int i=0;i<braceEnds.count();i++)
{
//qDebug()<<"braceEnd["<<i<<"]="<<braceEnds[i];
    if(currentStartBrace<braceEnds[i])
    {
        QPoint temp;

        temp.setX(currentStartBrace);
        temp.setY(braceEnds[i]);
        posPoints.append(temp);
        braceEnds[i]=-1;
        break;
    }
}
}


for (int i=0;i<posPoints.count();i++) {
    QString str=input.mid(posPoints[i].x(),posPoints[i].y()-posPoints[i].x()+1);
   // qDebug()<<"answer["<<i<<"]="<<str;
   result.append(str);
}

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

