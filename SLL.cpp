#include <bits/stdc++.h>

using namespace std;

class LinkedList
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
  LinkedList()
  {
    head = nullptr;
  }

  //insertion operations
  void insertAtBegining(int key)
  {
    Node *n = createNode(key);
    n->next = head;
    head = n;
  }

  void insertAtEnd(int key)
  {
    if (!head)
      head = createNode(key);
    else
    {
      Node *temp = head;
      while (temp->next)
        temp = temp->next;
      temp->next = createNode(key);
    }
  }

  void insertAtGivenPosition(int key, int position)
  {
    if (!head || position <= 0)
      cout << "List is empty" << endl;
    else
    {
      Node *temp = head, *t;
      while (--position)
      {
        t = temp;
        temp = temp->next;
      }
      t->next = createNode(key); // 5 -> 25 -> 10 -> 20
      t->next->next = temp;
    }
  }
  //insertion operations ends

  //deletion operation start
  void deleteAtBegining()
  {
    Node *t = head;
    if (!head)
      cout << "List is empty" << endl;
    else
    {
      head = t->next;
      delete (t);
    }
  }

  void deleteAtEnd()
  {
    if (!head)
      cout << "List is empty" << endl;
    else if (!head->next) //if list has only one node
    {
      delete (head);
      head = nullptr;
    }
    else
    {
      Node *t = head;
      while (t->next->next)
        t = t->next;
      delete (t->next);
      t->next = nullptr;
    }
  }

  void deleteAtGivenByPosition(int position)
  {
    if (position >= 1 && position <= count())
    {
      if (!head || position <= 0)
        cout << "List is empty" << endl;
      else if (position == 1)
        deleteAtBegining();
      else if (position == count())
        deleteAtEnd();
      else
      {
        Node *temp = head, *t;
        while (--position)
        {
          t = temp;
          temp = temp->next;
        }
        t->next = temp->next;
        delete (temp);
      }
    }
    else
      cout << "Invalid position" << endl;
  }

  void deleteAtByGivenKey(int key)
  {
    if (!head)
      cout << "List is empty" << endl;
    else if (key == head->key)
      deleteAtBegining();
    else
    {
      Node *temp = head, *r;
      while (temp)
      {
        if (temp->key == key)
        {
          r->next = temp->next;
          delete (temp);
          temp = nullptr;
          break;
        }
        r = temp;
        temp = temp->next;
      }
      if (!temp)
        cout << "Key is not found in list" << endl;
    }
  }
  //deletion operation ends

  bool find(int key)
  {
    if (!head)
      return false;
    else
    {
      while (head)
      {
        if (head->key == key)
          return true;
        head = head->next;
      }
    }
    return false;
  }

  int count()
  {
    Node *r = head;
    int count{0};
    while (r)
    {
      r = r->next;
      count++;
    }
    return count;
  }

  void display()
  {
    if (!head)
      cout << "List is empty" << endl;
    else
    {
      while (head)
      {
        cout << head->key << " ";
        head = head->next;
      }
    }
  }
};

int main()
{
  LinkedList node;
  node.insertAtBegining(10);
  node.insertAtBegining(20);
  node.insertAtEnd(30);
  node.insertAtEnd(50);
  node.insertAtBegining(5);

  node.insertAtGivenPosition(25, 2);

  node.deleteAtByGivenKey(400);

  node.display();
  return 0;
}
