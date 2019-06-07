#include "sample.h"
#include <iostream>


void Sample::read_from_file(const std::string &path) {
    if (path == "")
        return;

    this->clear();

    std::ifstream fin(path);

    while (fin) {
        std::string row;
        fin >> row;

        size_t comma_pos = row.find(",");
        if (comma_pos != std::string::npos)
            row.replace(comma_pos, 1, ".");

        if (row != "") {
            std::istringstream i(row);
            double d;
            i >> d;
            this->push_back(d);
        }
    }
}

double Sample::mean() const {
    double result = 0;

    for (auto i : *this) {
        result += i;
    }

    result /= size();

    return result;
};

double Sample::variance() const {
    double avg = mean();
    double result = 0;

    for (auto i : *this) {
        result += (i - avg) * (i - avg);
    }

    result /= size() - 1;
    result = sqrt(result);
    return result;
}

double Sample::val1() const {
    double avg = mean();
    double s = 0.000000;
    double d = 0.000000;

    for (auto i : *this) {
        s += (i - avg) * (i - avg);
    }

    s /= size();
    s = sqrt(s);

    for (auto i : *this) {
        d += std::abs(i - avg);
    }

    d = d/(size()*s);
    return d;
}

bool Sample::crit_1(Cont1 tabl1, int q) const {
    unsigned int s=0, i=0;
    for (i=0; i<tabl1.size(); i++) {
        if ((tabl1[i]).num==size())
            s=i;
    }
    std::cout<<val1();
    if (q==1) {
        if (tabl1[s].q99<val1() and val1()<tabl1[s].q1)
            return true;
        else return false;
    }
    else
        if (q==2) {
            if (tabl1[s].q95<val1() and val1()<tabl1[s].q5)
                return true;
            else return false;
        }
}

bool Sample::crit_2(Cont tabl2, int q) const {
    double avg = mean();
    std::cout<<avg<<std::endl;
    unsigned int i=0, j=0, nes=0;
    int kol=0;
    double s =  variance();
    std::cout<<s<<std::endl;
    for (i=0; i<tabl2.size(); i++)
        for (j=0; j<tabl2[i].nums.size(); j++)
        if (tabl2[i].nums[j]==size())
            nes=i;

    if (q==1) {
    for (auto i : *this)
        if ((i-avg)>tabl2[nes].q1*s)
            kol++;
    }
    else
        if (q==2) {
        for (auto i : *this)
            if ((i-avg)>tabl2[nes].q2*s)
                kol++;
        }
    else
            if (q==5) {
            for (auto i : *this)
                if ((i-avg)>tabl2[nes].q5*s)
                    kol++;
            }
    std::cout<<kol<<std::endl;
    if (kol<=tabl2[nes].m)
        return true;
    else
        return false;
}
