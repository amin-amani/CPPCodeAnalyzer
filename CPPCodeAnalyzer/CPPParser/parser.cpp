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



}
//===============================================================================
QStringList Parser::GetIncludes()
{
    QStringList result;
    QList<QByteArray> fileLines=_fileContent.split('\n');

    for (int line=0;line<fileLines.count();line++) {
        QString currentLine=QString::fromLatin1(fileLines[line]).trimmed().replace(" ","");

        int startIndex= currentLine.indexOf("#include",0);
        if(startIndex<0)continue;
        for(int i=startIndex;i<currentLine.length();i++)
        {
            if(currentLine[i]=='>')
            {
                //result.append(currentLine.mid(startIndex,i-startIndex+1));
                result.append(fileLines[line]);
            }

        }

    }
    return  result;
}
//===============================================================================
QStringList Parser::GetIncludeGaurds(QString content)
{
    QStringList result;
    QStringList fileLines=content.split('\n');

    for (int line=0;line<fileLines.count();line++) {
        QString currentLine=fileLines[line].trimmed();

        int idx1= currentLine.indexOf("#ifndef",0);
        int idx2= currentLine.indexOf("#endif",0);
        if(idx1<0 && idx2<0)continue;

        result.append(currentLine);
    }
    return  result;
}
//===============================================================================
QStringList Parser::GetDefines()
{
    QStringList result;
    QList<QByteArray> fileLines=_fileContent.split('\n');

    for (int line=0;line<fileLines.count();line++) {
        QString currentLine=QString::fromLatin1(fileLines[line]).trimmed();

        int idx1= currentLine.indexOf("#define",0);
        if(idx1<0)continue;
        result.append(currentLine);
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
QStringList Parser::GetBlockComments()
{
    QStringList result;
    int startInex=-1;
    QString comment="";
    for (int i=0;i<_fileContent.count()-1;i++)
    {


        if(_fileContent[i]=='/' && _fileContent[i+1]=='*' && startInex<0)
        {
            startInex=i;



        }
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

QString Parser::RemoveEmptyLines(QString content)
{
    QStringList fileLines=content.split('\n');
    QString result;
    foreach(QString line ,fileLines)
    {
        if(line.isEmpty())continue ;
        result+=line;


    }
    return  result;


}
//===============================================================================

CPPClass Parser::GetClassInheritances(QString content)
{
    CPPClass result;
    if(!content.contains("class "))
        return result;

        content=content.split("class ")[1];
        content=content.split("{")[0];
        result.Name=content.split(":")[0].trimmed();
    if(!content.contains(":"))
    {
        return  result;
    }


    QString inheritances=content.split(":")[1];

        foreach(QString item, inheritances.split(","))
        {
            if(item.contains("public "))
            {
                result.PulicParents.append(item.split("public ")[1].trimmed());
            }
            if(item.contains("private "))
            {
                result.PrivateParents.append(item.split("private ")[1].trimmed());
            }
            if(item.contains("protected "))
            {

                result.ProtectedParents.append(item.split("protected ")[1].trimmed());
            }
            if(!item.contains("public ") && !item.contains("protcted ") && !item.contains("private "))
            {

                 result.PrivateParents.append(item.trimmed());
            }
        }



    return result;
}
//===============================================================================

 QList <CPPClass> Parser::GetClassSignature(QString content)
{

    CPPClass result;
     QList <CPPClass> resultList;

    if(content.isNull())return  resultList;
    if(content.isEmpty())return  resultList;



     QList<QPoint> parentBraces=GetParentBraces(content);


     if(parentBraces.count()<1)
     {
         CPPClass signatureResult=GetClassInheritances(content);
         result.Name=signatureResult.Name;
         result.PulicParents=signatureResult.PulicParents;
         result.PrivateParents=signatureResult.PrivateParents;
         result.ProtectedParents=signatureResult.ProtectedParents;
         resultList.append(result);
         return resultList;
     }

         CPPClass signatureResult=GetClassInheritances(content.mid(0,parentBraces[0].y()));
         result.Name=signatureResult.Name;
         result.PulicParents=signatureResult.PulicParents;
         result.PrivateParents=signatureResult.PrivateParents;
         result.ProtectedParents=signatureResult.ProtectedParents;
         resultList.append(result);

     for(int i=1;i< parentBraces.count() ;i++)
     {

         CPPClass signatureResult=GetClassInheritances(content.mid(parentBraces[i-1].y(),parentBraces[i].x()));
         result.Name=signatureResult.Name;
         result.PulicParents=signatureResult.PulicParents;
         result.PrivateParents=signatureResult.PrivateParents;
         result.ProtectedParents=signatureResult.ProtectedParents;
         resultList.append(result);

     }






    return resultList;
}
//===============================================================================

QString Parser::GetClasses(QString contect)
{



    QStringList classtext= contect.split("class ");
    if(classtext.length()>0)
    {
        QStringList classDef= classtext[1].split("{");
        if(classDef.length()>0)
        {
            qDebug()<<classDef[0];
        }



    }
    return  "";
}
//===============================================================================
QList<CPPClass> Parser::GetAllClasses()
{
    QList<CPPClass> result;
    QString text;

    if(_fileContent.isNull())return result;
    if(_fileContent.isEmpty())return result;
    text=_fileContent;

    QStringList bcomments= GetBlockComments();

    foreach (QString bcomment, bcomments) {
        text=text.replace(bcomment,"");

    }

    QStringList comments= GetLineComments();
    foreach (QString commnet, comments) {
        text=text.replace(commnet,"");
    }

    QStringList Includes= GetIncludes();

    foreach (QString include, Includes) {
        text=text.replace(include,"");
    }
    QStringList gaurds= GetIncludeGaurds(text);

    foreach (QString gaurd, gaurds)
    {
        text=text.replace(gaurd,"");
    }
    QStringList defines= GetDefines();
    foreach (QString define, defines)
    {

        text=text.replace(define,"");
    }
    text=RemoveEmptyLines(text);
QFile out("out.txt");
out.open(QFile::ReadWrite);
out.write(text.toLatin1());
out.close();

//qDebug()<<"==========================="<<text;
     QList<CPPClass> cs= GetClassSignature(text);

     return  cs;
}
//===============================================================================
QStringList Parser::GetFunctionNames()
{
    QStringList result;
    QString text;

    if(_fileContent.isNull())return result;
    if(_fileContent.isEmpty())return result;
    text=_fileContent;

    QStringList bcomments= GetBlockComments();
    foreach (QString bcomment, bcomments) {
        text=text.replace(bcomment,"");
    }

    QStringList comments= GetLineComments();
    foreach (QString commnet, comments) {
        text=text.replace(commnet,"");
    }

    QStringList Includes= GetIncludes();
    foreach (QString include, Includes) {
        text=text.replace(include,"");
    }
    QList<QPoint> parentBraces=GetParentBraces(text);
    QStringList bracesTexts;
    for (int i=0;i<parentBraces.count();i++) {
        bracesTexts.append(text.mid(parentBraces[i].x(),parentBraces[i].y()-parentBraces[i].x()+1));
    }

    foreach (QString brace, bracesTexts) {
        text.replace(brace,"{}");
    }
    QStringList ans;
    ans.append(  text.split("{}"));
    //regex for{}-> \{\s*}
    //between two()-> \((.*?)\)
    for (int i=0;i<result.count();i++) {
        ans[i]=ans[i].trimmed();
        if(ans[i].contains("\n"))ans[i]="";


    }

    for (int i=0;i<ans.count();i++) {
        if(ans.isEmpty())continue;
        QString str=ans[i].trimmed();
        if(!str.isEmpty())
            result.append(str);

    }

    //result.append(text);
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
