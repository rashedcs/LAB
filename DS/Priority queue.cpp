#include <bits/stdc++.h>  
using namespace std;  
  
struct node  
{  
    int priority;  
    int data;  
    node *next;  
}*start = NULL;  
  
  
        node *creation(int data,int priority)  
        {  
          node *tmp;  
          tmp=new node;  
          tmp->data = data;  
          tmp->next=NULL;  
          tmp->priority = priority;  
          return tmp;  
        }  
  
  
  
  
        void insertion()  
        {  
            node *temp=start, *newn;  
            int item, priority;  
  
            cout<<"Input the item value to be added in the queue : ";  
            cin>>item;  
            cout<<"Enter its priority : ";  
            cin>>priority;  
  
            newn = creation(item,priority);  
  
            if (start == NULL || priority < start->priority)  
            {  
                newn->next = start;  
                start = newn;  
            }  
  
            else  
            {  
               while (temp->next!=NULL &&  temp->next->priority <= priority)  
                {  
                 temp=temp->next;  
                }  
                newn->next = temp->next;  
                temp->next = newn;  
            }  
        }  
  
  
  
  
  
        void deletion()  
        {  
            node *temp=start;  
  
            if(start == NULL)    cout<<"Queue is Underflow\n";  
  
            else  
            {  
              start=start->next;  
              free(temp);  
            }  
        }  
  
  
        void display()  
        {  
            node *temp=start;  
  
            if(start == NULL)    cout<<"Queue is Overflow\n";  
  
            else  
            {  
                cout<<"Queue is :\n";  
                cout<<"Priority       Item\n";  
                while(temp != NULL)  
                {  
                    cout<<temp->priority<<"                 "<<temp->data<<endl;  
                    temp = temp->next;  
                }  
            }  
        }  
  
  
  
   int main()  
    {  
      int choice, item, priority;  
  
      while(1)  
      {  
        cout<<"1.Insert\n";  
        cout<<"2.Delete\n";  
        cout<<"3.Display\n";  
        cout<<"4.Quit\n";  
        cout<<"Enter your choice : ";  
        cin>>choice;  
  
        if(choice==1)       insertion();  
        else if(choice==2)  deletion();  
        else if(choice==3)  display();  
        else     cout<<"Wrong type \n";  
     }  
  
     return 0;  
   }
