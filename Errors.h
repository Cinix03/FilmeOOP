//
// Created by Vasile George on 08.04.2024.
//

#ifndef LAB6OOP_ERRORS_H
#define LAB6OOP_ERRORS_H

#include <string>
using namespace std;

class Exception{
    string msg;
public:
    Exception(string msg) : msg{msg} {}
    string getMsg() const { return msg; }
};

#endif //LAB6OOP_ERRORS_H
