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
    QApplication   app(argc, argv);
    QGraphicsScene scene(QRectF(0, 0, 400, 400));
    QGraphicsView  view(&scene);

    QPushButton cmd("Quit");
    QGraphicsProxyWidget* pproxyWidget = scene.addWidget(&cmd);
    QTransform            transform    = pproxyWidget->transform();

    transform.translate(100, 350);
    transform.rotate(-45, Qt::YAxis);
    transform.scale(8, 2);
    pproxyWidget->setTransform(transform);
    QObject::connect(&cmd, SIGNAL(clicked()), &app, SLOT(quit()));

    QDial dia;
    dia.setNotchesVisible(true);
    pproxyWidget = scene.addWidget(&dia);
    transform    = pproxyWidget->transform();

    transform.scale(4, 2);
    transform.rotate(-45, Qt::YAxis);
    pproxyWidget->setTransform(transform);
    
    QProgressBar prb;
    prb.setFixedSize(500, 40);
    pproxyWidget = scene.addWidget(&prb);
    transform    = pproxyWidget->transform();

    transform.translate(20, 200);
    transform.scale(2, 2);
    transform.rotate(80, Qt::YAxis);
    transform.rotate(30, Qt::XAxis);
    pproxyWidget->setTransform(transform);

    QObject::connect(&dia, SIGNAL(valueChanged(int)), 
                     &prb, SLOT(setValue(int))
                    );

    view.rotate(15);
    view.show();
  
    return app.exec();
} 
