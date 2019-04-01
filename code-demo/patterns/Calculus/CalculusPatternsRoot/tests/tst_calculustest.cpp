#include <QtTest>


// add necessary includes here

class CalculusTest : public QObject
{
    Q_OBJECT

public:
    CalculusTest();
    ~CalculusTest();

private slots:
    void test_case1();

};

CalculusTest::CalculusTest()
{

}

CalculusTest::~CalculusTest()
{

}

void CalculusTest::test_case1()
{

}

QTEST_APPLESS_MAIN(CalculusTest)

#include "tst_calculustest.moc"
