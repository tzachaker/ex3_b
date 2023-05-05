#include "Fraction.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
using namespace std;

namespace ariel
{
    Fraction::Fraction(int num, int den)
    {
        if(den==0) throw std::invalid_argument("division by zero");
        int gcd_value = gcd(num,den);
        numerator = num/gcd_value;
        denominator = den/gcd_value;
    }

    Fraction::Fraction(float frac)
    {   
        if (frac==0)
        {
            numerator = 0;
            denominator = 1;
        }
        else
        {
            numerator = round(frac * 1000);
            denominator = 1000;
            int gcd_value = gcd(numerator, denominator);
            numerator /= gcd_value;
            denominator /= gcd_value;
        }
    }

    int Fraction::getNumerator()
    {
        return numerator;
    }

    int Fraction::getDenominator()
    {
        return denominator;
    }

    int Fraction::gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    float Fraction::convert_frac_to_float(Fraction frac) const
    {
    float num = static_cast<float>(frac.getNumerator());
    float den = static_cast<float>(frac.getDenominator());
    return num / den;
    }

    std::ostream& operator<<(ostream& output, const Fraction& frac)
    {
        int num = frac.numerator;
        int den = frac.denominator;
        if(frac.denominator < 0)
        {
            num *= -1;
            den *= -1;
        }
        output << num << "/" << den;
        return output;
    }

    std::istream& operator>>(std::istream& input, Fraction& frac)
    {
    int num, den;
    if (!(input >> num)) { //like input.fail()
        throw std::runtime_error("Invalid input");
    }
    if (!(input >> den)) {
        throw std::runtime_error("Invalid input");
    }
    if (den == 0) {
        throw std::runtime_error("Division by zero");
    }
    frac = Fraction(num, den);
    return input;
    }
    
    Fraction Fraction::operator+(const Fraction& frac)
    {
        long long int num = static_cast<long long int>(numerator) * frac.denominator +
        static_cast<long long int>(denominator) * frac.numerator; //convert int to long long int
        long long int den = static_cast<long long int>(denominator) * frac.denominator; //convert int to long long int
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
        den > std::numeric_limits<int>::max() || den < std::numeric_limits<int>::min())        {
            throw std::overflow_error("overflow_error");
        }
        return Fraction(static_cast<int>(num), static_cast<int>(den)); //convert long long int to int
    }

    Fraction operator+(float num, const Fraction& frac)
    {
        Fraction res = Fraction(num) + frac;
        return res;
    }

    Fraction Fraction::operator-(const Fraction& frac)
    {
        long long int num = static_cast<long long int>(numerator) * frac.denominator -
        static_cast<long long int>(denominator) * frac.numerator; //convert int to long long int
        long long int den = static_cast<long long int>(denominator) * frac.denominator; //convert int to long long int
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
        den > std::numeric_limits<int>::max() || den < std::numeric_limits<int>::min())        {
            throw std::overflow_error("overflow_error");
        }
        return Fraction(static_cast<int>(num), static_cast<int>(den)); //convert long long int to int
    }

    Fraction operator-(float num, const Fraction& frac)
    {
        Fraction res = Fraction(num) - frac;
        return res;
    }

    Fraction Fraction::operator*(const Fraction& frac) 
    {
        long long int num = static_cast<long long int>(numerator) * frac.numerator; //convert int to long long int
        long long int den = static_cast<long long int>(denominator) * frac.denominator; //convert int to long long int
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
        den > std::numeric_limits<int>::max() || den < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("overflow_error");
        }
        return Fraction(static_cast<int>(num), static_cast<int>(den)); //convert long long int to int
    }

    Fraction operator*(float num, const Fraction& frac)
    {
        Fraction res = Fraction(num) * frac;
        return res;
    }

    Fraction Fraction::operator/(const Fraction& frac)
    {
        if (frac.numerator==0)
        {
            throw::runtime_error("division by zero");
        }
        long long int num = static_cast<long long int>(numerator) * frac.denominator; //convert int to long long int
        long long int den = static_cast<long long int>(denominator) * frac.numerator; //convert int to long long int
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
        den > std::numeric_limits<int>::max() || den < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("overflow_error");
        }
        return Fraction(static_cast<int>(num), static_cast<int>(den)); //convert long long int to int
    }

    Fraction operator/(float num, const Fraction& frac)
    {
        if(frac == 0){
           throw runtime_error("division by zero"); 
        }
        Fraction res = Fraction(num) / frac;
        return res;
    }
    
    Fraction Fraction::operator++()
    {
        numerator += denominator;
        return *this;
    }

    Fraction Fraction::operator++(int dummy_flag_for_postfix_increment)
    {
        Fraction copy(*this);
        numerator += denominator;
        return copy;
    }

    Fraction Fraction::operator--()
    {
        numerator -= denominator;
        return *this;
    }


    Fraction Fraction::operator--(int dummy_flag_for_postfix_increment)
    {
        Fraction copy(*this);
        numerator -= denominator;
        return copy;
    }

    bool Fraction::operator>(const Fraction& frac)const
    {
        return convert_frac_to_float(*this) > convert_frac_to_float(frac);
    }

    bool operator>(const Fraction& frac, float num)
    {
        return frac > Fraction(num);
    }

    bool operator>(float num, const Fraction& frac)
    {
        return Fraction(num) > frac;
    }

    bool Fraction::operator<(const Fraction& frac)const
    {
        return convert_frac_to_float(*this)<convert_frac_to_float(frac);
    }

    bool operator<(const Fraction& frac, float num)
    {
        return frac < Fraction(num);
    }

    bool operator<(float num, const Fraction& frac)
    {
        return Fraction(num) < frac;
    }

    bool Fraction::operator>=(const Fraction& frac)const
    {
        return convert_frac_to_float(*this)>=convert_frac_to_float(frac);
    }

    bool operator>=(const Fraction& frac, float num)
    {
        return frac >= Fraction(num);
    }

    bool operator>=(float num, const Fraction& frac)
    {
        return Fraction(num) >= frac;
    }

    bool Fraction::operator<=(const Fraction& frac)const
    {
        return convert_frac_to_float(*this)<=convert_frac_to_float(frac);
    }

    bool operator<=(const Fraction& frac, float num)
    {
        return frac <= Fraction(num);
    }
    
    bool operator<=(float num, const Fraction& frac)
    {
        return Fraction(num) <= frac;
    }

    bool Fraction::operator==(const Fraction& frac)const
    {
        float thisVal = static_cast<float>(numerator) / static_cast<float>(denominator);
        float fVal = static_cast<float>(frac.numerator) / static_cast<float>(frac.denominator);
        thisVal*=1000;
        fVal*=1000;
        return (int)thisVal==(int)fVal;
    }

    bool operator==(const Fraction& frac, float num)
    {
        return frac == Fraction(num);
    }

    bool operator==(float num, const Fraction& frac)
    {
        return Fraction(num) == frac;
    }
}