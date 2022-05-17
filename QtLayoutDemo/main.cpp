#pragma execution_character_set("utf-8")

/*
 // part1: QVBoxLayout and QHBoxLayout
#include <QApplication>
#include <QWidget>
#include <QLabel>
//#include <QVBoxLayout>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    //widget.setWindowTitle("QVBoxLayout垂直布局");
    widget.setWindowTitle("QVBoxLayout水平布局");

    //QVBoxLayout * layout = new QVBoxLayout;
    //layout->setDirection(QBoxLayout::BottomToTop);
    QHBoxLayout * layout = new QHBoxLayout;
    layout->setDirection(QBoxLayout::RightToLeft);

    QLabel lab1("label1");
    lab1.setStyleSheet("QLabel{background:#dddddd;font:20px;}");
    lab1.setAlignment(Qt::AlignCenter);

    QLabel lab2("label2");
    lab2.setStyleSheet("QLabel{background:#cccccc;font:20px;}");
    lab2.setAlignment(Qt::AlignCenter);

    QLabel lab3("label3");
    lab3.setStyleSheet("QLabel{background:#ffffff;font:20px;}");
    lab3.setAlignment(Qt::AlignCenter);

    layout->addStretch(2);
    layout->addWidget(&lab1, 1);
    layout->addWidget(&lab2, 2);
    layout->addWidget(&lab3, 3);
    layout->addStretch(3);

    widget.setLayout(layout);
    widget.show();


    return a.exec();
}
*/

/*
// part2: QGridLayout
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    widget.setWindowTitle("QGridLayout网格布局");

    QPushButton *btn1 = new QPushButton("btn1");
    QPushButton *btn2 = new QPushButton("btn2");

    QLabel * lab3 = new QLabel("lab");
    lab3->setStyleSheet("QLabel{background:#dddddd;font:20px;}");
    lab3->setAlignment(Qt::AlignCenter);

    QPushButton *btn3 = new QPushButton("btn3");
    QPushButton *btn4 = new QPushButton("btn4");

    QGridLayout * layout = new QGridLayout;

    layout->setRowStretch(0, 2); // no useful ??
    layout->addWidget(btn1, 0, 0);
    layout->addWidget(btn2, 0, 2);
    layout->addWidget(lab3, 1, 0, 3, 3);
    layout->addWidget(btn3, 4, 0);
    layout->addWidget(btn4, 4, 2);

    layout->setColumnStretch(1, 2); // no useful ??


    widget.setLayout(layout);
    widget.show();


    return a.exec();
}
*/
/*
// part3: QFormLayout
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QFormLayout>

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    widget.setWindowTitle("QFormLayout表单布局");

    QFormLayout * layout = new QFormLayout();

    //layout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    layout->setRowWrapPolicy(QFormLayout::WrapLongRows);
    //layout->setRowWrapPolicy(QFormLayout::WrapAllRows);

    layout->addRow("Name:", new QLineEdit());
    layout->addRow("Email:", new QLineEdit());
    layout->addRow("Address:", new QLineEdit());

    layout->setSpacing(10);

    widget.setLayout(layout);
    widget.show();

    return a.exec();
}
*/

// part4: QStackedLayout
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QStackedLayout>
#include <QListWidget>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    widget.setWindowTitle("QStackLayou分组布局");

    QHBoxLayout * layout = new QHBoxLayout;

    QListWidget listWidget(&widget);
    listWidget.setMinimumWidth(150);
    listWidget.setFont(QFont("宋体", 14));
    listWidget.addItem("QPushButton");
    listWidget.addItem("QLabel");
    listWidget.addItem("QLineEdit");

    QWidget widget1;
    widget1.setMinimumSize(400, 400);

    QWidget widget2;
    widget2.setMinimumSize(400, 400);

    QWidget widget3;
    widget3.setMinimumSize(400, 400);

    QPushButton btn1("这是一个按钮", &widget1);
    QLabel lab1("这是一个文本框", &widget2);
    QLineEdit edt1("这是一个单行输入框", &widget3);

    QStackedLayout * stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(&widget1);
    stackedLayout->addWidget(&widget2);
    stackedLayout->addWidget(&widget3);

    layout->addWidget(&listWidget, 1);
    layout->addLayout(stackedLayout, 4);

    widget.setLayout(layout);
    widget.show();

    QObject::connect(&listWidget, &QListWidget::currentRowChanged, stackedLayout, &QStackedLayout::setCurrentIndex);

    return a.exec();
}







