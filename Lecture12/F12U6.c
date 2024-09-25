#include <stdio.h>
#include <math.h>

struct complexNumber
{
    float real;
    float imaginary;
};
typedef struct complexNumber ComplexNumber;

ComplexNumber funcCreateComplex(float real, float imaginary);
void funcPrintComplex(ComplexNumber number);
void funcMultiplyComplex(ComplexNumber *complexNumber, float decimalNumber);
int funcEquals(ComplexNumber complexNumber1, ComplexNumber complexNumber2);

int main()
{
    ComplexNumber c1 = funcCreateComplex(3, +2);
    ComplexNumber c2 = funcCreateComplex(2, -3);

    funcMultiplyComplex(&c1, -2.5);
    funcMultiplyComplex(&c2, -1);

    funcPrintComplex(c1);
    funcPrintComplex(c2);

    printf("\n%d", funcEquals(c1, c2));

    return 0;
}

ComplexNumber funcCreateComplex(float real, float imaginary)
{
    ComplexNumber newComplexNumber;

    newComplexNumber.real = real;
    newComplexNumber.imaginary = imaginary;

    return newComplexNumber;
}

void funcPrintComplex(ComplexNumber number)
{
    char temp = '+';

    if (number.imaginary < 0)
    {
        temp = '-';
        number.imaginary = sqrt(number.imaginary * number.imaginary);
    }

    printf("\n%0.4f %c %0.4fi", number.real, temp, number.imaginary);
}

void funcMultiplyComplex(ComplexNumber *complexNumber, float decimalNumber)
{
    complexNumber->real = complexNumber->real * decimalNumber;
    complexNumber->imaginary = complexNumber->imaginary * decimalNumber;
}

int funcEquals(ComplexNumber complexNumber1, ComplexNumber complexNumber2)
{
    if (complexNumber1.real == complexNumber2.real && complexNumber1.imaginary == complexNumber2.imaginary)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
