#include <QtTest>

#include "../app/functionbuilder.h"
#include "../app/function.h"

// add necessary includes here

class CalculusTest : public QObject
{
    Q_OBJECT

public:
    CalculusTest();
    ~CalculusTest();

private slots:
    void test_function_builder();
    void test_constant_variable();

};

CalculusTest::CalculusTest()
{

}

CalculusTest::~CalculusTest()
{

}

void CalculusTest::test_function_builder()
{
    FunctionBuilder builder;
    builder.start_build("x");
    Function * x = builder.get_result();

    builder.start_build("1");
    Function * one = builder.get_result();

    builder.start_build("plus");
    builder.add_operand(*x);
    builder.add_operand(*one);
    Function * xplus1 = builder.get_result();

    QCOMPARE(xplus1->str().c_str(),"plus(x, 1)");

}

void CalculusTest::test_constant_variable()
{
    FunctionBuilder builder;
    builder.start_build("x");
    Function * x = builder.get_result();
    QVERIFY(x->is_variable());
    QVERIFY(! x->is_constant());

    builder.start_build("1");
    Function * one = builder.get_result();

    QVERIFY(! one->is_variable());
    QVERIFY(one->is_constant());

    builder.start_build("plus");
    builder.add_operand(*x);
    builder.add_operand(*one);
    Function * xplus1 = builder.get_result();
    QVERIFY(! xplus1->is_variable());
    QVERIFY(! xplus1->is_constant());


}

QTEST_APPLESS_MAIN(CalculusTest)

#include "tst_calculustest.moc"
