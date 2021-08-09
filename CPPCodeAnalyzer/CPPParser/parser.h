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
class Parser
{
    QString _fileName;
    QByteArray _fileContent;
public:
    Parser();
    QStringList GetFunctionNames();
    Parser(QString fileName);
    void SetFileName(QString fileName);
    QStringList GetIncludes();
    QStringList GetBraces(QString input);
    QList<QPoint> GetParentBraces(QString input);
    QStringList GetLineComments();
    QStringList GetBlockComments();
    QStringList GetClassNames();
    QStringList GetIncludeGaurds(QString content);
    QStringList GetDefines();
    QString RemoveEmptyLines(QString content);
    QString GetClasses(QString contect);
    QStringList GetClassSignature(QString content);
};

#endif // PARSER_H
