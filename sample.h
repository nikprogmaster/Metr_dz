#ifndef SAMPLE_H
#define SAMPLE_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include "cont.h"
#include "cont1.h"

class Sample: public std::vector<double>
{
public:
    void read_from_file(const std::string &path);
    double mean() const;
    double variance() const;
    double val1() const;
    bool crit_1(Cont1 tabl1, int q) const;
    bool crit_2(Cont tabl2, int q) const;
};

#endif // SAMPLE_H
