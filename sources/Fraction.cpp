#include "Fraction.hpp" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    Fraction::Fraction(int nume,int denom):numerator(nume),denominator(denom)
    {
        if (denominator == 0){
            throw runtime_error("cannot divide by 0");
        }
        this->reduce();
    }
    Fraction::Fraction(float num)
    {
        this->denominator=1000;
        this->numerator = (int)(num*1000);
        this->reduce();
    }
    void Fraction::reduce(){
    this->denominator = 1;
    }
    Fraction operator-(const Fraction &frac){
        return Fraction(0);
    }
    Fraction operator+(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return Fraction(0);
    }
    bool operator==(const Fraction& fraction1, const Fraction& fraction2 ){
        return true;
    }
    bool operator<=(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return true;
    }
    bool operator>=(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return true;
    }
    bool operator<(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return true;
    }
    bool operator>(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return true;
    }
    Fraction operator-(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return Fraction(0);
    }
    Fraction operator*(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return Fraction(0);
    }
    Fraction operator/(const Fraction& fraction1 ,const Fraction& fraction2) {
        return Fraction(0);
    }
    Fraction operator++(const Fraction& fraction ){
        return Fraction(0);
    }
    Fraction operator--(const Fraction& fraction ){
        return Fraction(0);
    }
    Fraction operator++(const Fraction& fraction ,int){
        return Fraction(0);
    }
    Fraction operator--(const Fraction& fraction, int){
        return Fraction(0);
    }
    ostream& operator<<(ostream& os, const Fraction& fraction ){
        return os<<"default default";
    }
    istream & operator >> (istream &in,  Fraction &fraction){
        in>>fraction.denominator;
        in>>fraction.numerator;
        return in;
    }
    
    
} // namespace 
