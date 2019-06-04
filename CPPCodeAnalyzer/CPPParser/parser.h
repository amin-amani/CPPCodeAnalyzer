#ifndef PARSER_H
#define PARSER_H
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QRegExp>
#include <QByteArray>
#include <QRegularExpression>
#include <QFile>
#include <QPoint>
#include "objectfactory.h"

class Parser
{
    QString _fileName;
    QByteArray _fileContent;
public:
    friend class TestCPPParse;
    Parser();
    Parser(QString fileName);
    void SetFileName(QString fileName);
    QList<ParserObject> GetIncludes();
    QStringList GetBraces(QString input);
    QList<QPoint> GetParentBraces(QString input);
    QList<ParserObject> GetLineComments();
    //QList<QPoint> GetBlockComments();
    QList<ParserObject> GetDefines();
    QList<ParserObject> GetBlockComments();
    QList<ParserObject> GetFunctionSignatures(QByteArray text);
    QStringList GetFunctionNames();
    QList<ParserObject> GetClassesNames();
    QList<ParserObject> GetClassesSignatures(QByteArray text);
    QString GetClassFromBrace(QPoint braceLocation, QByteArray text);
    QList<ParserObject> Start();
    QByteArray RemoveParserObject(QByteArray input, QList<ParserObject> objectList);
private slots:

private:

    QString RemoveTabsAndEnters(QString text);
    QString GetFunctionFromBrace(QPoint braceLocation, QByteArray text);
    QByteArray RemoveBlockComments(QByteArray data);
    QByteArray RemoveLineComments(QByteArray data);
    QByteArray RemoveDefines(QByteArray data);
    QByteArray RemoveIncludes(QByteArray data);
};

#endif // PARSER_H
