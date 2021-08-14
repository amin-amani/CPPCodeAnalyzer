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
#include "Types.h"
class Parser
{
    QString _fileName;
    QByteArray _fileContent;
public:
    Parser();
    QStringList GetFunctionNames();
    Parser(QString fileName);
    void SetFileName(QString fileName);
    QStringList GetIncludes(QString content);
    QStringList GetBraces(QString input);
    QList<QPoint> GetParentBraces(QString input);
    QStringList GetLineComments(QString content);
    QStringList GetBlockComments(QString content);
    QList<CPPClass> GetAllClasses();
    QStringList GetIncludeGaurds(QString content);
    QStringList GetDefines(QString content);
    QString RemoveEmptyLines(QString content);
    QString GetClasses(QString contect);
    QList<CPPClass> GetClassSignature(QString content);
    CPPClass GetClassInheritances(QString content);
    QString ReplaceEndlineTolinuxFormat(QString content);
    QStringList GetClassesFromText(QString content);
};

#endif // PARSER_H
