#include <QtTest>

// add necessary includes here

class TestPairs : public QObject
{
    Q_OBJECT

public:
    TestPairs();
    ~TestPairs();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

TestPairs::TestPairs()
{

}

TestPairs::~TestPairs()
{

}

void TestPairs::initTestCase()
{

}

void TestPairs::cleanupTestCase()
{

}

void TestPairs::test_case1()
{

}

QTEST_APPLESS_MAIN(TestPairs)

#include "tst_testpairs.moc"
