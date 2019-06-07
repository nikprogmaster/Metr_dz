#include "cont1.h"

Cont1::Cont1()
{

}

void Cont1::filling1() {
    std::ifstream fin("criteria1.txt");

        while (fin) {
        Table_Cr1 *newel = new Table_Cr1;
        fin >>(*newel).num >> (*newel).q1 >>(*newel).q5 >>(*newel).q99 >>(*newel).q95;

        if ((*newel).q1!=0.0)
        this->push_back(*newel);
    }
}
