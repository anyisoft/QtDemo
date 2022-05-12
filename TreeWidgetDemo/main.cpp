#pragma execution_character_set("utf-8")

#include <QApplication>
#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QTableWidget>

// custom slot function
class MyWidget:public QWidget {
    Q_OBJECT
public slots:
    void treeWidgetClicked(QTreeWidgetItem *item);
};

void MyWidget::treeWidgetClicked(QTreeWidgetItem *item) {
    for (int i = 0; i < item->childCount(); i++) {
        QTreeWidgetItem *childItem = item->child(i);
        childItem->setCheckState(0, item->checkState(0));
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget widget;
    widget.setWindowTitle("MyTreeWidget控件");
    widget.resize(600, 300);

    QTreeWidget treeWidget(&widget);
    treeWidget.setColumnCount(3);
    treeWidget.resize(600, 300);

    QTreeWidgetItem topItem;
    topItem.setText(0, "教程");
    topItem.setCheckState(0, Qt::Unchecked);
    treeWidget.addTopLevelItem(&topItem);

    QStringList c;
    c << "C语言教程" << "http://c.biancheng.net/c/" << "已完成";
    QTreeWidgetItem childItem1(&topItem, c);
    childItem1.setCheckState(0, Qt::Unchecked);


    QStringList qt;
    qt << "Qt教程" << "http://c.biancheng.net/qt/" << "未完成";
    QTreeWidgetItem childItem2(&topItem, qt);
    childItem2.setCheckState(0, Qt::Unchecked);


    QStringList python;
    python << "Python教程" << "http://c.biancheng.net/python/" << "已完成";
    QTreeWidgetItem childItem3(&topItem, python);
    childItem3.setCheckState(0, Qt::Unchecked);

    QObject::connect(&treeWidget, &QTreeWidget::itemClicked, &widget, &MyWidget::treeWidgetClicked);
    QObject::connect(&treeWidget, &QTreeWidget::itemClicked, &treeWidget, &QTreeWidget::expandItem);

    widget.show();

    return a.exec();
}

// MyWidget类的定义应该放到.h 中，本例中将其写到main.cpp 中，程序最后需要添加#include "当前源文件名.moc"语句，否则无法通过编译。
#include "main.moc"
