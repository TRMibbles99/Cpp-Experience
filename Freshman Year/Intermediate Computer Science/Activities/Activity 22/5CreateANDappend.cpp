#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  ofstream output;

  // Create a file
  output.open("Grades.txt", ios::out | ios::app);

  srand(time(0));

  for (int i = 100; i < 110; i++)
  {
    output << "CS"<<i<<" "<<rand()%100 <<" "<<(1.0)*rand()/RAND_MAX<<"\n";
  }

  output.close();

  cout << "Done" << endl;

  return 0;
}
