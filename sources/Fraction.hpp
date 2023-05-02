namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
        void reduce();
    public:
        Fraction(int nume,int denom);
        Fraction(float number);
        friend Fraction operator+(const Fraction&,const Fraction&);
        friend bool operator==(const Fraction&,const Fraction&);
        friend Fraction operator-(const Fraction&,const Fraction&);
        friend Fraction operator*(const Fraction&,const Fraction&);
        friend Fraction operator/(const Fraction&,const Fraction&);
        friend Fraction operator++(const Fraction&);
        friend Fraction operator--(const Fraction&);
        friend Fraction operator++(const Fraction&,int);
        friend Fraction operator--(const Fraction&,int);
        friend ostream& operator<<(ostream& os, const Fraction&);
    };
    
    
} 