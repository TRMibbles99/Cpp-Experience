#include <sstream>
#include <cmath>
#include <iostream>

class Movie
{
public:
  string title;
  string actors;
  int hash;

  Movie(){
    title = "";
    actors = "";
    hash = 0;
  }

  Movie(string name, string actor, int slots){
    title = name;
    actors = actor;
    hash = hashFunction(name, slots);
  }

  Movie(string name, int slots){
    title = name;
    actors = "";
    hash = hashFunction(name, slots);
  }

  int hashFunction(string s, int slots){
    int k = 0;
    char c;

    for(int i = 0; i < s.length(); i++){
      c = s[i];
      k = c * pow(11, i) + k;
    }

    return k % slots;
  }

  bool operator==(const Movie& m) const{
    return (title == m.title);
  }

  bool operator<=(const Movie& m) const{
    return (title <= m.title);
  }

  bool operator<(const Movie& m) const{
    return(title < m.title);
  }

  bool operator>(const Movie& m) const{
    return(title > m.title);
  }

  void operator=(const Movie& m){
    title = m.title;
    actors = m.actors;
    hash = m.hash;
  }

  friend ostream& operator<<(ostream& stream, const Movie& m){
    stream << m.actors;
    return stream;
  }
};
