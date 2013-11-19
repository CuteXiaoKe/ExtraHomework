#include<iostream>
using namespace std;
struct Node
{
	int data,times;
    Node* l;
	Node* r;
};
void gj( Node *p,int x){
      Node *q;
     if(p->data==x){
         p->times++;
         return;          
     }
     if(p->data>x){
         if(p->l==NULL){
             q=(Node *)malloc(sizeof( Node));
             q->data=x;
             q->times=1;
             q->r=q->l=NULL;
             p->l=q;                              
         }else gj(p->l,x);                  
         return;        
     }else{
         if(p->r==NULL){
             q=(Node *)malloc(sizeof(Node));
             q->data=x;
             q->times=1;
             q->r=q->l=NULL;
             p->r=q;                              
         }else gj(p->r,x);                  
         return;        
     }
}
void  sc(Node* head)
{
      if(head->l!=NULL)
			sc(head->l);
	 for(int i=1;i<=head->times;i++)
	   cout<<head->data<<"   ";
		if(head->r!=NULL)
			sc(head->r);
}
class sort
{
public:
	 virtual void sortmin(int a[10])=0;
};
class BubbleSort:public  sort
{
public:
	void   sortmin(int a[10])
	{
		int j,k,s;
		for(j=1;j<10;j++)
		{ 
		  for(k=0;k<=10-j-1;k++)
		  {
			  if(a[k]>a[k+1])
			 {
			  s=a[k];
			  a[k]=a[k+1];
			  a[k+1]=s;
			 }
		  } 
		}
	 for(int i=0;i<10;i++)
	 {
	   cout<<a[i]<<"   ";
	 }
	}
};
class BTreeSort:public sort
{
public:
	Node* createBtree(int a[10])
	{ 
	  Node* head=(Node *)malloc(sizeof(Node));
	  head->data=a[0];
	   head->times=1;
       head->r=head->l=NULL;      
	  for(int i=1;i<10;i++)
	     gj(head,a[i]);
	  return head;
	}
	void sortmin(int b[10])
	{
		sc(createBtree(b));
	}
};
int main()
{
	int a[10]={1,2,3,9,5,4,6,7,2,5};
	BubbleSort c;
	c.sortmin(a);
	cout<<endl;
	BTreeSort d;
	d.sortmin(a);
}