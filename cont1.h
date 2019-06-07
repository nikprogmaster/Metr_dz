#ifndef CONT1_H
#define CONT1_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "table_cr1.h"

class Cont1: public std::vector<Table_Cr1>
{
public:
    Cont1();
    void filling1();
};

#endif // CONT1_H
