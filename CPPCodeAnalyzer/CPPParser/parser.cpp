#include "parser.h"


//===============================================================================
Parser::Parser()
{

}
//===============================================================================
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
//===============================================================================
void Parser::SetFileName(QString fileName)
{
    _fileName=fileName;
    QFile file;
    file.setFileName(_fileName);
    if(!file.open(QFile::ReadOnly))
     return;
    _fileContent= file.readAll();
    file.close();
}
//===============================================================================
QStringList Parser::GetIncludes()
{
    QStringList result;
    QList<QByteArray> fileLines=_fileContent.split('\n');

    int sgncount=0;
    for (int line=0;line<fileLines.count();line++) {
        QString currentLine=QString::fromLatin1(fileLines[line]).trimmed().replace(" ","");

        int startIndex= currentLine.indexOf("#include",0);
        if(startIndex<0)continue;

        for(int i=startIndex;i<currentLine.length();i++)
        {
            if(currentLine[i]=='"')sgncount++;
            if(currentLine[i]=='>' || sgncount==2)
            {

                result.append(fileLines[line]);
                sgncount=0;
            }
        }
    }
    return  result;
}
//===============================================================================
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

//===============================================================================
QStringList Parser::GetLineComments()
{
    QStringList result;
    QList<QByteArray> fileLines=_fileContent.split('\n');
    for (int i=0;i<fileLines.count();i++) {
        int startIndex=fileLines[i].indexOf("//");
        if(startIndex<0)continue;
        result.append(fileLines[i].mid(startIndex,fileLines[i].count()-startIndex));

    }
    return  result;
}
//===============================================================================
QStringList Parser::GetDefines()
{
    QStringList result;
    QList<QByteArray> fileLines=_fileContent.split('\n');
    for (int i=0;i<fileLines.count();i++) {
        int startIndex=fileLines[i].indexOf("#define ");
        if(startIndex<0)continue;
        result.append(fileLines[i].mid(startIndex,fileLines[i].count()-startIndex));

    }
    return  result;
}
//===============================================================================
QStringList Parser::GetBlockComments()
{
    QStringList result;
    int startInex=-1;
    QString comment="";
    for (int i=0;i<_fileContent.count()-1;i++)
    {
        if(_fileContent[i]=='/' && _fileContent[i+1]=='*' && startInex<0)startInex=i;
        if(_fileContent[i]=='*' && _fileContent[i+1]=='/' && startInex>=0 && comment.length()>3)
        {
            comment=comment+_fileContent[i]+_fileContent[i+1];
            result.append(comment);
            startInex=-1;
            comment="";
        }
        if(startInex>=0)comment+=_fileContent[i];
    }
    return  result;
}
//===============================================================================
QString Parser::RemoveTabsAndEnters(QString text)
{
    return text.replace("\t","").replace("\n","").replace("\r","");

}
//===============================================================================
QString Parser::GetFunctionFromBrace(QPoint braceLocation,QByteArray text)
{
    QString result;
    int endOfBrace=braceLocation.y();
    while(endOfBrace<text.count())
    {
        endOfBrace++;
        char ch=text[endOfBrace];
        if(ch==';')return result;
        if(ch=='\n')  break;
    }
    int end=braceLocation.x();
    int start=end;
    int parenthesesCount=0;
    while(start-->1)
    {
        char ch=text[start];
        if(ch==')' || ch=='('){parenthesesCount++;}
        if(ch=='\n' && parenthesesCount==2){
            result= text.mid(start,end-start);
            break;
        }
    }
    return RemoveTabsAndEnters( result);
}
//===============================================================================
QStringList Parser::GetFunctionSignatures(QByteArray text)
{
    if(_fileName.contains("GXDLMSMd5"))
        qDebug()<<"file";
    QStringList result;
    QList<QPoint> parentBraces=GetParentBraces(text);
    for(int i=0;i<parentBraces.count();i++)
    {
        QString temp= GetFunctionFromBrace(parentBraces[i],text);
        if(!temp.isEmpty())
        result.append(temp);
    }
    return  result;
}
//===============================================================================
QByteArray Parser::RemoveBlockComments(QByteArray data)
{
    QStringList bcomments= GetBlockComments();
    foreach (QString bcomment, bcomments) {
        data=data.replace(bcomment.toLatin1(),"");
    }
    return  data;
}
//===============================================================================
QByteArray Parser::RemoveLineComments(QByteArray data)
{
    QStringList comments= GetLineComments();
    foreach (QString commnet, comments) {
        data=data.replace(commnet,"");
    }
    return  data;
}
//===============================================================================
QByteArray Parser::RemoveDefines(QByteArray data)
{
    QStringList Defines= GetDefines();
    foreach (QString define, Defines) {
        data=data.replace(define.toLatin1(),"");
    }
    return  data;
}
//===============================================================================
QByteArray Parser::RemoveIncludes(QByteArray data)
{
    QStringList Includes= GetIncludes();
    foreach (QString include, Includes) {
        data=data.replace(include,"");
    }
    return  data;
}
//===============================================================================
QStringList Parser::GetFunctionNames()
{
    QStringList result;
    QByteArray text;
    if(_fileContent.isNull())return result;
    if(_fileContent.isEmpty())return result;
    text=_fileContent;
    text=RemoveBlockComments(text);
    text=RemoveLineComments(text);
    text=RemoveDefines(text);
    text=RemoveIncludes(text);
    result=GetFunctionSignatures(text);
    return  result;
}
//===============================================================================
QList<QPoint> Parser::GetParentBraces(QString input)
{
    QList< QPoint> result;
    int openCount=-1;
    QPoint point;
    for (int i=0;i<input.count();i++)
    {

        if(input[i]=='{' )
        {

            if(openCount<0){
                openCount++;
                point.setX(i);
            }
            openCount++;

        }
        if(input[i]=='}')
        {
            point.setY(i);
            openCount--;
        }
        if(openCount==0){

            result.append(point);
            openCount--;
        }

    }

    return  result;

}
