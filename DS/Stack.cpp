#include<bits/stdc++.h>
using namespace std;


int top = 0;

void push(int stk[],int n, int item)
{
  if(top==n)    cout<<"Overflow \n";
  else          stk[top++]=item;
}


void pop(int stk[])
{
  if(top==NULL)      cout<<"Underflow \n";
  else               top--;
}

int peek(int stk[])
{
           return stk[top-1];
}

void show(int stk[])
{
  if(top==NULL) cout<<"Stack is empty \n";
  else
  {
    for(int i=0; i<top; i++)
    {
      cout<<stk[i]<<" ";
    }
  }
}


int main()
{
 int choice, item, n=10;
 int stk[n];

 while(1)
 {
  cout<<"\n1.Insertion \n2.Deletion \n3.Peek  \n3.Show  \n4.Exit  \n Enter your choice : ";
  cin>>choice;

  if(choice==1)
  {
     cout<<"Enter the element to be inserted : ";
     cin>>item;
     push(stk,n, item);
  }
  else if(choice==2)       pop(stk);
  else if(choice==3)       cout<<peek(stk);
  else if(choice==4)       show(stk);
  else if(choice==5)       exit(1);
 }
return 0;
}
