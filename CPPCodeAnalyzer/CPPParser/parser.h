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

    Parser(QString fileName);
    void SetFileName(QString fileName);
    QStringList GetFunctionNames();
    QStringList GetIncludes();
    QStringList GetBraces(QString input);
    QList<QPoint> GetParentBraces(QString input);
    QStringList GetLineComments();
    //QList<QPoint> GetBlockComments();
    QStringList GetDefines();
    QStringList GetBlockComments();
    QStringList GetFunctionSignatures(QByteArray text);

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
