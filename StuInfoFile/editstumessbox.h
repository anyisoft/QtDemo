#ifndef EDITSTUMESSBOX_H
#define EDITSTUMESSBOX_H

#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class EditStuMessBox : public QDialog
{
public:
    EditStuMessBox();

private:
    QVBoxLayout m_vbLayout;
    QFormLayout m_frmLayout;
    QHBoxLayout m_hbLayout;

    // up form layout
    QLineEdit m_ledtNo;
    QLineEdit m_ledtName;
    QLineEdit m_ledtAge;
    QLineEdit m_ledtSex;
    QLineEdit m_ledtChinese;
    QLineEdit m_ledtMath;
    QLineEdit m_ledtEnglish;

    // down hbox layout
    QPushButton m_btnCommit;
    QPushButton m_btnCancel;

};

#endif // EDITSTUMESSBOX_H
