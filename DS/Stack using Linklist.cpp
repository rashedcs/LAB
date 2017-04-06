          #include <bits/stdc++.h>
          using namespace std;

          struct node
          {
            int data;
            node *next;
          } *top = NULL;



          node *creation(int data)
          {
            node *tmp = new node;
            tmp->data = data;
            tmp->next=NULL;
            return tmp;
          }




          void insertion(int data)
          {
            node *newnode = creation(data);
            if (top == NULL)
            {
              top = newnode;
            }

            else
            {
              newnode->next = top;
              top = newnode;
            }
          }




          void deletion()
          {
            node *temp;
            if (top == NULL)
            {
              printf("\n Error : Trying to pop from empty stack");
              return;
            }

            else
            {
              temp = top;
              top=top->next;
              delete temp;
            }
          }






         void display()
         {
           node *temp = top;
           if (temp == NULL)
           {
              printf("Stack is empty");
              return;
           }

           while (temp!= NULL)
           {
              cout<<temp->data<<" ";
              temp = temp->next;
           }
         }




        int main()
        {
          int choice, item;
 
          while(1)
          {
            cout<<"\n";
            cout<<"1.Insert\n";
            cout<<"2.Delete\n";
            cout<<"3.Display\n";
            cout<<"4.Quit\n";
            cout<<"Enter your choice : ";
            cin>>choice;

            if(choice==1)
            {
               cin>>item;
               insertion(item);
            }
            else if(choice==2)  deletion();
            else if(choice==3)  display();
            else     cout<<"Wrong type \n";
           }

          return 0;
        }
