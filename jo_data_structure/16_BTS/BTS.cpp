#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

enum { ADD, REMOVE, DEPTH, LEAF, QUIT };
array<string, 5> commands = {"+", "-", "depth", "leaf", "quit"};

int getCommand(string str)
{
  auto iter = find(commands.begin(), commands.end(), str);
  if (iter == commands.end())
    return -1;
  return iter - commands.begin();
}

class Node
{
  string val;
  Node *parent;
  Node *left;
  Node *right;

public:
  Node(string _val, Node *_parent) : val(_val), parent(_parent), left(NULL), right(NULL) {}

  void add(string str)
  {
    if (str < val)
    {
      if (left)
        left->add(str);
      else
        left = new Node(str, this);
    }
    else if (str > val)
    {
      if (right)
        right->add(str);
      else
        right = new Node(str, this);
    }
  }

  Node *findNode(string str)
  {
    while (true)
    {
      if (str < val)
      {
        if (left)
          return left->findNode(str);
        else
          return NULL;
      }
      else if (str > val)
      {
        if (right)
          return right->findNode(str);
        else
          return NULL;
      }
      else
        return this;
    }
  }

  Node *findSuccessor()
  {
    Node *node = this;
    node = node->right;
    while (node->left)
      node = node->left;
    return node;
  }

  Node *findPredecessor()
  {
    Node *node = this;
    node = node->left;
    while (node->right)
      node = node->right;
    return node;
  }

  bool remove(string str)
  {
    Node *tar = findNode(str);
    if (!tar)
      return false;
    return tar->remove();
  }

  bool remove()
  {
    Node *node = this;
    if (left)
      node = findPredecessor();
    else if (right)
      node = findSuccessor();
    else
      return removeLeaf();
    val = node->val;
    return node->remove();
  }

  bool removeLeaf()
  {
    bool isRoot = true;
    if (parent)
    {
      if (parent->left == this)
        parent->left = NULL;
      else
        parent->right = NULL;
      isRoot = false;
    }
    delete this;
    return isRoot;
  }

  bool printDepth(int k, int depth)
  {
    if (depth == k)
    {
      cout << val << " ";
      return true;
    }
    bool haveK = false;
    if (left)
      haveK |= left->printDepth(k, depth + 1);
    if (right)
      haveK |= right->printDepth(k, depth + 1);
    return haveK;
  }

  void printLeaf()
  {
    if (!left && !right)
      cout << val << " ";
    else
    {
      if (left)
        left->printLeaf();
      if (right)
        right->printLeaf();
    }
  }
};

class BST
{
  Node *root = NULL;

public:
  void add(string str)
  {
    if (root)
      root->add(str);
    else
      root = new Node(str, NULL);
  }

  void remove(string str)
  {
    if (root)
    {
      bool is_root = root->remove(str);
      if (is_root)
        root = NULL;
    }
  }

  void printDepth(int k)
  {
    if (root && root->printDepth(k, 1))
      cout << "\n";
    else
      cout << "NO\n";
  }

  void printLeaf()
  {
    if (root)
    {
      root->printLeaf();
      cout << "\n";
    }
  }
};

void solution()
{
  string cmd, str;
  int num;

  Node *root = NULL;
  BST bst;
  while (true)
  {
    cin >> cmd;
    switch (getCommand(cmd))
    {
    case ADD:
      cin >> str;
      bst.add(str);
      break;
    case REMOVE:
      cin >> str;
      bst.remove(str);
      break;
    case DEPTH:
      cin >> num;
      bst.printDepth(num);
      break;
    case LEAF:
      bst.printLeaf();
      break;
    case QUIT:
      return;
    }
  }
}

int main()
{
  solution();
  return 0;
}