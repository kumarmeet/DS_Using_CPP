#include <bits/stdc++.h>

using namespace std;

class QUEUE
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
  Node *head, *front;
  Node *createNode(int key)
  {
    Node *n = new Node();
    n->key = key;
    return n;
  }

  public:
  QUEUE()
  {
    head = front = nullptr;
  }

  //Basic Operation of queue
  void enque(int key);
  void deque();
  bool isEmpty();
  int peek();
  int top();
  void display();
};

void QUEUE::enque(int key)
{
  if (!head)
   {
     head = createNode(key);
     front = head;
   }
  else
  {
    Node *temp = head;
    while (temp->next)
      temp = temp->next;
    temp->next = createNode(key);
  }

}

void QUEUE::deque()
{
  Node *t = head;
  if (!head)
    return;
  else
  {
    head = t->next;
    front = front->next;//for front item in queue
    delete (t);
  }
}

bool QUEUE::isEmpty()
{
  return (!head) ? true : false;
}

int QUEUE::peek()
{
  if(isEmpty())
    return -1;
  else
    return head->key;
}

void QUEUE::display()
{
  if(!head)
    return;
  else
  {
    Node *temp = head;
    while(temp)
    {
      cout << temp->key<<" ";
      temp = temp->next;
    }
  }
}

int QUEUE::top()
{
  return (!head) ? -1 : head->key;
}

int main()
{
  QUEUE q;
  q.enque(10);
  q.enque(20);
  q.enque(30);

  q.deque();
  
  cout << q.peek();

  q.display();
  return 0;
}
