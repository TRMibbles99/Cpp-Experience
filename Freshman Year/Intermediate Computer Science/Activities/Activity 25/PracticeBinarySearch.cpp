/*
 * File: BinarySearch.cpp
 * ----------------------
 * Implementation of binary search.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Function prototypes */

void initCityNames(vector<string> & cities);
int binarySearch(string key, vector<string> & vec);
int binarySearch(string key, vector<string> & vec, int p1, int p2, int counter);

/* Main program */

int main() {
   vector<string> cities;
   initCityNames(cities);
   for(string city : cities) {
      int index = binarySearch(city, cities);
      cout << city << " == " << cities[index] << endl;
   }
   return 0;
}

/*
 * Function: initCityNames
 * Usage: initCityNames(cities);
 * -----------------------------
 * Initializes the cities vector to the cities in the board game Ticket
 * to Ride Europe by Alan Moon.
 */

void initCityNames(vector<string> & cities) {
   cities = {"Amsterdam", "Angora", "Athina", "Barcelona", "Berlin",
             "Brest", "Brindisi", "Bruxelles", "Bucuresti", "Budapest",
             "Cadiz","Danzig", "Dieppe", "Edinburgh",
             "Erzurum", "Essen", "Frankfurt", "Istanbul", "Kharkov", "Kobenhavn",
             "Kyiv", "Lisboa", "London", "Madrid", "Marseille", "Moskva",
             "Munchen", "Palermo", "Pamplona", "Paris", "Petrograd",
             "Riga", "Roma", "Rostov", "Sarajevo", "Sevastopol",
             "Smolensk", "Smyrna", "Sochi", "Sofia", "Stockholm",
             "Venezia", "Warszawa", "Wien", "Wilno", "Zagrab", "Zurich"};
}

/*
 * Function: findInSortedVector
 * Usage: int index = findInSortedVector(key, vec);
 * ------------------------------------------------
 * Searches for the specified key in the vector<string> vec, which
 * must be sorted in lexicographic (character code) order.  If the
 * key is found, the function returns the index in the vector at
 * which that key appears. (If the key appears more than once in
 * the vector, any of the matching indices may be returned).  If the
 * key does not exist in the vector, the function returns -1.  This
 * implementation is simply a wrapper function; all of the real work
 * is done by the more general binarySearch function.
 */

int binarySearch(string key, vector<string> & vec) {

   // call binarySearch function with the key, vec and initial fist and last index of the vec
   return binarySearch(key, vec, 0, vec.size()-1, 1);
}

/*
 * Function: binarySearch
 * Usage: int index = binarySearch(key, vec, p1, p2);
 * --------------------------------------------------
 * Searches for the specified key in the vector<string> vec, looking
 * only at indices between p1 and p2, inclusive.  The function returns
 * the index of a matching element, or -1 if no match is found.
 */
//attendeance assig: how many calls did binarysearch do for finding each element?
int binarySearch(string key, vector<string> & vec, int p1, int p2, int counter) {
  if(p1>p2){
    cout << "Total="<<counter<<endl;
    return -1;
  }

  int mid = (p1+p2)/2;
  if (key==vec[mid]){
    cout << "Total="<<counter<<endl;
    return mid;
  }else if(key > vec[mid]){
    counter++;
    return binarySearch(key, vec, mid+1, p2, counter++);
  }else{
    counter++;
    return binarySearch(key, vec, p1, mid-1, counter++);
  }
}
