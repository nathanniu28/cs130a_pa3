// GraphGenerator.cpp

#include <iostream>
#include <fstream>
#include <algorithm> // std::max
#include "GraphGenerator.h"
using namespace std;

GraphGenerator::GraphGenerator(ifstream &fileInput){
  string line;
  /*while (getline (fileInput, line) && (line.length() > 0)){
    cout<<line<<endl;
    }*/
  /*
  InsertVertex(4);
  InsertVertex(2);
  InsertVertex(7);
  InsertVertex(11);
  InsertVertex(9);
  */

  InsertVertex(8);
  InsertVertex(10);
  InsertVertex(3);
  InsertVertex(4);
  InsertVertex(1);
  InsertVertex(9);
  InsertVertex(2);
  InsertVertex(7);
  InsertVertex(6);
  InsertVertex(5);
}

void GraphGenerator::InsertVertex(int data){
  Node* vertex = new Node();
  vertex->key = data;
  root = InsertVertex(root, vertex);
}

Node* GraphGenerator::InsertVertex(Node* parent, Node* vertex){
  if (!parent)
    return vertex;
  if (vertex->key > parent->key)
    parent->right = InsertVertex(parent->right, vertex);
  else if (vertex->key < parent->key)
    parent->left = InsertVertex(parent->left, vertex);
  else
    return parent;

  
  parent->height = 1 + max(Height(parent->left),Height(parent->right));

  int balance = GetBalance(parent);

  // Left Left Case
    if (balance > 1 && vertex->key < parent->left->key)
        return RightRotate(parent);
 
    // Right Right Case
    if (balance < -1 && vertex->key > parent->right->key)
        return LeftRotate(parent);
 
    // Left Right Case
    if (balance > 1 && vertex->key > parent->left->key)
    {
        parent->left = LeftRotate(parent->left);
        return RightRotate(parent);
    }
 
    // Right Left Case
    if (balance < -1 && vertex->key < parent->right->key)
    {
        parent->right = RightRotate(parent->right);
        return LeftRotate(parent);
    }
  
  return parent;
}

Node* GraphGenerator::RightRotate(Node *vertex)
{
    Node* temp1 = vertex->left;
    Node* temp2 = temp1->right;
 
    // Perform rotation
    temp1->right = vertex;
    vertex->left = temp2;
 
    // Update heights
    vertex->height = max(Height(vertex->left),Height(vertex->right)) + 1;
    temp1->height = max(Height(temp1->left),Height(temp1->right)) + 1;
 
    // Return new root
    return temp1;
}

Node* GraphGenerator::LeftRotate(Node *vertex)
{
    Node* temp1 = vertex->right;
    Node* temp2 = temp1->left;
 
    // Perform rotation
    temp1->left = vertex;
    vertex->right = temp2;
 
    // Update heights
    vertex->height = max(Height(vertex->left),Height(vertex->right)) + 1;
    temp1->height = max(Height(temp1->left),Height(temp1->right)) + 1;
 
    // Return new root
    return temp1;
}

int GraphGenerator::Height(Node* vertex){
  if (!vertex)
    return 0;
  return vertex->height;
}

int GraphGenerator::GetBalance(Node* vertex){
  if (!vertex)
        return 0;
  return Height(vertex->left) - Height(vertex->right);
}

void GraphGenerator::InOrder() const{
  if(root){
    InOrder(root);
  }
  cout << endl;
}


void GraphGenerator::InOrder(Node* vertex) const{
  if(vertex){
    InOrder(vertex->left);
    cout << vertex->key << " ";
    InOrder(vertex->right);
  }
}

void GraphGenerator::PreOrder() const{
  if(root){
    PreOrder(root);
  }
  cout << endl;
}


void GraphGenerator::PreOrder(Node* vertex) const{
  if(vertex){
    cout << vertex->key << " ";
    PreOrder(vertex->left);
    PreOrder(vertex->right);
  }
}
