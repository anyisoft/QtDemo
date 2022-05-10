#pragma execution_character_set("utf-8")
#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QDebug>
#include <QPushButton>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;

    widget.setWindowTitle("QWidget窗口");
    widget.resize(900, 500);

    QTableWidget tableWidget(4, 3, &widget);
    tableWidget.resize(900, 350);
    tableWidget.setFont(QFont("宋体", 20));
    tableWidget.setHorizontalHeaderLabels(QStringList()<<"tutorial" << "web" << "state");
    tableWidget.setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableWidget.setItem(0, 0, new QTableWidgetItem("C语言教程"));
    tableWidget.setItem(0, 1, new QTableWidgetItem("http://c.biancheng.net/c/"));
    tableWidget.setItem(0, 2, new QTableWidgetItem("updated"));
    tableWidget.setItem(1, 0, new QTableWidgetItem("QT教程"));
    tableWidget.setItem(1, 1, new QTableWidgetItem("http://c.biancheng.net/qt/"));
    tableWidget.setItem(1, 2, new QTableWidgetItem("正在更新"));
    tableWidget.setItem(2, 0, new QTableWidgetItem("C++教程"));
    tableWidget.setItem(2, 1, new QTableWidgetItem("http://c.biancheng.net/cplus/"));
    tableWidget.setItem(2, 2, new QTableWidgetItem("已更新完毕"));

    QMyLabel print;
    print.setText("选中内容");
    print.setParent(&widget);
    print.resize(900, 150);
    print.move(0, 350);
    print.setAlignment(Qt::AlignCenter);
    print.setFont(QFont("宋体", 16));

    widget.show();

    QObject::connect(&tableWidget, &QTableWidget::itemClicked, &print, &QMyLabel::rsetText);


    return a.exec();
}
