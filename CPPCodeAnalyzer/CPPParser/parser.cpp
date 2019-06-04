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
QList<ParserObject> Parser::GetIncludes()
{
    QList<ParserObject> result;

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
                ParserObject temp;
                temp.Type=Include;
                temp.Body=fileLines[line];
                temp.Location.setX(startIndex);
                temp.Location.setY(i);

                result.append(temp);

                //result.append(fileLines[line]);
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
QList<ParserObject> Parser::GetLineComments()
{
    //QStringList result;
    QList<ParserObject> res;
    QList<QByteArray> fileLines=_fileContent.split('\n');
    for (int i=0;i<fileLines.count();i++) {
        int startIndex=fileLines[i].indexOf("//");
        if(startIndex<0)continue;
        ParserObject temp;
        temp.Body=fileLines[i].mid(startIndex,fileLines[i].count()-startIndex);
        temp.Type=Comment;
        temp.Location.setX(startIndex);
        temp.Location.setY(fileLines[i].count());
        res.append(temp);
        //result.append(fileLines[i].mid(startIndex,fileLines[i].count()-startIndex));

    }
    return  res;
}
//===============================================================================
QList<ParserObject> Parser::GetDefines()
{
    QList<ParserObject>result;
    //QStringList result;
    QList<QByteArray> fileLines=_fileContent.split('\n');
    for (int i=0;i<fileLines.count();i++) {
        int startIndex=fileLines[i].indexOf("#define ");
        if(startIndex<0)continue;
        ParserObject temp;
        temp.Type=Define;
        temp.Location.setX(startIndex);
        temp.Location.setY(fileLines[i].count());
        temp.Body=fileLines[i].mid(startIndex,fileLines[i].count()-startIndex);
        result.append(temp);
        //result.append(fileLines[i].mid(startIndex,fileLines[i].count()-startIndex));

    }
    return  result;
}
//===============================================================================
QList<ParserObject> Parser::GetBlockComments()
{
    // QStringList result;
    QList<ParserObject> res;
    int startInex=-1;
    QString comment="";
    for (int i=0;i<_fileContent.count()-1;i++)
    {
        if(_fileContent[i]=='/' && _fileContent[i+1]=='*' && startInex<0)startInex=i;
        if(_fileContent[i]=='*' && _fileContent[i+1]=='/' && startInex>=0 && comment.length()>3)
        {
            comment=comment+_fileContent[i]+_fileContent[i+1];
            // result.append(comment);
            ParserObject temp;
            temp.Location.setX(startInex);
            temp.Location.setY(i+1);
            temp.Type=Comment;
            temp.Body=comment;
            res.append(temp);
            startInex=-1;
            comment="";
        }
        if(startInex>=0)comment+=_fileContent[i];
    }
    return  res;
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
QString Parser::GetClassFromBrace(QPoint braceLocation,QByteArray text)
{
    QString result;
    int start=braceLocation.x();
    int count=0;
    while (start-->0) {
        result=text.mid(start,count);
        count++;
        if(result.contains("class "))break;
    }
    return RemoveTabsAndEnters( result);
}
//===============================================================================
QList<ParserObject> Parser::GetClassesSignatures(QByteArray text)
{
    QList<ParserObject> result;
    QList<QPoint> parentBraces=GetParentBraces(text);
    for(int i=0;i<parentBraces.count();i++)
    {
        QString temp= GetClassFromBrace(parentBraces[i],text);
        if(!temp.isEmpty()){
            ParserObject tempobj;
            tempobj.Type=Class;
            tempobj.Signature=temp;
            tempobj.Location=parentBraces[i];
            result.append(tempobj);

        }

    }
    return  result;
}
//===============================================================================
QList<ParserObject> Parser::GetFunctionSignatures(QByteArray text)
{
    //  if(_fileName.contains("GXDLMSMd5"))
    //        qDebug()<<"file";
    QList<ParserObject> result;
    //QStringList result;
    QList<QPoint> parentBraces=GetParentBraces(text);
    for(int i=0;i<parentBraces.count();i++)
    {
        QString temp= GetFunctionFromBrace(parentBraces[i],text);
        if(!temp.isEmpty())
        {    ParserObject tempobj;
            tempobj.Body=text.mid(parentBraces[i].x(),parentBraces[i].y()-parentBraces[i].x());
            tempobj.Type=Function;
            tempobj.Location.setX(0);
            tempobj.Location.setY(0);
            tempobj.Signature=temp;

            result.append(tempobj);


            //result.append(temp);
        }
    }
    return  result;
}
//===============================================================================
QByteArray Parser::RemoveParserObject(QByteArray data,QList<ParserObject> objectList)
{
    foreach (ParserObject obj, objectList) {
        data=data.replace(obj.Body.toLatin1(),"");
    }
    return  data;
}
//===============================================================================
QByteArray Parser::RemoveBlockComments(QByteArray data)
{
    QList<ParserObject> bcomments= GetBlockComments();
    foreach (ParserObject bcomment, bcomments) {
        data=data.replace(bcomment.Body.toLatin1(),"");
    }
    return  data;
}
//===============================================================================
QByteArray Parser::RemoveLineComments(QByteArray data)
{
    QList<ParserObject> comments= GetLineComments();
    foreach (ParserObject commnet, comments) {
        data=data.replace(commnet.Body,"");
    }
    return  data;
}
//===============================================================================
QByteArray Parser::RemoveDefines(QByteArray data)
{

    QList<ParserObject> Defines= GetDefines();
    foreach (ParserObject define, Defines) {
        data=data.replace(define.Body.toLatin1(),"");
    }
    return  data;
}
//===============================================================================
QByteArray Parser::RemoveIncludes(QByteArray data)
{
    QList<ParserObject>  Includes= GetIncludes();
    foreach (ParserObject include, Includes) {
        data=data.replace(include.Body,"");
    }
    return  data;
}
//===============================================================================
QStringList Parser::GetFunctionNames()
{
    QList<ParserObject> res;
    QStringList result;
    QByteArray text;
    if(_fileContent.isNull())return result;
    if(_fileContent.isEmpty())return result;
    text=_fileContent;
    QList<ParserObject> blockComments=GetBlockComments();
    res.append(blockComments);
    text=RemoveParserObject(text,blockComments);

    QList<ParserObject> lineComments=GetLineComments();
    res.append(blockComments);
    text=RemoveParserObject(text,lineComments);

    QList<ParserObject> defines=GetDefines();
    res.append(defines);
    text=RemoveParserObject(text,defines);


    QList<ParserObject> includes=GetIncludes();
    res.append(includes);
    text=RemoveParserObject(text,includes);
QList<ParserObject> funcs=GetFunctionSignatures(text);

foreach(ParserObject obj,funcs)
    result.append(obj.Signature);
    //result=
    return  result;
}
//===============================================================================
QList<ParserObject> Parser::GetClassesNames()
{
    QList<ParserObject> result;
    QByteArray text;
    if(_fileContent.isNull())return result;
    if(_fileContent.isEmpty())return result;
    text=_fileContent;

    QList<ParserObject> blockComments=GetBlockComments();
    result.append(blockComments);
    text=RemoveParserObject(text,blockComments);

    QList<ParserObject> lineComments=GetLineComments();
    result.append(blockComments);
    text=RemoveParserObject(text,lineComments);

    QList<ParserObject> defines=GetDefines();
    result.append(defines);
    text=RemoveParserObject(text,defines);

    QList<ParserObject> includes=GetIncludes();
    result.append(includes);
    text=RemoveParserObject(text,includes);

    result=GetClassesSignatures(text);
    return  result;
}
//===============================================================================
QList<ParserObject> Parser::Start()
{
    QList<ParserObject> result;
    QByteArray text;
    if(_fileContent.isNull())return result;
    if(_fileContent.isEmpty())return result;
    text=_fileContent;

    QList<ParserObject> blockComments=GetBlockComments();
    result.append(blockComments);
    text=RemoveParserObject(text,blockComments);

    QList<ParserObject> lineComments=GetLineComments();
    result.append(blockComments);
    text=RemoveParserObject(text,lineComments);

    QList<ParserObject> defines=GetDefines();
    result.append(defines);
    text=RemoveParserObject(text,defines);

    QList<ParserObject> includes=GetIncludes();
    result.append(includes);
    text=RemoveParserObject(text,includes);

    result=GetClassesSignatures(text);
    QList<ParserObject> funcs=GetFunctionSignatures(text);
    result.append(funcs);
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
