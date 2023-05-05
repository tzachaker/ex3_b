#ifndef FRACTION_HPP
#define FRACTION_HPP
#include "Fraction.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel{

    class Fraction{
        private:
            int numerator; 
            int denominator; 

        public:
            Fraction(): numerator(0), denominator(1){}
            Fraction(float num);
            Fraction(int num,int den);

            int getNumerator();
            int getDenominator();

            int gcd(int num, int den);
            float convert_frac_to_float(Fraction frac) const;

            // friend global IO operators
            friend std::ostream& operator<< (std::ostream& output, const Fraction& frac);
            friend std::istream& operator>> (std::istream& input , Fraction& frac);
        
            Fraction operator+(const Fraction& frac);
            // Fraction operator+(float num);
            // friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
            // friend Fraction operator+(const Fraction& frac, float num);
            friend Fraction operator+(float num, const Fraction& frac);

            Fraction operator-(const Fraction& frac);
            // Fraction operator-(float num);
            // friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
            // friend Fraction operator-(const Fraction& frac, float num);
            friend Fraction operator-(float num, const Fraction& frac);

            Fraction operator*(const Fraction& frac);
            // Fraction operator*(float num);
            // friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
            // friend Fraction operator*(const Fraction& frac, float num);  
            friend Fraction operator*(float num, const Fraction& frac);  

            Fraction operator/(const Fraction& frac);
            // Fraction operator/(float num);
            // friend Fraction operator/(const Fraction& frac1, const Fraction& frac2);
            // friend Fraction operator/(const Fraction& frac, float num);
            friend Fraction operator/(float num, const Fraction& frac);

            // prefix increment:
            Fraction operator++();
            // postfix increment:
            Fraction operator++(int);
            // prefix decrement:
            Fraction operator--();
            // postfix decrement:
            Fraction operator--(int);

            bool operator>(const Fraction& frac) const;
            // bool operator>(float num);
            friend bool operator>(const Fraction &frac, float num);
            friend bool operator>(float num, const Fraction &frac);

            bool operator<(const Fraction& frac) const;
            // bool operator<(float num);
            friend bool operator<(const Fraction &frac, float num);
            friend bool operator<(float num, const Fraction &frac);

            bool operator>=(const Fraction& frac) const;
            // bool operator>=(float num);
            friend bool operator>=(const Fraction &frac,float num);
            friend bool operator>=(float num, const Fraction &frac);

            bool operator<=(const Fraction& frac) const;
            // bool operator<=(float num);
            friend bool operator<=(const Fraction &frac,float num);
            friend bool operator<=(float num, const Fraction &frac);

            bool operator==(const Fraction& frac) const;
            // bool operator==(float num);
            friend bool operator==(const Fraction &frac, float num);
            friend bool operator==(float num, const Fraction &frac);
    };
}
#endif