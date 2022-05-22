#pragma execution_character_set("utf-8")

#include "editstumessbox.h"

EditStuMessBox::EditStuMessBox()
{
    m_frmLayout.addRow("学号", &m_ledtNo);
    m_frmLayout.addRow("姓名", &m_ledtName);
    m_frmLayout.addRow("年龄", &m_ledtAge);
    m_frmLayout.addRow("性别", &m_ledtSex);
    m_frmLayout.addRow("语文", &m_ledtChinese);
    m_frmLayout.addRow("数学", &m_ledtMath);
    m_frmLayout.addRow("英语", &m_ledtEnglish);
    m_vbLayout.addLayout(&m_frmLayout);

    m_btnCommit.setText("提 交");
    m_btnCancel.setText("取 消");
    m_hbLayout.addWidget(&m_btnCommit);
    m_hbLayout.addWidget(&m_btnCancel);
    m_vbLayout.addLayout(&m_hbLayout);

    this->setLayout(&m_vbLayout);

}
