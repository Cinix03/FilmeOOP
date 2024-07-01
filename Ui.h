//
// Created by Vasile George on 30.03.2024.
//

#ifndef LAB6OOP_UI_H
#define LAB6OOP_UI_H


#include "Service.h"

class Ui {
private:
    Service& service;
public:
    explicit Ui(Service& service);
    void run();
};


#endif
