#include <iostream>
#include <fstream>
#include <string>
#include <sys/time.h>
#include "hash.cpp"
#include "dict.cpp"
#include "movie.h"
using namespace std;

Dictionary<Movie> getMovieDict(string fileName, int slots){
  string title;
  string actors;
  Dictionary<Movie> movies(slots);

  //timeval timeBef, timeAf;
  //long diffSec, diffUSec;

  //gettimeofday(&timeBef, NULL);
  ifstream file(fileName);
  while(!file.eof()){
    getline(file, title, '\t');
    getline(file, actors, '\n');

    Movie *m = new Movie(title, actors, slots);
    movies.insert(m);

  }
  file.close();
  //gettimeofday(&timeAf, NULL);

  //diffSec = timeAf.tv_sec - timeBef.tv_sec;
  //diffUSec = timeAf.tv_usec - timeBef.tv_usec;
  //cout << diffSec + diffUSec/1000000.0 << endl;

  return movies;
}

string getMovie(){
  string title;
  getline(cin, title);
  return title;
}

int main(){
  int slots = 1000;
  Dictionary<Movie> movies = getMovieDict("movies_mpaa.txt", slots);

  string title = getMovie();

  cout << *(movies.get(Movie(title, slots))) << endl;

  return 0;
}
