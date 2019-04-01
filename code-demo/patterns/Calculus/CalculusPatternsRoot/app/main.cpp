#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "functionbuilder.h"
#include "function.h"

int main(int argc, char *argv[])
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

    qDebug()<<xplus1->str().c_str();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
