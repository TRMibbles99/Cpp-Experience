/*
Mary Price
April 4, 2020
CS173
Operator Practice: takes an expression that the user inputs and shows how you
would solve the problem
*/
#include <iostream>
#include <vector>
#include <string>
#include "ImprovedStack.h"

bool checkValid(string userInput);
void process(string userInput);
void evaluate(Stack<char> &operandStack, Stack<char> &operatorStack);
void printVector(vector<char> results);

//keeps track of how many times evaluate has run to change the different variables
int countEval = 0;

int main(){
  //declaring variable and prompting user
  string userInput;
  cout << "Enter an equation: ";
  getline(cin, userInput, '\n');

  //checking if user variable is valid
  bool isValid = checkValid(userInput);

  if (!isValid){
    return 0;
  }

  //process the user expression
  process(userInput);

  return 0;
}

bool checkValid(string userInput){
  //checks if the user input if valid by not counting spaces and seeing if it
  //consists of letters and operator signs
  for (int i = 0; i < userInput.length(); i++){
    int cha = userInput[i];
    if (!(userInput[i] == ' ')){
      if(!((userInput[i] == '+') || (userInput[i] == '-') || (userInput[i] == '/') || (userInput[i] == '*'))){
        if(!(cha >= 97 && cha <= 109)){
          cout << "Invalid Expression" << endl;
          return false;
        }
      }
    }
  }
  return true;
}

void process(string userInput){
  //creating stacks and declaring variables
  Stack<char> operandStack;
  Stack<char> operatorStack;
  int counter = 0;

  //runs for until it reaches the end of the string from user input
  while(counter < userInput.length()){
    //changes the current char into an integer and checks if it is a letter or
    //an operator

    //if it is a letter then it pushes it onto the operand stack
    int ch = userInput[counter];
    if(ch >= 97 && ch <= 109){
      operandStack.push(userInput[counter]);
    }
    //checks if operator stack is empty, if it is not and the top is a * or /
    //then it will evaluate
    if(!(operatorStack.empty())){
      char top = operatorStack.peek();
      if(top == '*' || top == '/'){
        evaluate(operandStack, operatorStack);
      }
    }
    //pushes the current operator onto the operator stack
    if(userInput[counter] == '+' || userInput[counter] == '-'){
        operatorStack.push(userInput[counter]);
    }else if(userInput[counter] == '/' || userInput[counter] == '*'){
        operatorStack.push(userInput[counter]);
    }
    counter++;
  }
  //runs evaluate until operand stack is empty
  while(!(operatorStack.empty())){
    evaluate(operandStack, operatorStack);
  }
}

void evaluate(Stack<char> &operandStack, Stack<char> &operatorStack){
  //creates result vector and other variables
  vector<char> results;
  char ch = 122-countEval;

  //reads everything it needs into result vector and pops it from the two stacks
  results.push_back(operatorStack.peek());
  operatorStack.pop();

  results.push_back(operandStack.peek());
  operandStack.pop();
  results.push_back(operandStack.peek());
  operandStack.pop();
  operandStack.push(ch);

  results.push_back(ch);

  //prints the results vector and clears it
  countEval++;
  printVector(results);
  results.clear();
}

void printVector(vector<char> results){
  //prints vectors
  for (int i = 0; i < results.size(); i++){
    cout << results.at(i) << ' ';
  }
  cout << endl;
}
