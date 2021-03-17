#include "Complex.h"
#include <sstream>
#include <cstdlib>
#include <cmath>

Complex::Complex(){
  a = 0;
  b = 0;
}

Complex::Complex(double newA){
  a = newA;
  b = 0;
}

Complex::Complex(double newA, double newB){
  a = newA;
  b = newB;
}

double Complex::getRealPart() const{
  return a;
}

double Complex::getImaginaryPart() const{
  return b;
}

Complex Complex::add(const Complex& secondComplex) const
{
  double c = a + secondComplex.getRealPart();
  double d = b + secondComplex.getImaginaryPart();
  return Complex(c, d);
}

Complex Complex::subtract(const Complex& secondComplex) const
{
  double c = a - secondComplex.getRealPart();
  double d = b - secondComplex.getImaginaryPart();
  return Complex(c, d);
}

Complex Complex::multiply(const Complex& secondComplex) const
{
  double c = a * secondComplex.getRealPart() - b * secondComplex.getImaginaryPart();
  double d = b * secondComplex.getRealPart() + a * secondComplex.getImaginaryPart();
  return Complex(c, d);
}

Complex Complex::divide(const Complex& secondComplex) const
{
  double c = secondComplex.getRealPart();
  double d = secondComplex.getImaginaryPart();
  double newA = (a*c+b*d)/(pow(c,2)+pow(d,2));
  double newB = (b*c-a*d)/(pow(c,2)+pow(d,2));
  return Complex(newA, newB);
}

string Complex::toString() const
{
  stringstream ss;
  ss << a;
  if (b != 0){
  ss << " + " << b << "i";
  }

  return ss.str();
}

double Complex::abs() const{
  return sqrt(pow(a,2)+pow(b,2));
}

Complex Complex::operator+(const Complex& c2){
  return this->add(c2);
}

Complex Complex::operator-(const Complex& c2){
  return this->subtract(c2);
}

Complex Complex::operator*(const Complex& c2){
  return this->multiply(c2);
}

Complex Complex::operator/(const Complex& c2){
  return this->divide(c2);
}

Complex Complex::operator+=(const Complex& c2){
  *this = this->add(c2);
  return *this;
}

Complex Complex::operator-=(const Complex& c2){
  *this = this->subtract(c2);
  return *this;
}

Complex Complex::operator*=(const Complex& c2){
  *this = this->multiply(c2);
  return *this;
}

double& Complex::operator[](int index){
  if (index==0){
    return a;
  }else{
    return b;
  }
}

Complex& Complex::operator++(){
  a += 1;
  return *this;
}

Complex& Complex::operator--(){
  a -= 1;
  return *this;
}

Complex Complex::operator++(int dummy){
  Complex temp(a, b);
  a=a+1;
  return temp;
}

Complex Complex::operator--(int dummy){
  Complex temp(a, b);
  a=a-1;
  return temp;
}

Complex Complex::operator+(){
  return *this;
}

Complex Complex::operator-(){
  return Complex(-a, b);
}

ostream& operator<<(ostream& out, const Complex& c1){
  if(c1.getImaginaryPart() == 0){
    out << c1.getRealPart();
  }else{
    out << c1.getRealPart() << " + " << c1.getImaginaryPart() << "i";
  }
  return out;
}

istream& operator>>(istream& in, Complex& c1){
  cout << "Enter real part: ";
  in>>c1.a;
  cout << "Enter imaginary part: ";
  in>>c1.b;
  return in;
}

Complex operator+(const Complex& firstComplex, const Complex& secondComplex){
  return firstComplex.add(secondComplex);
}

Complex operator-(const Complex& firstComplex, const Complex& secondComplex){
  return firstComplex.subtract(secondComplex);
}

Complex operator*(const Complex& firstComplex, const Complex& secondComplex){
  return firstComplex.multiply(secondComplex);
}

Complex operator/(const Complex& firstComplex, const Complex& secondComplex){
  return firstComplex.divide(secondComplex);
}
