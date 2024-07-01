//
// Created by Vasile George on 08.04.2024.
//

#include "Validator.h"
#include "Errors.h"
#include <iostream>
using std::string;
bool validString(string str)
{
    if(str.size() == 0) return false;
    for(int i = 0; i<str.size(); i++)
        if(str[i] < 'A' || str[i] > 'z')
            if(str[i] != ' ' && str[i] != '.')
            return false;
    return true;
}

void Validator::validateFilm(const std::string &titlu, const std::string &actor, const std::string &gen, int an) {
    string errors;
    if(!validString(titlu))
        errors += "Titlu invalid\n";
    if(!validString(gen))
        errors += "Gen invalid\n";
    if(!validString(actor))
        errors += "Actor invalid\n";
    if(an < 0)
        errors += "An invalid\n";
    if(errors.size() > 0)
        throw Exception(errors);
}