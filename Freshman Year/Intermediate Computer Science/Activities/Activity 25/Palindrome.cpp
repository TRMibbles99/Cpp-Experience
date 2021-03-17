/*
 * File: Palindrome.cpp
 * --------------------
 * This program tests for palindromes, which are strings that read the same
 * same backwards and forwards, such as "LEVEL" or "NOON".
 */

#include <iostream>
#include <string>
using namespace std;

/* Function prototypes */

void testPalindrome(string str);
bool isPalindrome1(string str);
bool isPalindrome2(string str,int p1, int p2);
bool isPalindrome2(string str);


/* Main program */

int main() {
   testPalindrome("");
   testPalindrome("x");
   testPalindrome("level");
   testPalindrome("noon");
   testPalindrome("abcdefghgfedcba");
   testPalindrome("0123443210");
   testPalindrome("xyzzy");
   return 0;
}

/*
 * Function: testPalindrome
 * Usage: testPalindrome(str);
 * ---------------------------
 * Tests if the specified string is a palindrome and reports the results.
 */

void testPalindrome(string str) {
   cout << "isPalindrome1(\"" << str << "\") -> ";
   cout << (isPalindrome1(str) ? "true" : "false" ) << endl;

   cout << "isPalindrome2(\"" << str << "\") -> ";
   cout << (isPalindrome2(str) ? "true" : "false" ) << endl;
}

bool isPalindrome2(string str){
  return isPalindrome2(str, 0, str.length());
}
/*
 * Function: isPalindrome
 * Usage: if (isPalindrome(str)) . . .
 * -----------------------------------
 * Returns true if str is a palindrome, which is a string that
 * reads the same backwards and forwards.  This implementation
 * uses the recursive insight that all strings of length 0 or 1
 * are palindromes and that longer strings are palindromes if
 * their first and last characters match and the remaining substring
 * is a palindrome.
 */

bool isPalindrome1(string str) {
  int len = str.length();
  if(len<=1){
    return true;
  }else{
    return str[0]==str[len-1] && isPalindrome1(str.substr(1,len-2));
  }

}


bool isPalindrome2(string str, int p1, int p2) {

  if(p1>=p2){
    return true;
  }else{
    return str[p1] == str[p2] && isPalindrome2(str, p1+1, p2-1);
  }

}
