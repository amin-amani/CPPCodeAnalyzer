#include <QtTest>
#include <QVector>
#include "../../CPPParser/treepoints.h"


// add necessary includes here

class TestTreePoints : public QObject
{
    Q_OBJECT
public:
    TestTreePoints();
    ~TestTreePoints();
    void test_AddTwoPoints();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_AddOnlyOnePoint();



    void test_AddThreePoints();
};

TestTreePoints::TestTreePoints()
{

}

TestTreePoints::~TestTreePoints()
{

}

void TestTreePoints::initTestCase()
{

}

void TestTreePoints::cleanupTestCase()
{

}


void TestTreePoints::test_AddOnlyOnePoint()
{
    TreePoints TreePoint;


TreePoint.AddPoint(1,2);
//TreePoint.AddPoint(5,6);
CodeTreeNode t= TreePoint.GetTree();
QVERIFY(t.Node.Start==1 && t.Node.End==2);
}

void TestTreePoints::test_AddTwoPoints()
{
    TreePoints TreePoint;

TreePoint.AddPoint(3,5);
TreePoint.AddPoint(1,6);

CodeTreeNode t= TreePoint.GetTree();
//QVERIFY(t.Node.Start==1 && t.Node.End==6);


//QVERIFY(t.Childs[0].Start==3 && t.Childs[0].End==5);
}
void TestTreePoints::test_AddThreePoints()
{
    TreePoints TreePoint;
TreePoint.AddPoint(1,12);
TreePoint.AddPoint(3,5);

TreePoint.AddPoint(6,9);
CodeTreeNode t= TreePoint.GetTree();
///QVERIFY(t.Node.Start==1 && t.Node.End==12);


//QVERIFY(t.Childs==1 && t.Node.End==6);
}

QTEST_APPLESS_MAIN(TestTreePoints)

#include "tst_testtreepoints.moc"
