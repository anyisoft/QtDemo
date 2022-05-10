#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QTableWidgetItem>

class QMyLabel:public QLabel {
    Q_OBJECT
public slots:
    void rsetText(QTableWidgetItem *item);
};

#endif // MAINWINDOW_H
