// ======================================================================
//  main.cpp
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

#include <QtWidgets>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QGroupBox gbx("&Colors");

    QRadioButton* pradRed   = new QRadioButton("&Red");
    QRadioButton* pradGreen = new QRadioButton("&Green");
    QRadioButton* pradBlue  = new QRadioButton("&Blue");
    pradGreen->setChecked(true);

    //Layout setup 
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pradRed);
    pvbxLayout->addWidget(pradGreen);
    pvbxLayout->addWidget(pradBlue);
    gbx.setLayout(pvbxLayout);

    gbx.show();

    return app.exec();
}
