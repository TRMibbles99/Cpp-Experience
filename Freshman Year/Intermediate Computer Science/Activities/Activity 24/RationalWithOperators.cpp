#include "RationalWithOperators.h"
#include <sstream> // Used in toString to convert numbers to strings
#include <cstdlib> // For the abs function
Rational::Rational()
{
  numerator = 0;
  denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
  int factor = gcd(numerator, denominator);
  this->numerator = (denominator > 0 ? 1 : -1) * numerator / factor;
  this->denominator = abs(denominator) / factor;
}

int Rational::getNumerator() const
{
  return numerator;
}

int Rational::getDenominator() const
{
  return denominator;
}

// Find GCD of two numbers
int Rational::gcd(int n, int d)
{
  int n1 = abs(n);
  int n2 = abs(d);
  int gcd = 1;

  for (int k = 1; k <= n1 && k <= n2; k++)
  {
    if (n1 % k == 0 && n2 % k == 0)
      gcd = k;
  }

  return gcd;
}

Rational Rational::add(const Rational& secondRational) const
{
  int n = numerator * secondRational.getDenominator() +
    denominator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::subtract(const Rational& secondRational) const
{
  int n = numerator * secondRational.getDenominator()
    - denominator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::multiply(const Rational& secondRational) const
{
  int n = numerator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::divide(const Rational& secondRational) const
{
  int n = numerator * secondRational.getDenominator();
  int d = denominator * secondRational.numerator;
  return Rational(n, d);
}

int Rational::compareTo(const Rational& secondRational) const
{
  Rational temp = subtract(secondRational);
  if (temp.getNumerator() < 0)
    return -1;
  else if (temp.getNumerator() == 0)
    return 0;
  else
    return 1;
}

bool Rational::equals(const Rational& secondRational) const
{
  if (compareTo(secondRational) == 0)
    return true;
  else
    return false;
}

int Rational::intValue() const
{
  return getNumerator() / getDenominator();
}

double Rational::doubleValue() const
{
  return 1.0 * getNumerator() / getDenominator();
}

string Rational::toString() const
{
  stringstream ss;
  ss << numerator;

  if (denominator > 1)
    ss << "/" << denominator;

  return ss.str();
}

Rational::Rational(int numerator) // Suitable for type conversion
{
  this->numerator = numerator;
  this->denominator = 1;
}

bool Rational::operator<(const Rational& r2)
{
    return (compareTo(r2) < 0);
}

Rational Rational::operator+(const Rational& r2)
{
    return this->add(r2);
}

Rational Rational::operator-(const Rational& r2)
{
    return this->subtract(r2);
}

Rational Rational::operator*(const Rational& r2)
{
    return this->multiply(r2);
}

Rational Rational::operator/(const Rational& r2)
{
    return this->divide(r2);
}

// Define function operators for augmented operators
Rational& Rational::operator+=(const Rational& secondRational)
{
  *this = this->add(secondRational);
  return *this;
}

// Define function operator []
int& Rational::operator[](int index)
{
  if (index == 0)
    return numerator;
  else
    return denominator;
}

// Define function operators for prefix ++ and --
Rational& Rational::operator++()
{
  numerator += denominator;
  return *this;
}

Rational& Rational::operator--()
{
  numerator -= denominator;
  return *this;
}

// Define function operators for postfix ++ and --
Rational Rational::operator++(int dummy)
{
  Rational temp(numerator, denominator);
  numerator += denominator;
  return temp;
}

Rational Rational::operator--(int dummy)
{
  Rational temp(numerator, denominator);
  numerator -= denominator;
  return temp;
}

// Define function operators for unary + and -
Rational Rational::operator+()
{
  return *this;
}

Rational Rational::operator-()
{
  return Rational(-numerator, denominator);
}


ostream& operator<<(ostream& out, const Rational& r1){
  if (r1.getDenominator()==1){
    out << r1.getNumerator();
  }else{
    out << r1.getNumerator() << "/" << r1.getDenominator();
  }
  return out;
}

istream& operator>>(istream& in, Rational& r1){
  cout << "Enter numerator: ";
  in>>r1.numerator;
  cout << "Enter denominator: ";
  in>>r1.denominator;
  return in;
}

Rational operator+(const Rational& firstRational, const Rational& secondRational){
  return firstRational.add(secondRational);
}

Rational operator-(const Rational& firstRational, const Rational& secondRational){
  return firstRational.subtract(secondRational);
}

Rational operator*(const Rational& firstRational, const Rational& secondRational){
  return firstRational.multiply(secondRational);
}

Rational operator/(const Rational& firstRational, const Rational& secondRational){
  return firstRational.divide(secondRational);
}
