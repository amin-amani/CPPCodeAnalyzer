#include <QtTest>
#include <QStringList>
#include "../../CPPParser/parser.h"
// add necessary includes here

class TestCPPParse : public QObject
{
    Q_OBJECT

    QStringList GetTestFunctionResultsFromFile(QString fileName);
public:
    TestCPPParse();
    ~TestCPPParse();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

    void CheckIfNullReturnHasNoFunction();
    void CheckIfEmptyStringReturnHasNoFunction();
    void test_MainAndFunction();
    void test_CanCheckClass();
    void test_SimpleMainAndInclude();
    void test_MainAndFunctionAnd2Includes();

    void test_BracesParsWithEmptyAndNull();
    void test_BracesPraseSimplest();
    void test_BracesPraseMultiple();
    void test_BracesPraseNested();
    void test_GetParentBraces();

    void test_GetFunctionsWithComments();
};

TestCPPParse::TestCPPParse()
{

}

TestCPPParse::~TestCPPParse()
{

}

void TestCPPParse::initTestCase()
{

}

void TestCPPParse::cleanupTestCase()
{

}

void TestCPPParse::test_case1()
{

}
//======================================================================
void TestCPPParse::CheckIfNullReturnHasNoFunction()
{
Parser parser;
QStringList result=parser.GetFunctionNames();
QVERIFY2(result.length()==0,"Null doesnt return empty");
}
//======================================================================
void TestCPPParse::CheckIfEmptyStringReturnHasNoFunction()
{
  Parser parser;
QStringList result=parser.GetFunctionNames();
QVERIFY2(result.length()==0,"empty string doesnt return empty");
}
//======================================================================
QStringList TestCPPParse::GetTestFunctionResultsFromFile(QString fileName)
{
    QStringList result;
    if(!QFile::exists(fileName)){qDebug()<<"test file does not exits:"<<fileName;return result;}
    QFile resultFile(fileName);
    resultFile.open(QFile::ReadOnly);
    QByteArray content=resultFile.readAll();
    resultFile.close();
    return  QString::fromLatin1(content).split('\n');
}

//======================================================================
void TestCPPParse::test_SimpleMainAndInclude()
{

Parser parser;
parser.SetFileName("../../../TestModels/SimpleMain.cpp");
QStringList preDefinedResults=GetTestFunctionResultsFromFile("../../../TestModels/SimpleMain.cpp.res");
QStringList testResults=parser.GetFunctionNames();
qDebug()<<"res="<<testResults.at(0)<<" ans="<<preDefinedResults;
QVERIFY(preDefinedResults==testResults);
}


void TestCPPParse::test_MainAndFunction()
{
    Parser parser;
    parser.SetFileName("../../../TestModels/MainAndOneFunction.cpp");
    QStringList preDefinedResults=GetTestFunctionResultsFromFile("../../../TestModels/MainAndOneFunction.cpp.res");
    QStringList testResults=parser.GetFunctionNames();
    qDebug()<<"res="<<testResults.at(0)<<" ans="<<preDefinedResults.at(0);
    QVERIFY(preDefinedResults==testResults);
}

void TestCPPParse::test_CanCheckClass()
{

    Parser parser;
    parser.SetFileName("../../../TestModels/SimpleClass.cpp");

    qDebug()<<parser.GetClassNames();

    QVERIFY(1==2);
}

void TestCPPParse::test_MainAndFunctionAnd2Includes()
{
    Parser parser;
    parser.SetFileName("../../../TestModels/MainAndOneFunction2Includes.cpp");
    QStringList preDefinedResults=GetTestFunctionResultsFromFile("../../../TestModels/MainAndOneFunction2Includes.cpp.res");
    QStringList testResults=parser.GetFunctionNames();
    qDebug()<<"res="<<testResults.at(0)<<" ans="<<preDefinedResults.at(0);
    qDebug()<<"res="<<testResults.at(1)<<" ans="<<preDefinedResults.at(1);
    QVERIFY(preDefinedResults==testResults);
}

void TestCPPParse::test_GetFunctionsWithComments()
{
    Parser parser;
    parser.SetFileName("../../../TestModels/Comments.cpp");
    QStringList preDefinedResults=GetTestFunctionResultsFromFile("../../../TestModels/Comments.cpp.res");
    QStringList testResults=parser.GetFunctionNames();
    qDebug()<<"res="<<testResults.at(0)<<" ans="<<preDefinedResults.at(0);
    qDebug()<<"res="<<testResults.at(1)<<" ans="<<preDefinedResults.at(1);
    QVERIFY(preDefinedResults==testResults);
}


void TestCPPParse::test_BracesParsWithEmptyAndNull()
{  Parser parser;
    QStringList bracesList= parser.GetBraces("");
    QVERIFY2(bracesList.count()==0,"empty return must be no braces");
     bracesList= parser.GetBraces(NULL);
     QVERIFY2(bracesList.count()==0,"null return must be no braces");
}

void TestCPPParse::test_BracesPraseSimplest()
{  Parser parser;
    QStringList bracesList= parser.GetBraces("{in brace}");

  QVERIFY2(bracesList.count()==1,"no answer");

//  if(bracesList.count()>0)qDebug()<<"==>"<<bracesList[0];
  QVERIFY2(bracesList[0]=="{in brace}","null return must be no braces");
}

void TestCPPParse::test_BracesPraseMultiple()
{  Parser parser;
    QStringList bracesList= parser.GetBraces("{in brace1}\n{in brace2}");
    QVERIFY2(bracesList[0]=="{in brace2}","not brace2");
    QVERIFY2(bracesList[1]=="{in brace1}","not brace1");
}

void TestCPPParse::test_BracesPraseNested()
{  Parser parser;
    QStringList bracesList= parser.GetBraces("{in brace1{in brace2}}");
  QVERIFY2(bracesList[1]=="{in brace1{in brace2}}","outside brace error");
  QVERIFY2(bracesList[0]=="{in brace2}","inside brace error");

}

void TestCPPParse::test_GetParentBraces()
{
  Parser parser;
    QList<QPoint> braces=parser.GetParentBraces(NULL);
    QVERIFY(braces.length()==0);

    braces=parser.GetParentBraces("");
    QVERIFY(braces.length()==0);

     braces=parser.GetParentBraces("{hello}");
   QVERIFY(braces.length()>0);
   QVERIFY(braces[0].x()==0 && braces[0].y()==6 );

    braces=parser.GetParentBraces("q{myworld{hello}g}r");
    QVERIFY2(braces.length()>0,"step2 len");
    QVERIFY2(braces[0].x()==1 && braces[0].y()==17 ,"step2 error");

    braces=parser.GetParentBraces("q{myworld{hello}g}r{1234}%");
    QVERIFY2(braces.length()==2,"step3 len");
    QVERIFY2(braces[0].x()==1 && braces[0].y()==17 ,"step2 error");
    QVERIFY2(braces[1].x()==19 && braces[1].y()==24 ,"step3 error");

    braces=parser.GetParentBraces("q{{myworld{hello}g}r{1234}%");

    QVERIFY2(braces.length()==0,"step4 len");

}

QTEST_APPLESS_MAIN(TestCPPParse)

#include "tst_testcppparse.moc"
