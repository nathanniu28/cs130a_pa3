// GraphGenerator.h

#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include <iostream>
#include <fstream>
//#include <vector>
using namespace std;



struct Node
{
  int key;
  List* adj;
  Node* left = NULL;
  Node* right = NULL;
  int height = 1;
};

struct List
{
  Node* vertex;
  List* next;
};

class GraphGenerator
{
public:
  GraphGenerator(ifstream &fileInput);
  void InsertVertex(int data);
  void InsertEdge();
  Node* Lookup();
  void InOrder() const;
  void PreOrder() const;
private:
  //vector<Node> tree; // AVL Tree
  Node* root = NULL;
  Node* InsertVertex(Node* temp, Node* vertex);
  Node* RightRotate(Node* vertex);
  Node* LeftRotate(Node* vertex);
  int Height(Node* vertex);
  int GetBalance(Node* vertex);
  void InOrder(Node* vertex) const;
  void PreOrder(Node* vertex) const;
};

#endif
