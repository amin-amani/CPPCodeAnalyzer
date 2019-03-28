#include <QtTest>
#include <QStringList>
#include "../CPPParser/parser.h"
// add necessary includes here
//======================================================================

class ParsTest : public QObject
{
    Q_OBJECT
    Parser parser;


public:
    ParsTest();
    ~ParsTest();

    void CheckIfEmptyStringReturnHasNoFunction();
    void CheckIfNullReturnHasNoFunction();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_SimpleMainAndInclude();
    void test_BracesParsWithEmptyAndNull();
    void test_BracesPraseSimplest();
    void test_BracesPraseMultiple();
    void test_BracesPraseNested();
};
//======================================================================
ParsTest::ParsTest()
{


}
//======================================================================
void ParsTest::CheckIfNullReturnHasNoFunction()
{
QStringList result=parser.GetFunctionName();
QVERIFY2(result.length()==0,"Null doesnt return empty");
}
//======================================================================
void ParsTest::CheckIfEmptyStringReturnHasNoFunction()
{

QStringList result=parser.GetFunctionName();
QVERIFY2(result.length()==0,"empty string doesnt return empty");
}
//======================================================================
void ParsTest::test_SimpleMainAndInclude()
{
    return;
parser.SetFileName("../../TestModels/SimpleMain.cpp");
QStringList result=parser.GetFunctionName();
QVERIFY2(result.length()==1,"function not found");
if(result.length()<1)return;
//qDebug()<<result.at(0);
QVERIFY2(result.at(0)=="main","invalid name");
}

//======================================================================
ParsTest::~ParsTest()
{

}
//======================================================================
void ParsTest::initTestCase()
{

}
//======================================================================
void ParsTest::cleanupTestCase()
{

}
//======================================================================
void ParsTest::test_BracesParsWithEmptyAndNull()
{
QStringList bracesList= parser.GetBraces("");
QVERIFY2(bracesList.count()==0,"empty return must be no braces");
 bracesList= parser.GetBraces(NULL);
 QVERIFY2(bracesList.count()==0,"null return must be no braces");

}
//======================================================================
void ParsTest::test_BracesPraseSimplest()
{
    QStringList bracesList= parser.GetBraces("{in brace}");

  QVERIFY2(bracesList.count()==1,"no answer");

//  if(bracesList.count()>0)qDebug()<<"==>"<<bracesList[0];
  QVERIFY2(bracesList[0]=="{in brace}","null return must be no braces");
}
//======================================================================
void ParsTest::test_BracesPraseMultiple()
{
    QStringList bracesList= parser.GetBraces("{in brace1}\n{in brace2}");
    QVERIFY2(bracesList[0]=="{in brace2}","not brace2");
    QVERIFY2(bracesList[1]=="{in brace1}","not brace1");

}
//======================================================================
void ParsTest::test_BracesPraseNested()
{
    QStringList bracesList= parser.GetBraces("{in brace1{in brace2}}");
  QVERIFY2(bracesList[1]=="{in brace1{in brace2}}","outside brace error");
  QVERIFY2(bracesList[0]=="{in brace2}","inside brace error");
}
//======================================================================

QTEST_APPLESS_MAIN(ParsTest)

#include "tst_parstest.moc"
