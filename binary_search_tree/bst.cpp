#include <iostream>

class TreeNode
{
public:
  int Value;
  TreeNode* Left;
  TreeNode* Right;

  TreeNode(int value) : Value(value), Left(nullptr), Right(nullptr) {}
};

class BinarySearchTree
{
public:
  TreeNode* Root;

  BinarySearchTree() : Root(nullptr) {}

  // Insert a value into the tree
  void Insert(int value)
  {
    Root = InsertData(Root, value);
  }

  // Search for a value in the tree
  bool Search(int value)
  {
    return SearchData(Root, value);
  }

  // Prints all values in the tree in ascending order
  void Inorder()
  {
    InorderTraversal(Root);
    std::cout << std::endl;
  }

private:
  TreeNode* InsertData(TreeNode* node, int value)
  {
    if (node == nullptr)
    {
      return new TreeNode(value);
    }
    if (value < node->Value)
    {
      node->Left = InsertData(node->Left, value);
    }
    else
    {
      node->Right = InsertData(node->Right, value);
    }
    return node;
  }

  bool SearchData(TreeNode* node, int value) {
    if (node == nullptr)
    {
      return false;
    }

    if (node->Value == value)
    {
      return true;
    }

    if (value < node->Value)
    {
      return SearchData(node->Left, value);
    }
    else
    {
      return SearchData(node->Right, value);
    }
  }

  void InorderTraversal(TreeNode* node)
  {
    if (node != nullptr)
    {
      InorderTraversal(node->Left);
      std::cout << node->Value << " ";
      InorderTraversal(node->Right);
    }
  }
};


int main()
{

  BinarySearchTree bst;
  for (int i = 100; i > 0; i--) {
    bst.Insert(i);
  }
  bst.Inorder();
  system("PAUSE");
}