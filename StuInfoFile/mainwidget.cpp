#pragma execution_character_set("utf-8")

#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    // 1)divide left right
    m_gbLeft.setTitle("学生信息");
    m_gbRight.setTitle("功能面板");
    m_hbLayout.addWidget(&m_gbLeft, 2);
    m_hbLayout.addWidget(&m_gbRight, 1);
    this->setLayout(&this->m_hbLayout);

    // 2)left table
    m_hbl4Table.addWidget(&m_table);
    m_table.setRowCount(4);
    m_table.setColumnCount(7);
    m_table.setHorizontalHeaderLabels(QStringList() << "学  号" << "姓  名" << "年龄" << "性别" << "语文" << "数学" << "英语");
    m_gbLeft.setLayout(&this->m_hbl4Table);

    // 3)right panel
    m_vbLayout.addWidget(&m_list, 7);

    m_btnAdd.setText("添 加");
    m_btnDel.setText("删 除");
    m_btnSave.setText("保 存");
    m_btnExit.setText("退 出");
    m_edtInput.setPlaceholderText("输入学生姓名查找...");
    m_gridLayout.addWidget(&m_btnAdd, 0, 0);
    m_gridLayout.addWidget(&m_btnDel, 0, 1);
    m_gridLayout.addWidget(&m_edtInput, 1, 0, 1, 2);
    m_gridLayout.addWidget(&m_btnSave, 2, 0);
    m_gridLayout.addWidget(&m_btnExit, 2, 1);
    m_vbLayout.addLayout(&m_gridLayout, 3);
    m_gbRight.setLayout(&m_vbLayout);

    m_wndEdit.setModal(true);
    QObject::connect(&m_btnAdd, &QPushButton::clicked, &m_wndEdit, &QDialog::show);
}

MainWidget::~MainWidget()
{
}

