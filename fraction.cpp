#include <iostream>
#include "fraction.h"


    Fractions Fractions::PowFraction(const Fractions & frac){
        Fractions result;
        double Exponent = frac.numerator/frac.denominator;

        if(frac.numerator < 0){
            result.numerator = -this->denominator;
            result.denominator = -this->numerator;
            Exponent *= -1;
        }else{
            result.denominator = this->denominator;
            result.numerator = this->numerator;
        }
        result.numerator = pow(result.numerator, Exponent);
        result.denominator = pow(result.denominator, Exponent);
        return result;

    }

    Fractions operator+(const Fractions &frac1, const Fractions &frac2){
        Fractions temp;
        temp.SetNumerator((frac1.GetNumerator() * frac2.GetDenominator()) + (frac1.GetDenominator() * frac2.GetNumerator()));
        temp.SetDenominator(frac1.GetDenominator()*frac2.GetDenominator());
        return temp;
    }

    Fractions operator-(const Fractions &frac1, const Fractions &frac2){
        Fractions temp;
        temp.SetNumerator((frac1.GetNumerator() * frac2.GetDenominator()) - (frac1.GetDenominator() * frac2.GetNumerator()));
        temp.SetDenominator(frac1.GetDenominator()*frac2.GetDenominator());
        return temp;
    }

    Fractions operator/(const Fractions &frac1, const Fractions &frac2){
        Fractions temp(frac1.GetNumerator() * frac2.GetDenominator(), frac1.GetDenominator() * frac2.GetNumerator());
        if(temp.denominator < 0){
            temp.numerator = -temp.numerator;
            temp.denominator = -temp.denominator;
        }
        return temp;
    }

    Fractions operator*(const Fractions &frac1, const Fractions &frac2){
        Fractions temp(frac1.GetNumerator() * frac2.GetNumerator(), frac1.GetDenominator() * frac2.GetDenominator());
        return temp;
    }

    Fractions & Fractions::operator=(const Fractions & frac){
        if(this != &frac){
            numerator = frac.numerator;
            denominator = frac.denominator;
        }
        return *this;
    }
    Fractions & Fractions::operator+=(const Fractions & frac){
        if(this != &frac){
            double down = this->denominator * frac.denominator;
            this->numerator = (this->numerator*frac.denominator) + (this->denominator*frac.numerator);
            this->denominator =down;

        }else{
            numerator *= 2;
        }

        return *this;
    }

    Fractions & Fractions::operator-=(const Fractions & frac){
        if(this != &frac){
            double down = this->denominator * frac.denominator;
            this->numerator = (this->numerator*frac.denominator) - (this->denominator*frac.numerator);
            this->denominator =down;

        }else{
            numerator = denominator = 0;

        }

        return *this;
    }

    Fractions & Fractions::operator*=(const Fractions & frac){

        this->numerator *= frac.numerator;
        this->denominator *= frac.denominator;

        return *this;
    }

    Fractions & Fractions::operator/=(const Fractions & frac){
        if(this != &frac){
            this->numerator *= frac.denominator;
            this->denominator *= frac.numerator;
            if(this->denominator <0){
                this->denominator = -this->denominator;
                this->numerator = -this->numerator;
            }
        }else{
            this->numerator = this->denominator = 1;
        }
        return *this;
    }

    Fractions & Fractions::operator-(){
        this->numerator = -this->numerator;
        return *this;
    }
    std::istream & operator >>(std::istream &is, Fractions & frac){
        std::cout << "Digite o numerador: ";
        is >> frac.numerator;
        std::cout << "Digite o denominador: ";
        is >> frac.denominator;
        if(frac.denominator < 0){
            frac.numerator *= -1;
            frac.denominator *= -1;
        }
        return is;
    }

    std::ostream & operator <<(std::ostream &os, const Fractions & frac){
        os << "Numerador: " <<frac.numerator <<'\n';
        os << "Denominador: " << frac.denominator << '\n';
        if(frac.denominator == 0)
            os << "Resultado: " << "Nao e possivel efetuar divisao por 0" << '\n';
        else
        os << "Resultado: " << frac.numerator / frac.denominator << '\n';
        return os;
    }
