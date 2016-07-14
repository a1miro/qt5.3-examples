// ======================================================================
//  LoadMyForm.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#pragma once

#include <QtWidgets>
#include <QtUiTools>

// ======================================================================
class LoadMyForm : public QWidget {
Q_OBJECT
private:
    QSlider*    m_psld;
    QLCDNumber* m_plcd;

public:
    LoadMyForm(QWidget* pwgt = 0) : QWidget(pwgt)
    {
        QUiLoader* puil = new QUiLoader(this);
        QFile      file(":/MyForm.ui");

        QWidget* pwgtForm = puil->load(&file);
        if (pwgtForm) {
            resize(pwgtForm->size());

            m_psld = pwgtForm->findChild<QSlider*>("m_sld");
            m_plcd = pwgtForm->findChild<QLCDNumber*>("m_lcd");

            QPushButton* pcmdReset = 
                pwgtForm->findChild<QPushButton*>("m_cmdReset");
            connect(pcmdReset, SIGNAL(clicked()), SLOT(slotReset()));

            QPushButton* pcmdQuit = 
                pwgtForm->findChild<QPushButton*>("m_cmdQuit");
            connect(pcmdQuit, SIGNAL(clicked()), qApp, SLOT(quit()));

            //Layout setup
            QHBoxLayout* phbxLayout = new QHBoxLayout;    
            phbxLayout->addWidget(pwgtForm);
            setLayout(phbxLayout);
        }
    }

public slots:
    void slotReset()
    {
        m_psld->setValue(0);
        m_plcd->display(0);
    }
};
