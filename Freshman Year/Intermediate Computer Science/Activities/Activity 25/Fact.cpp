/*
 * File: Fact.cpp
 * --------------
 * This file generates a list of factorials.  The test program
 * stops when the value of fact(n) is smaller than its predecessor,
 * which means that an overflow must have occurred.
 */

#include <iostream>
#include <iomanip>
using namespace std;

/* Function prototypes */

int factR(int n);
int factI(int n);

/* Main program */

int main() {
   for (int i = 0; i < 2 || factR(i) > factR(i - 1); i++) {
      cout << setw(2) << i << "! = " << setw(10) << factR(i) << endl;
   }

   for (int i = 0; i < 2 || factI(i) > factI(i - 1); i++) {
      cout << setw(2) << i << "! = " << setw(10) << factI(i) << endl;
   }
   return 0;
}

/*
 * Function: fact
 * Usage: int nfact = fact(n);
 * ---------------------------
 * Computes the factorial of n using the following recursive
 * formulation:
 *
 *    fact(0) = 1
 *    fact(n) = n * fact(n - 1)
 */

int factR(int n) {
  if(n==0){
    return 1;
  }else{
    return n*factR(n-1);
  }
}
// iterative factorial
int factI(int n) {
  int result = 1;
  for(int i = 1; i<=n; i++){
    result*=1;
  }
  return result;
}
