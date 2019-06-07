#include "cont.h"

Cont::Cont()
{

}

void Cont::filing () {

    std::ifstream fin("criteria2.txt");

        std::string row, m1, m2;
        int mi1, mi2;

        while (fin) {
        Table_Cr2 *newel = new Table_Cr2;
        fin >> row >>(*newel).m >> (*newel).q1 >>(*newel).q2 >>(*newel).q5;

        size_t pos = row.find("-");
        if (pos != std::string::npos)
        {
            m1 = row.substr(0,pos);
            mi1 = std::stoi(m1);
            m2 = row.substr(pos+1, row.length()-pos+1);
            mi2 = std::stoi(m2);
            for (int i=mi1; i<=mi2; i++)
                (*newel).nums.push_back(i);
        }
        else
             (*newel).nums.push_back(std::stoi(row));
        if ((*newel).q1!=0.0)
        this->push_back(*newel);
    }

}
