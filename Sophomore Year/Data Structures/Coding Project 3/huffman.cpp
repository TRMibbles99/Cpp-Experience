//huffman.cpp

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#include <string>
#include "node.h"
#include "pq.h"

// compression
void compression(string fileName, string destination)
{
  int frequency[255] = {0};
  string line;
  string oldFile;
  string codes[255] ={""};
  int index[255] = {0};
  int headerLen = 0;
  string code;
  MinPriorityQueue<Node> pq(255);
  char c;
  Node* nd[255];
  int longest = 0;
  int counter = 0;

  //making list of frequencies
  ifstream file(fileName);
  if (file.tellg() == 1)
  {
      throw "ERROR: file is empty";
  }
  if(file.is_open())
  {
      while(getline(file, line))
      {
        oldFile.append(line);
          for (int i = 0; i < line.length(); i++)
          {
              frequency[line[i]] = frequency[line[i]] + 1;
          }
      }
  }
  else
  {
      cout << "ERROR: Failed to read file." << endl;
  }

  file.close();

  // makes variables needed in order to make the pq

  //puts the nodes into the pq
  for (int i = 0; i < 255; i++)
  {
      if (frequency[i] != 0)
      {
          c = i;
          Node* temp = new Node(c, frequency[i]);
          pq.insert(temp);
      }
  }

  //condense pq
  while (pq.length() > 1)
  {
      Node* z = new Node;
      Node* x = (pq.extractMin());
      Node* y = (pq.extractMin());
      z->leftPtr = x;
      z->rightPtr = y;
      z->freq = -(x->freq + y->freq);
      pq.insert(z);
      //cout << pq << endl;
  }
  // search
  Node* temp(pq.minimum());
  while(temp->leftPtr != NULL){
      codes[temp->rightPtr->C] = code+"0";
      code = code.append("1");

      index[counter] = temp->rightPtr->C;
      counter++;

      temp = temp->leftPtr;
  }
  codes[temp->C] = code;
  index[counter] = temp->C;
  longest = code.length();

  //read into a new file
  string compressed = "";
  ofstream compFile;
  compFile.open(destination);
  compFile << counter << ":" << longest << "\n";
  for(int i = 0; i <= counter; i++){
    c = index[i];
    compFile << c << ":" << codes[index[i]] << "\n";
  }

  for (int i = 0; i < oldFile.length(); i++)
  {
      compressed.append(codes[oldFile[i]]);
  }
  compFile << compressed;

  ///cout << "I ran" << endl;
}



void decompression(string fileName, string destination){
  char c;
  string line;
  int counter;
  int longest;
  string code;
  string current = "";
  string codes[255];

  ifstream file(fileName);
  if(file.is_open())
  {
      string header = "";
      getline(file, header);
      counter = stoi(header.substr(0,header.find(":")));
      longest = stoi(header.substr(header.find(":")+1, header.length()-1));
  }
  else
  {
      cout << "ERROR: Failed to read file." << endl;
  }
  for(int i = 0; i <= counter; i++){
    getline(file, line);
    c = line[0];
    code = line.substr(line.find(":")+1, line.length()-1);
    codes[c] = code;
  }

  getline(file, line);
  file.close();

  ofstream destFile;
  destFile.open(destination);

  string fileStr;
  for (int i = 0; i < line.length(); i++)
  {
      current.push_back(line[i]);
      if(line[i] == '0' || current.length() == longest)
      {
        for(int j = 0; j < 255; j++){
          if (current == codes[j]){
            c = j;
            fileStr.push_back(c);
          }
        }
        current = "";
      }
  }
  destFile << fileStr;
  //cout << "I ran" << endl;
}


int main(int argc, char* argv[])
{
    /*
    // NODE FUNCTION TESTS
    Node test1();
    cout << test1 << endl;

    char temp = 'a';
    Node test2(temp, 2);
    cout << test2 << endl;

    Node test3(test2);
    cout << test3 << endl;

    Node test4('b',5);
    Node test5('_', 3, test2, test4);
    cout << test5 << endl;
    cout << *(test5.leftPtr) << endl;
    cout << *(test5.rightPtr) << endl;

    assert(test2 < test4);
    assert(test4 > test2); */


    if(argc != 4){
      throw "ERROR: Incorrect input";
    }else{
      string startFile(argv[2]);
      string endFile(argv[3]);
      string option(argv[1]);
      //cout << option << endl;

      if(option == "-c"){
        compression(startFile, endFile);
      } else if(option == "-d"){
        decompression(startFile, endFile);
      }
    }



    return 0;
}
