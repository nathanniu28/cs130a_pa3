// main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "GraphGenerator.h"
using namespace std;

int main(int argv, char** argc){
  if(argv != 2){
    cout << "Please provide 1 file name" << endl;
    return 1;
  }

  ifstream fileInput (argc[1]);
  if (fileInput.fail()){
    cout << "Could not open file " << argc[1] << endl;
    return 1;
  }
  
  GraphGenerator graph(fileInput);

  // print results
  cout << "The in order traversal:" << endl;
  graph.InOrder();
  cout << "The pre order traversal:" << endl;
  graph.PreOrder();
  cout << "Is acyclic(Yes/No):" << endl;
  cout << "Connected Components:" << endl;
  
  
  
  fileInput.close();
  
  return 0;
}
