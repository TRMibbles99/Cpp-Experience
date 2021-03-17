#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "set_empty.cpp"
using namespace std;

int main(){

  string name;
  string party;
  string state;
  string religion;
  string age;

  Set<string> VA;
  Set<string> NY;
  Set<string> MA;
  Set<string> OH;
  Set<string> OtherState;
  Set<string> Episcopalian;
  Set<string> Presbyterian;
  Set<string> Methodist;
  Set<string> OtherReligion;
  Set<string> forties;
  Set<string> fifties;
  Set<string> sixties;
  Set<string> Whig;
  Set<string> Democrat;
  Set<string> Republican;
  Set<string> DR;
  Set<string> OtherParty;

  string fileName = "pres.txt";
  ifstream input(fileName);
  while(!input.eof()){
    getline(input, name, '\t');
    getline(input, party, '\t');
    getline(input, state, '\t');
    getline(input, religion, '\t');
    getline(input, age, '\n');

    if(state == "VA"){
      VA.insert(name);
    }else if(state == "NY"){
      NY.insert(name);
    }else if(state == "MA"){
      MA.insert(name);
    }else if(state == "OH"){
      OH.insert(name);
    }else{
      OtherState.insert(name);
    }

    if(religion == "Episcopalian"){
      Episcopalian.insert(name);
    }else if(religion == "Presbyterian"){
      Presbyterian.insert(name);
    }else if(religion == "Methodist"){
      Methodist.insert(name);
    }else{
      OtherReligion.insert(name);
    }

    if(age.substr(0,1) == "4"){
      forties.insert(name);
    }else if(age.substr(0,1) == "5"){
      fifties.insert(name);
    }else if(age.substr(0,1) == "6"){
      sixties.insert(name);
    }

    if(party == "(W)"){
      Whig.insert(name);
    } else if(party == "(D)"){
      Democrat.insert(name);
    } else if(party == "(R)"){
      Republican.insert(name);
    } else if(party == "(DR)"){
      DR.insert(name);
    }else {
      OtherParty.insert(name);
    }
  }
  input.close();

  Set<string> OHMeth;
  OHMeth = OH & Methodist;
  cout << "Methodist Ohioians: " << OHMeth << endl;

  Set<string> VAEpisWhig;
  VAEpisWhig = VA & Episcopalian;
  VAEpisWhig = VAEpisWhig & Whig;
  cout << "VA, Episcopalian, and Whig: " << VAEpisWhig << endl;

  Set<string> WhigDR;
  WhigDR = Whig + DR;
  cout << "Whig or DR: " << WhigDR << endl;

  cout << "Presidents in 40s: " << forties << endl;
  return 0;
}
