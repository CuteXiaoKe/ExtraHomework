#include<iostream>
using namespace std;
void JonseArray(int N,int M)
{
  int a[1000];
  int j=0;
  int count=N;
  for(int i=0;i<N;i++)
  {
   a[i]=i+1;
  }
  while(count!=1)
  {
   for(int k=0;k<N;k++)
   {
   if(a[k]!=-1) j++;
   if(j==M)
   {
	cout<<a[k]<<endl;
	a[k]=-1;
	j=0;
	count--;
   }
   }
  }
  for(int l=0;l<N;l++)
  {
  if(a[l]!=-1) 
  {
    cout<<"winner is:"<<a[l]<<endl;}
  }
}
int main()
{
 JonseArray(5,5);
}