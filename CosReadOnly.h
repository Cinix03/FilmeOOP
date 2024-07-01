//
// Created by Vasile George on 24.05.2024.
//

#ifndef LAB6OOP_COSREADONLY_H
#define LAB6OOP_COSREADONLY_H
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QPainter>
#include "Service.h"

class CosReadOnly: public QWidget, public Observer{
private:
    Service& service;
    QPushButton* btnExit = new QPushButton("&Exit");
public:
    CosReadOnly(Service& service): service{service} {
        setWindowTitle("CosReadOnly");
        init_gui();
        init_connect();
    }
    void init_gui(){
        auto lyMain = new QVBoxLayout();
        setLayout(lyMain);
        lyMain->addWidget(btnExit);
    }
    void init_connect(){
        service.cos.addObserver(this);
        QObject::connect(btnExit, &QPushButton::clicked, [&](){
            close();
        });
    }
    void update() override{
        repaint();
    }
    void paintEvent(QPaintEvent* ev) override {
        QPainter p{ this };
        srand(time(NULL));
        for (const auto& u : service.cos.get_all()) {
            int x = rand() % 300;
            int y = rand() % 300;
            p.drawRect(x, y, 20, u.getAn() / 10);
        }

    }
};


#endif //LAB6OOP_COSREADONLY_H
