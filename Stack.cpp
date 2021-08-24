#include <bits/stdc++.h>

using namespace std;

class STACK
{
private:
  class Node
  {
  public:
    int key;
    Node *next;
    Node()
    {
      next = nullptr;
    }
  };
  Node *head;
  Node *createNode(int key)
  {
    Node *n = new Node();
    n->key = key;
    return n;
  }

public:
  STACK()
  {
    head = nullptr;
  }

  void push(int key);
  void pop();
  int top();
  bool isEmpty();
  void showStack();
};

void STACK::push(int key)
{
  Node *n = createNode(key);
  n->next = head;
  head = n;
}

void STACK::pop()
{
  Node *t = head;
  if (!head)
    return;
  else
  { //4 3 2 1
    head = t->next;
    delete (t);
  }
}

int STACK::top()
{
  if (!head)
    return -1;
  else
    return head->key;
  return -1;
}

bool STACK::isEmpty()
{
  return (!head) ? true : false;
}

void STACK::showStack()
{
  if (!head)
    return;
  else
  {
    Node *t = head;
    while (t)
    {
      cout << t->key << " ";
      t = t->next;
    }
  }
}

int main()
{
  STACK stk;
  stk.push(10);
  stk.push(20);
  stk.push(30);
  stk.push(40);

  stk.showStack();
  cout << stk.top();
  stk.pop();
  cout << stk.top();
  stk.showStack();

  stk.pop();
  stk.pop();
  stk.pop();

  if (stk.isEmpty())
    cout << "true";
  else
    cout << "false";
  return 0;
}
