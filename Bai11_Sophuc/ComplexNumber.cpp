#include "ComplexNumber.h"
#include <iostream>
#include <string>

using namespace std;


void checkFormatInput(const string &input)
{
    int countError1 = 0;
    
    //fist elemet must not be a dot
    if ((int(input[0]) > 57 || int(input[0]) < 48) && int(input[0]) != 45) 
    {
        throw "error format input..."; 
    }
    //if fist elemet is a minus sign, second elemet must not be a dot
    else if (int(input[0]) == 45 && int(input[1]) == 46)  
    {
        throw "error format input...";
    }

    //from second element, string just have only numeric character or dot
    for (int i = 1; i < input.size(); i++)
    {   
        if ((int(input[i]) > 57 || int(input[i]) < 48) && input[i] != 46)
        {
            throw "error format input...";
        }
        if (input[i] == 46)
        {
            ++countError1;
        }
        
    }
    //if in string have sum of dot greater than 1, throw exception
    if (countError1 > 1)
    {
        throw "error format input...";
    }
}
ComplexNumber::ComplexNumber()
{
}
ComplexNumber::ComplexNumber(double real, double imaginary)
{
    ComplexNumber ::real = real;
    ComplexNumber :: imaginary = imaginary;
}

//check format for imaginary part and real part
void ComplexNumber ::input()
{
    string real, imaginary;
    try
    {
        cout << "enter real part: ";
        cin >> real;
        checkFormatInput(real);
        cout << "enter imaginary part: ";
        cin >> imaginary;
        checkFormatInput(imaginary);
        this->real = stod(real);
        this->imaginary = stod(imaginary);
    }
    catch (const char *error)
    {
        cout << error << endl;
        exit(0);
    }
}

double ComplexNumber :: getRealPart()
{
    return real;
}

double ComplexNumber :: getImaPart()
{
    return imaginary;
}

ComplexNumber ComplexNumber :: operator+(ComplexNumber &complexNumber1)
{
    double a = this->real + complexNumber1.getRealPart();
    double b = this->imaginary + complexNumber1.getImaPart();
    return ComplexNumber(a, b);
}
ComplexNumber ComplexNumber :: operator*(ComplexNumber &complexNumber2)
{
    double a = this->real * complexNumber2.getRealPart() - this->imaginary * complexNumber2.getImaPart();
    double b = this->real * complexNumber2.getImaPart() + this->imaginary * complexNumber2.getRealPart();
    return ComplexNumber(a, b);
}
void ComplexNumber :: output()
{
    if (real == 0 && imaginary == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        if (imaginary == 0)
        {
            cout << real << endl;
        }
        else if (real == 0)
        {
            cout << imaginary << "i" << endl;
        }
        else if (imaginary < 0)
        {
            cout << real << " " << imaginary << "i" << endl;
        }
        else
        {
            cout << real << " +" << imaginary << "i" << endl;
        }
    }
}
