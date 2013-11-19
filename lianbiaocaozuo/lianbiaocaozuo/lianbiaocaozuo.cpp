#include <iostream>
using namespace std;
struct Node
{
	char data;
	Node* next;
};
Node* create(char a[20])
{
    Node* p=(Node*)malloc(sizeof(Node));
	p->data=a[0];
	Node* r=p;
	for(int i=1;a[i]!='\0';i++)
	{
     Node* q=(Node*)malloc(sizeof(Node));
	 p->next=q;
	 q->data=a[i];
	 p=q;
	 p->next=NULL;
	}
  Node* f=r;
  while(f!=NULL)
  {
	  cout<<f->data<<"    ";
	  f=f->next;
  }
  cout<<endl;
  return r;
}
char display(Node*q,int n)
{
  int count=1;
  Node* p=q;
  while(count!=3)
  {
    p=p->next;
	count++;
  }
    return p->data;
}
Node* insert(Node*e,int n,char m)
{
	Node* p=e;
	Node* r=p;
	int i=1;
	while(i!=2)
	{
	  p=p->next;
	  i++;
	}
    Node* s=(Node*)malloc(sizeof(Node));
	s->data=m;
	s->next=p->next;
	p->next=s;
	Node* q=r;
	while(r!=NULL)
	{
		cout<<r->data<<"    ";
		r=r->next;
	}
	cout<<endl;
	return q;
 }
Node* deleteone(Node*p,int n)
{ 
	Node* r=p;
    int i=1;
	while(i!=n-1)
	{
		p=p->next;
		i++;
	}
     Node* f=p->next;
	p->next=p->next->next; 
	delete(f);
	Node* o=r;
	while(r!=NULL)
	{
		cout<<r->data<<"    ";
		r=r->next;
	}
	cout<<endl;
	return o;
}
void deleteall(Node* q)
{ 
	Node* p=q;
	Node* r=p->next;
	while(r!=NULL)
	{
	  Node* f=p;
	  p=p->next;
	  r=r->next;
	  delete(f);
	}
	delete(p);
}
int main()
{
	char  a[20]={'a','b','c','d','e','f'};
	cout<<display(create(a),3)<<endl;
	deleteall(deleteone(insert(create(a),3,'e'),3));
}