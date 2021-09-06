#include <sstream>
#include <iostream>

class Movie
{
public:
  string title;
  string actors;

  Movie(){
    title = "";
    actors = "";
  }

  Movie(string name, string actor){
    title = name;
    actors = actor;
  }

  Movie(string name){
    title = name;
    actors = "";
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

  friend ostream& operator<<(ostream& stream, const Movie& m){
    stream << m.actors;
    return stream;
  }
};
