#include<iostream>    
#include<stdlib.h>    
using namespace std;    
    
struct node    
{    
 int data;    
 node *next;    
};    
    
node *start=NULL;    
    
node *creation(int data)    
{    
    
 node *temp;    
 temp=new node;    
 temp->data=data;    
 temp->next=NULL;    
 return temp;    
}    
    
    
void insertion()    
{    
  node *newn, *temp, *temp2;    
  int data , pstn ;    
    
  cout<<"Enter position to insert : ";    
  cin>>pstn;    
    
  cout<<"Enter value to be inswerted ";    
  cin>>data;    
    
  newn=creation(data);    
    
  ///Case 1: When position is one    
  if(pstn==1)    
  {    
    if (start == NULL)    
    {    
        start = newn;    
        start->next = NULL;    
    }    
    
    else    
    {    
        newn->next = start;    
        start = newn;    
    }    
  }    
    
  ///Case 2: When position is middle    
  else    
  {    
    temp=start;    
    for(int i=1; i<pstn-1; i++)    
    {    
     temp=temp->next;    
    }    
   // newn->next=temp->next;    
  //  temp->next=newn;   
     temp2=temp->next;
     temp->next = newn;
     newn->next=temp2;
      
  }    
}    
    
    
void deletion()    
 {    
   node *temp,*temp2;    
   int pstn;    
    
   cout<<"Enter the position at which node to be deleted: ";    
   cin>>pstn;    
    
   ///Case 1: When position is one    
   if(pstn==1)    
   {    
      if(start==NULL)    
      {    
        cout<<"Deletion can not possible "<<endl;    
      }    
    
      else    
      {    
        temp=start;    
        start=temp->next;    
        free(temp);    
      }    
   }    
    
   ///Case 2: When position is middle    
   else    
    {  temp=start;    
       for(int i=1; i<pstn-1; i++) {temp=temp->next;}    
       temp2=temp->next;    
       temp->next=temp2->next;    
       free(temp2);    
    }    
  }    
    
    
void seartion()    
{    
  node *temp=start;    
  int value, pos = 0;    
  bool flag = false;    
    
  if (temp == NULL)    
  {    
      cout<<"List is empty"<<endl;    
      return;    
  }    
    
  else    
  {    
    cout<<"Enter the value to be searched: ";    
    cin>>value;    
 
    while (temp != NULL)    
    {    
       pos++;    
       if (temp->data == value)    
       {    
         flag = true; 
         cout<<"Element "<<value<<"is found at position "<<pos<<endl; 
       }    
      temp = temp->next;    
     }  
      if (!flag)      cout<<"Element "<<value<<" not found in the list"<<endl; 
   }    
 }    
    
    
void display()    
{    
  node *temp;    
    
  if(start==NULL)    
  {    
     cout<<"List is empty "<<endl;    
  }    
    
  else    
  {    
    temp=start;    
    while(temp!=NULL)    
    {    
     cout<<temp->data<<"->";    
     temp=temp->next;    
    }    
   cout<<"NULL"<<endl;    
  }    
    
}    
        
    
  int main()    
   {    
     int choice;    
     int data;    
   
     while(1)    
     {    
    
       cout<<"\n1.Insertion \n2.Deletion \n3.Searching \n4.display. \n5.Exit\n "; 
 
       cout<<"\nPlease enter your choice  : ";    
       cin>>choice;    
    

         if(choice==1)    
          {    
            insertion();    
          }    
    
         else if(choice==2)    
          {    
            deletion();    
          }    
    
         else if(choice==3)    
          {    
            seartion();    
          }    
    
         else if(choice==4)    
          {    
            display();    
          }    
   
         else if(choice==5)    
          {    
            exit(0);    
          }    
    
         else    
         {    
            cout<<"Sorry wrong number "<<endl;    
         }  
  
       }    
    
      return 0;    
  } 
