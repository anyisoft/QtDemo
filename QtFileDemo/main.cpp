#pragma execution_character_set("utf-8")

#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDataStream>

/* part1 text
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("D:/work/QtDemo/demo.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
    }

    file.write("C语言中文网\n");
    file.write("http://c.biancheng.net\n");
    file.close();

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
    }

    char * str = new char[100];
    qint64 readNum = file.readLine(str, 100);

    while (readNum != 0 && readNum != -1) {
        qDebug() << str;
        readNum = file.readLine(str, 100);
    }

    file.close();

    return a.exec();
}
*/
/*
// part2: binary
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qint32 nums[5] = { 1, 2, 3, 4, 5 };
    QByteArray ba;
    ba.resize(sizeof(nums));
    for (int i = 0; i < 5; i++) {
        memcpy(ba.data()+i*sizeof(qint32), &(nums[i]), sizeof(qint32));
    }

    QFile file("D:/work/QtDemo/demo.dat");
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "文件打开失败";
    }

    file.write(ba);
    file.close();

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败";
    }

    QByteArray baRet = file.readAll();

    qDebug() << "baRet: " << baRet;

    char * data = baRet.data();
    while (*data) {
        qDebug() << *(qint32*)data;
        data += sizeof(qint32);
    }

    file.close();

    return a.exec();
}
*/
/*
// part 3: QTextStream
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("D:/work/QtDemo/demo.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
    }

    QTextStream tsOut(&file);
    tsOut << (QString)"C语言中文网\n" << (QString)"http://c.biancheng.net";

    file.close();

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
    }

    QTextStream tsIn(&file);
    while (!tsIn.atEnd()) {
        QString str;

        tsIn >> str;
        qDebug() << str;
    }

    file.close();

    return a.exec();
}
*/
/*
// part 4: QTextStream format output
int main (int argc, char * argv[])
{
    QFile file("D:/work/QtDemo/demo.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
    }

    QTextStream tsOut(&file);

    tsOut << hex << 10;
    tsOut.setFieldWidth(10);
    tsOut << left << 3.14;
    tsOut.setFieldAlignment(QTextStream::AlignRight);
    tsOut << 2.7;

    file.close();


    return 0;
}
*/

// part 5: QDataStream
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qint32 nums[5] = { 1, 2, 3, 4, 5 };
    QFile file("D:/work/QtDemo/demo.dat");
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "文件打开失败";
    }

    QDataStream dsOut(&file);
    for (int i = 0; i < 5; i++) {
        dsOut << nums[i];
    }

    file.close();

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败";
    }

    QDataStream dsIn(&file);
    while (!dsIn.atEnd()) {
        qint32 num;
        dsIn >> num;
        qDebug() << num;
    }

    file.close();

    return a.exec();
}




