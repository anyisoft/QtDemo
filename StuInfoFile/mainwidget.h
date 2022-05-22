#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFile>

#include "editstumessbox.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    QHBoxLayout m_hbLayout;
    QGroupBox m_gbLeft;
    QHBoxLayout m_hbl4Table;
    QTableWidget m_table;

    QGroupBox m_gbRight;
    QVBoxLayout m_vbLayout;
    QListWidget m_list;
    QGridLayout m_gridLayout;
    QPushButton m_btnAdd;
    QPushButton m_btnDel;
    QPushButton m_btnSave;
    QPushButton m_btnExit;
    QLineEdit m_edtInput;

    EditStuMessBox m_wndEdit;

};
#endif // MAINWIDGET_H
