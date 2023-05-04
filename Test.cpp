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
            Fraction a= Fraction(rand()%256,rand()%256+1);
            Fraction b= Fraction(rand()%256,rand()%256+1);
            CHECK_EQ(a+b,b+a);
            
        }
    }
    SUBCASE("commutativity for multiplication"){
        for (int i = 0; i < 10; i++)
        {
            Fraction a= Fraction(rand()%256,rand()%256+1);
            Fraction b= Fraction(rand()%256,rand()%256+1);
            CHECK_EQ(a*b,b*a);
            
        }
    }
    SUBCASE("identity"){
        for (int i = 0; i < 10; i++)
        {
            int aSign = (rand()%2)*2-1;
            int denom = rand()%256+1, numer=aSign*(rand()%256);
            Fraction a= Fraction(numer,denom);
            Fraction b= Fraction(1,1);
            CHECK_EQ(a*b,a);
            b = Fraction(0,1);
            CHECK_EQ(a+b,a);
        }
    }
    SUBCASE("inverse for addition"){
        for (int i = 0; i < 10; i++)
        {
            int aSign = (rand()%2)*2-1;
            int denom = rand()%256+1, numer=aSign*(rand()%256);
            Fraction a= Fraction(numer,denom);
            Fraction b= Fraction(-numer,denom);
            CHECK_EQ(a+b,0);
            b=-a;
            CHECK_EQ(a+b,0);
        }
    }
    SUBCASE("inverse for multiplication"){
        for (int i = 0; i < 10; i++)
        {
            int aSign = (rand()%2)*2-1;
            int denom = rand()%256+1, numer=aSign*(rand()%256);
            Fraction a= Fraction(numer,denom);
            Fraction b= Fraction(-numer,denom);
            CHECK_EQ(a*b,1);
            b = 1/a;
            CHECK_EQ(a*b,1);
        }
    }
    SUBCASE("associativity"){
         for (int i = 0; i < 10; i++)
        {
            int cSign = (rand()%2)*2-1;
            int bSign = (rand()%2)*2-1;
            int aSign = (rand()%2)*2-1;
            Fraction a= Fraction(aSign*(rand()%256),rand()%256+1);
            Fraction b= Fraction(bSign*(rand()%256),rand()%256+1);
            Fraction c= Fraction(cSign*(rand()%256),rand()%256+1);
            CHECK_EQ((a*b)*c,a*(b*c));
        }
    }
    SUBCASE("distirbutivity"){
        for (int i = 0; i < 10; i++)
        {
            int cSign = (rand()%2)*2-1;
            int bSign = (rand()%2)*2-1;
            int aSign = (rand()%2)*2-1;
            Fraction a= Fraction(aSign*(rand()%256),rand()%256+1);
            Fraction b= Fraction(bSign*(rand()%256),rand()%256+1);
            Fraction c= Fraction(cSign*(rand()%256),rand()%256+1);
            CHECK_EQ(a*(b+c),a*b+a*c);

        }
    }
}
TEST_CASE("reduction"){
    Fraction a = Fraction(69,23);
    CHECK(a.numerator==1);
    CHECK( a.denominator==3);
     a = Fraction(390,-234);
    CHECK(a.numerator==-5);
    CHECK(a.denominator==3);
    a =Fraction(2,4);
    CHECK(a.numerator==1) ;
    CHECK(a.denominator==2);
}
TEST_CASE("conversion"){
    SUBCASE("straight conversion"){
    double a= 0.1;
    int b =5;
    float c = 78.996;
    Fraction fractin1 = a;
    CHECK_EQ(fractin1,Fraction(1,10));
    fractin1 =b;
    CHECK_EQ(fractin1,Fraction(5,1));
    fractin1 =c;
    CHECK_EQ(fractin1,Fraction(78966,1000));
    }
    SUBCASE("arithmetic"){
        Fraction fraction1 = Fraction(1,5);
        int a=3;
        CHECK_EQ(fraction1*a,Fraction(3,5));
        CHECK_EQ(fraction1/a,Fraction(1,15));
        CHECK_EQ(fraction1+a,Fraction(18,5));
        CHECK_EQ(fraction1-a,Fraction(-12,5));
        double c=0.1;
        CHECK_EQ(fraction1*c,Fraction(1,50));
        CHECK_EQ(fraction1/c,Fraction(10,5));
        CHECK_EQ(fraction1+c,Fraction(3,10));
        CHECK_EQ(fraction1-c,Fraction(1,10));
        float b=0.1;
        CHECK_EQ(fraction1*b,Fraction(1,50));
        CHECK_EQ(fraction1/b,Fraction(10,5));
        CHECK_EQ(fraction1+b,Fraction(3,10));
        CHECK_EQ(fraction1-b,Fraction(1,10));

    }
    
}
TEST_CASE("arithmetic"){
        Fraction fraction1 = Fraction(1,5);
        Fraction a= Fraction(3,1);
        CHECK_EQ(fraction1*a,Fraction(3,5));
        CHECK_EQ(fraction1/a,Fraction(1,15));
        CHECK_EQ(fraction1+a,Fraction(18,5));
        CHECK_EQ(fraction1-a,Fraction(-12,5));
        Fraction c= Fraction(1,10);
        CHECK_EQ(fraction1*c,Fraction(1,50));
        CHECK_EQ(fraction1/c,Fraction(10,5));
        CHECK_EQ(fraction1+c,Fraction(3,10));
        CHECK_EQ(fraction1-c,Fraction(1,10));
        Fraction b= Fraction(2,6);
        CHECK_EQ(fraction1*b,Fraction(2,30));
        CHECK_EQ(fraction1/b,Fraction(6,10));
        CHECK_EQ(fraction1+b,Fraction(16,30));
        CHECK_EQ(fraction1-b,Fraction(-4,30));
}

TEST_CASE("inequlities"){
    SUBCASE("equal numbers"){
 CHECK(Fraction(1,6)<=Fraction(1,6));
 CHECK(Fraction(1,6)>=Fraction(1,6));
 CHECK(!(Fraction(1,6)<Fraction(1,6)));
 CHECK(!(Fraction(1,6)>Fraction(1,6)));
 CHECK(Fraction(1,6)<=Fraction(1,6));
 CHECK(Fraction(1,6)>=Fraction(1,6));
 }
 SUBCASE("non equal numbers"){
     CHECK(Fraction(1,6)<=Fraction(1,5));
 CHECK(Fraction(1,5)>=Fraction(1,6));
 CHECK(Fraction(1,6)<Fraction(1,5));
 CHECK(Fraction(1,5)>Fraction(1,6));
CHECK(!(Fraction(1,6)>Fraction(1,5)));
 CHECK(!(Fraction(1,5)<Fraction(1,6)));
 CHECK(!(Fraction(1,6)>=Fraction(1,5)));
 CHECK(!(Fraction(1,5)<=Fraction(1,6)));


 }

}
TEST_CASE("output"){
    CHECK_NOTHROW( cout<< Fraction(-124,124134));
    CHECK_NOTHROW( cout<< Fraction(15,1423));
    CHECK_NOTHROW( cout<< Fraction(6,-124));
}
