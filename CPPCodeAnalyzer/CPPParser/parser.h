#ifndef PARSER_H
#define PARSER_H
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QRegExp>
#include <QFile>
class Parser
{
    QString _fileName;
    QByteArray _fileContent;
public:
    Parser();
    QStringList GetFunctionName();
    Parser(QString fileName);
    void SetFileName(QString fileName);
    QStringList GetIncludes();
    QStringList GetBraces(QString input);
};

#endif // PARSER_H
