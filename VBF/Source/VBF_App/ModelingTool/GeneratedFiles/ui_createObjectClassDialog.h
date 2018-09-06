/********************************************************************************
** Form generated from reading UI file 'createObjectClassDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEOBJECTCLASSDIALOG_H
#define UI_CREATEOBJECTCLASSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateObjectClassDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_buttons;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_create;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *CreateObjectClassDialog)
    {
        if (CreateObjectClassDialog->objectName().isEmpty())
            CreateObjectClassDialog->setObjectName(QString::fromUtf8("CreateObjectClassDialog"));
        CreateObjectClassDialog->resize(835, 527);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ModelingTool/Images/createObjectClass.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateObjectClassDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(CreateObjectClassDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidget = new QListWidget(CreateObjectClassDialog);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ModelingTool/Images/basicinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setPointSize(10);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ModelingTool/Images/reference.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font);
        __qlistwidgetitem1->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ModelingTool/Images/attribute.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setFont(font);
        __qlistwidgetitem2->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ModelingTool/Images/form.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setFont(font);
        __qlistwidgetitem3->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ModelingTool/Images/compose.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setFont(font);
        __qlistwidgetitem4->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ModelingTool/Images/behaviorComponent.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget);
        __qlistwidgetitem5->setFont(font);
        __qlistwidgetitem5->setIcon(icon6);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(160, 16777215));
        listWidget->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName(QString::fromUtf8("horizontalLayout_buttons"));
        horizontalSpacer = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_buttons->addItem(horizontalSpacer);

        pushButton_create = new QPushButton(CreateObjectClassDialog);
        pushButton_create->setObjectName(QString::fromUtf8("pushButton_create"));

        horizontalLayout_buttons->addWidget(pushButton_create);

        pushButton_cancel = new QPushButton(CreateObjectClassDialog);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_buttons->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout_buttons);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(CreateObjectClassDialog);

        QMetaObject::connectSlotsByName(CreateObjectClassDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateObjectClassDialog)
    {
        CreateObjectClassDialog->setWindowTitle(QApplication::translate("CreateObjectClassDialog", "\345\210\233\345\273\272\345\257\271\350\261\241\347\261\273", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("CreateObjectClassDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("CreateObjectClassDialog", "\346\227\266\347\251\272\345\217\202\347\205\247", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("CreateObjectClassDialog", "\345\261\236\346\200\247\347\211\271\345\276\201", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("CreateObjectClassDialog", "\347\251\272\351\227\264\345\275\242\346\200\201", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("CreateObjectClassDialog", "\347\273\204\346\210\220\347\273\223\346\236\204", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("CreateObjectClassDialog", "\350\241\214\344\270\272\350\203\275\345\212\233", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton_create->setText(QApplication::translate("CreateObjectClassDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("CreateObjectClassDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateObjectClassDialog: public Ui_CreateObjectClassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEOBJECTCLASSDIALOG_H