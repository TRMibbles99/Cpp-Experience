#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>
#include <iostream>
using namespace std;

class Complex{
private:
  double a;
  double b;

public:
  Complex();
  Complex(double);
  Complex(double, double);

  double getRealPart() const;
  double getImaginaryPart() const;

  Complex add(const Complex& secondComplex) const;
  Complex subtract(const Complex& secondComplex) const;
  Complex multiply(const Complex& secondComplex) const;
  Complex divide(const Complex& secondComplex) const;

  string toString() const;

  double abs() const;

  Complex operator+(const Complex& secondComplex);
  Complex operator-(const Complex& secondComplex);
  Complex operator*(const Complex& secondComplex);
  Complex operator/(const Complex& secondComplex);

  Complex operator+=(const Complex& secondComplex);
  Complex operator-=(const Complex& secondComplex);
  Complex operator*=(const Complex& secondComplex);

  double& operator[](int index);

  Complex& operator++();
  Complex& operator--();

  Complex operator++(int dummy);
  Complex operator--(int dummy);

  Complex operator+();
  Complex operator-();

  friend istream& operator>>(istream&, Complex&);
};

ostream& operator<<(ostream&, const Complex&);
Complex operator+(const Complex& firstComplex, const Complex& secondComplex);
Complex operator-(const Complex& firstComplex, const Complex& secondComplex);
Complex operator*(const Complex& firstComplex, const Complex& secondComplex);
Complex operator/(const Complex& firstComplex, const Complex& secondComplex);


#endif
