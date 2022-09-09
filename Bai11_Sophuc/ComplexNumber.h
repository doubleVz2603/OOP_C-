#ifndef COMPLEXNUMBER_H_INCLUDED
#define COMPLEXNUMBER_H_INCLUDED


using namespace std;
class ComplexNumber
{
private:
    double real, imaginary;
public:

    ComplexNumber();
    ComplexNumber(double, double);
    
    void input();
    double getRealPart();
    double getImaPart();
    ComplexNumber operator+(ComplexNumber &);
    ComplexNumber operator*(ComplexNumber &);
    void output();
};

#endif