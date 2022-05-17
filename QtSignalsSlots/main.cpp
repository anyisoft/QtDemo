#pragma execution_character_set("utf-8")

#include <QApplication>
#include <QWidget>
#include <QDebug>


class MyWidget : public QWidget {
    Q_OBJECT
signals:
    void MySignal(QString mess1, QString mess2);

public:
    void emitSignal() {
        emit MySignal(message1, message2);
    }

    void recSlot1(QString mess) {
        qDebug() << "执行 recSlot1() 成员函数，输出" << mess;
    }

public slots:
    void recSlot2(QString mess1, QString mess2) {
        qDebug() << "执行 recSlot2() 成员函数，输出" << mess1 << " " << mess2;
    }

public:
    QString message1;
    QString message2;
};

void recSlot3()
{
    qDebug() << "执行 recSlot3() 全局函数";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyWidget myWidget;
    myWidget.message1 = "C语言中文网";
    myWidget.message2 = "http://c.biancheng.net";

    QObject::connect(&myWidget, &MyWidget::MySignal, &myWidget, &MyWidget::recSlot1);
    QObject::connect(&myWidget, &MyWidget::MySignal, &myWidget, &MyWidget::recSlot2);
    QObject::connect(&myWidget, &MyWidget::MySignal, &recSlot3);

    myWidget.show();
    myWidget.emitSignal();

    return a.exec();
}

#include "main.moc"
