#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "chrono"
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;
#include "doctest.h"
TEST_CASE("check divison by zero"){
    CHECK_THROWS(Fraction(1,0));
    Fraction nonzero = Fraction(1,1),zero = Fraction(1,0);
    CHECK_THROWS(nonzero/0);
    CHECK_THROWS(nonzero/zero);
    CHECK_THROWS(1/zero);
}
TEST_CASE("check field axioms"){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    srand((unsigned) time(NULL));
	SUBCASE("commutativity for addition"){
        for (int i = 0; i < 10; i++)
        {
            Fraction a= Fraction(rand()%256,rand()%256);
            Fraction b= Fraction(rand()%256,rand()%256);
            CHECK_EQ(a+b,b+a);
            
        }
    }
    SUBCASE("commutativity for multiplication"){
        for (int i = 0; i < 10; i++)
        {
            Fraction a= Fraction(rand()%256,rand()%256);
            Fraction b= Fraction(rand()%256,rand()%256);
            CHECK_EQ(a*b,b*a);
            
        }
    }
    SUBCASE("inverse for addition"){
        for (int i = 0; i < 10; i++)
        {
            int denom = rand()%256, numer=rand()%256;
            Fraction a= Fraction(numer,denom);
            Fraction b= Fraction(-numer,denom);
            CHECK_EQ(a+b,0);
            //b=-a;
            //CHECK_EQ(a+b,0);
        }
    }
}