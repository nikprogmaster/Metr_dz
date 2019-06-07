#ifndef TABLE_CR2_H
#define TABLE_CR2_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Table_Cr2
{
public:
    Table_Cr2() {
        m = 0;
        q1 = 0.0;
        q2 = 0.0;
        q5 = 0.0;
    }

    int m;
    double  q1, q2, q5;
    std::vector<int> nums;

};


#endif // TABLE_CR2_H
