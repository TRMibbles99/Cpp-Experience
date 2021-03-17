#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
using namespace std;

class Rational
{
public:
  Rational();
  Rational(int numerator, int denominator);
  int getNumerator() const;
  int getDenominator() const;
  Rational add(const Rational& secondRational) const;
  Rational subtract(const Rational& secondRational) const;
  Rational multiply(const Rational& secondRational) const;
  Rational divide(const Rational& secondRational) const;
  int compareTo(const Rational& secondRational) const;
  bool equals(const Rational& secondRational) const;
  int intValue() const;
  double doubleValue() const;
  string toString() const;
  //define functionoperator for comparison
  bool operator<(const Rational& r2);

  //define function operator for arithmetic calculation
  Rational operator+(const Rational& r2);
  Rational operator-(const Rational& r2);
  Rational operator*(const Rational& r2);
  Rational operator/(const Rational& r2);

  //define function operator for augmented operator
  Rational & operator+=(const Rational& r2);

  // define function operator []
  int & operator[](int index);

  //prefix y=++a
  Rational & operator++();
  Rational & operator--();
  // postfix y=a++
  Rational & operator++(int dummy);
  Rational & operator--(int dummy);
  // 5  -5  a`-a  +a
  Rational operator+();
  Rational operator-();


private:
  int numerator;
  int denominator;
  static int gcd(int n, int d);
};

#endif
