#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node {
  int value;
  struct node* left;
  struct node* right;
} Node;


Node* createNode(int value)
{
  Node *newNode = malloc(sizeof(Node));
  if (newNode != NULL) 
  {
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
  }
  return newNode;
}


void printNode(Node *node)
{
  // Can node itself ever be null? If it can, we might need to check.
  __UINT64_TYPE__ nodeAddress = (__UINT64_TYPE__) node;

  int nodeValue = node->value;
  Node* leftChild = node->left;
  Node* rightChild = node->right;

  printf("node: \e[32m%llu\e[0m\tvalue: \e[33m%d\e[0m\tleft: ", nodeAddress, nodeValue);
  if (leftChild != NULL)
  {
    printf("\e[32m%llu\e[0m", (__UINT64_TYPE__) leftChild);
  }
  else
  {
    printf("\e[31mNULL\e[0m");
  }
  printf("\t\tright: ");
  if (rightChild != NULL)
  {
    printf("\e[32m%p\e[0m", rightChild);
  }
  else
  {
    printf("\e[31mNULL\e[0m");
  }
  printf("\n");
}


int main()
{
  srand(time(NULL));
  const int count = 10;
  Node** nodes = malloc(sizeof(Node) * count);

  for (int i = 0; i < count; i++)
  {
    Node* node = createNode(rand() % 100);
    if (i > 0)
    {
      node->left = nodes[i-1];
    }
    if (i < count - 1)
    {
      node->right = nodes[count - i];
    }
    nodes[i] = node;
    printNode(nodes[i]);
  }
  
  return 0;
}