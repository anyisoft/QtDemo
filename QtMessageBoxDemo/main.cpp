#pragma execution_character_set("utf-8")

#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QAbstractButton>

QPushButton * agreeBtn;
QPushButton * disagreeBtn;

class MyWidget : public QWidget {
    Q_OBJECT
public slots:
    void buttonClicked(QAbstractButton *btnClicked);
};

void MyWidget::buttonClicked(QAbstractButton * btnClicked) {
    if (btnClicked == (QAbstractButton*)disagreeBtn) {
        this->close();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyWidget myWidget;
    myWidget.setWindowTitle("主窗口");
    myWidget.resize(400, 300);

    QMessageBox MyBox(QMessageBox::Question, "", "");
    MyBox.setParent(&myWidget);
    MyBox.setWindowFlag(Qt::Dialog);
    MyBox.setWindowTitle("协议");
    MyBox.setText("使用本产品，请您严格遵守xxx规定！");

    agreeBtn = MyBox.addButton("同意", QMessageBox::AcceptRole);
    disagreeBtn = MyBox.addButton("拒绝", QMessageBox::RejectRole);

    myWidget.show();

    QObject::connect(&MyBox, &QMessageBox::buttonClicked, &myWidget, &MyWidget::buttonClicked);
    MyBox.exec();

    return a.exec();
}

#include "main.moc"
