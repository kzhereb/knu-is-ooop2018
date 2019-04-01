#include <QtTest>

#include "../app/functionbuilder.h"
#include "../app/function.h"
#include "../app/differentiate.h"

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
    void test_differentiate();

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

    Function * x = builder.create_simple("x");
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

void CalculusTest::test_differentiate()
{
    FunctionBuilder builder;

    Function * x = builder.create_simple("x");

    builder.start_build("1");
    Function * one = builder.get_result();


    builder.start_build("plus");
    builder.add_operand(*x);
    builder.add_operand(*one);
    Function * xplus1 = builder.get_result();

    Differentiate diff;

    Function* der = diff.get_derivative(xplus1,"x");
    QCOMPARE(der->str().c_str(),"plus(1, 0)");

}

QTEST_APPLESS_MAIN(CalculusTest)

#include "tst_calculustest.moc"
