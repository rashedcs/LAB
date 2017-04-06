#include<iostream>
#include<stdlib.h>
using namespace std;
#define max 100

int front=0,rear=0;

void insertion(int queue[], int num)
{
  if(rear==max)
  {
    cout<<"\nQueue OverFlow Occured\n";
   // front=rear=0;
  }

  else
  {
    queue[rear++]=num;
    cout<<"Succesful Inserted "<<endl;
  }

}

void deletion(int queue[])
{
  if(front==rear)  cout<<"The queue is empty "<<endl;
  else             cout<<"\nThe deleted element is : "<<queue[front++];
}



void display(int queue[])
{
    if(front==rear)
    {
      cout<<"\nThis queue is empty \n";
    }

    else
    {
      for(int i=front; i<rear; i++)
      {
       cout<<queue[i]<<"  ";
      }
    }
}



int main()
{
  int queue[100];
  int option;
  int num;

  while(1)
  {
    cout<<"\n";
    cout<<"\n1.Insert an element";
    cout<<"\n2.Delete an element";
    cout<<"\n3.Display queue";
    cout<<"\n4.Exit";
    cout<<"\n\nEnter your choice : ";
    cin>>option;

    if(option==1)
    {
        cout<<"\nEnter the item to be inserted : ";
        cin>>num;
        insertion(queue,num);
    }
    else if(option==2)   deletion(queue);
    else if (option==3)  display(queue);
    else if(option==4)   exit(0);
    else                 cout<<"Sorry Sir , Wrong Choice "<<endl;

  }

  return 0;
}
