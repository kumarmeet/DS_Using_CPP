#include <bits/stdc++.h>

using namespace std;
//* Ciclular Linked List (head)->pre contains last node address and (head)-pre-next node contains first node address
class LinkedList
{
private:
  class Node
  {
  public:
    int key;
    Node *prev;
    Node *next;
    Node()
    {
      next = prev = nullptr;
    }
  };
  Node *head;
  Node *createNode(int key)
  {
    Node *n = new Node();
    n->key = key;
    n->next = n->prev = n; //** Important step
    return n;
  }

public:
  LinkedList()
  {
    head = nullptr;
  }
  //insertion operations
  void insertAtBegining(int key); //!bug detected
  void insertAtEnd(int key);
  void insertAtGivenPosition(int key, int position);
  //insertion operations ends

  //deletion operation start
  void deleteAtBegining();
  void deleteAtEnd();
  void deleteAtByGivenKey(int key);
  //deletion operation ends

  bool find(int key);
  int count();
  void display();
};

void LinkedList ::deleteAtBegining()
{
  if (!head)
    cout << "List is empty" << endl;
  else
  {
    Node *t = head;
    head = t->next;
    head->prev = t->prev;
    head->prev->next = head;
    delete (t);
  }
}

void LinkedList ::deleteAtByGivenKey(int key)
{
  if (!head)
    cout << "List is empty" << endl;
  else if (key == head->key)
    deleteAtBegining();
  else if (key == head->prev->key)
    deleteAtEnd();
  else
  {
    Node *t = head;
    do
    { //1 2 3 4 5
      if (key == t->key)
      {
        t->prev->next = t->next;
        t->next->prev = t->prev;
        delete (t);
        break;
      }
      t = t->next;
    } while (head->next != t->next);
  }
}

void LinkedList ::deleteAtEnd()
{
  if (!head)
    cout << "List is empty" << endl;
  else
  { // 1 2 3
    Node *t = head->prev;
    head->prev = t->prev;
    t->prev->next = head;
    delete (t);
  }
}

void LinkedList::insertAtBegining(int key)
{
  if (!head)
    return;
  else
  {
    Node *n = createNode(key);
    Node *t = head;
    n->prev = t->prev;
    n->next = t;
    t->prev->next = n;
    head = n;
  }
}

void LinkedList::insertAtGivenPosition(int key, int position)
{
  if (!head && position <= 0 || position > count())
    cout << "Invalid position" << endl;
  else if (position == 1)
    insertAtBegining(key);
  else if (position == count())
    insertAtEnd(key);
  else if (position > 0 && position < count())
  {
    // 10 15 (43) 25 35 20
    Node *t = head, *n = createNode(key);

    while ((position--) - 1) //(position--) - 1 assumes linked list starts from 1 ..... n
      t = t->next;

    n->prev = t->prev;
    n->next = t;
    t->prev = n;
    t->prev->prev->next = n;
  }
}

void LinkedList::insertAtEnd(int key)
{
  Node *n = createNode(key);
  if (!head)
    head = n;
  else
  {
    Node *t = head;
    while (t->next != head)
      t = t->next;
    t->next = n;
    n->prev = t;
    head->prev = n;
    n->next = head;
  }
}

void LinkedList::display()
{
  if (!head)
    cout << "List is empty" << endl;
  else
  {
    Node *t = head;
    do
    {
      cout << t->key << " ";
      t = t->next;
    } while (head->next != t->next);
  }
}

int LinkedList::count()
{
  if (!head)
    return -1;
  else
  {
    int cnt{0};
    Node *t = head;
    do
    {
      cnt++;
      t = t->next;
    } while (t->next != head->next);
    return cnt;
  }
  return -1;
}

bool LinkedList::find(int key)
{
  if (!head)
    return false;
  else
  {
    Node *t = head;
    do
    {
      if (t->key == key)
        return true;
      t = t->next;
    } while (t->next != head);
  }
  return false;
}

int main()
{
  LinkedList node;
  node.insertAtEnd(10);
  node.insertAtEnd(15);
  node.insertAtEnd(25);
  node.insertAtEnd(35);
  node.insertAtEnd(20);

  node.insertAtBegining(1);
  node.insertAtBegining(16);
  node.insertAtBegining(21);

  node.insertAtGivenPosition(14, 5);

  node.deleteAtByGivenKey(15);
  node.display();
  return 0;
}
