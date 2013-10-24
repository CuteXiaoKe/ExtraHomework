#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
};
class Cqueue
{
public:
	void push(int n);
	void pop();
	int getfront();
	int getback();
	int getsize();
	bool isEmpty();
	Cqueue():size(0){};
private:
	int size;
    Node* front;
	Node* back;
};
bool Cqueue::isEmpty()
{
   return (0==size);
}
void Cqueue::push(int n)
{
  if(isEmpty())
  {
    Node* p=(Node*)malloc(sizeof(Node));
	p->data=n;
	front=p;
	back=p;
	size++;
  }
  else
  {
    Node* q=(Node*)malloc(sizeof(Node));
	q->data=n;
	back->next=q;
	back=q;
	size++;
  }
}
void Cqueue::pop()
{
  Node* p=front;
  front=front->next;
  delete(p);
  size--;
}
int Cqueue::getfront()
{
	return front->data;
}
int Cqueue::getback()
{
	return back->data;
}
int Cqueue::getsize()
{
	return size;
}
int main()
{
  Cqueue c;
  if(c.isEmpty())
  {
    cout<<"此队列为空"<<endl;
  }
  c.push(1);
  c.push(2);
  c.push(3);
  c.push(4);
  c.pop();
  c.pop();
  cout<<c.getfront()<<endl;
  cout<<c.getback()<<endl;
  cout<<c.getsize()<<endl;
}
