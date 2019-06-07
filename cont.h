#ifndef CONT_H
#define CONT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "table_cr2.h"

class Cont: public std::vector<Table_Cr2>
{
public:
    Cont();
    void filing ();
};

#endif // CONT_H
