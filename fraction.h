#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>

class Fractions{

    private:
    double numerator;
    double denominator;


    public:
    //  members modifiers
    double GetNumerator() const{ return numerator;};
    void SetNumerator(double num){numerator = num;};

    double GetDenominator() const{ return denominator;};
    void SetDenominator(double div){denominator = div;};

    Fractions PowFraction(const Fractions &frac);

    //  constructors/destructor
    Fractions(): numerator(1), denominator(1){};
    Fractions(double num, double div = 1): numerator(num), denominator(div){
        if(div < 0){
            numerator *= -1;
            denominator *= -1;
        }
    };
    ~Fractions(){};

    //  operators
    friend Fractions operator+(const Fractions & frac1, const Fractions & frac2);
    friend Fractions operator-(const Fractions & frac1, const Fractions & frac2);
    friend Fractions operator/(const Fractions & frac1, const Fractions & frac2);
    friend Fractions operator*(const Fractions & frac1, const Fractions & frac2);

    Fractions & operator=(const Fractions & frac);
    Fractions & operator+=(const Fractions & frac);
    Fractions & operator-=(const Fractions & frac);
    Fractions & operator/=(const Fractions & frac);
    Fractions & operator*=(const Fractions & frac);
    Fractions & operator -();
    //  I/O functions
    friend std::istream & operator >>(std::istream &is, Fractions & frac);
    friend std::ostream & operator <<(std::ostream &os, const Fractions & frac);

};



#endif
