          #include <bits/stdc++.h>
          using namespace std;

          struct node
          {
            int data;
            node *next;
          };

          node *front = NULL;
          node *rear =NULL;


          node *creation(int data)
          {
            node *tmp = new node;
            tmp->data = data;
            tmp->next=NULL;
            return tmp;
          }




         void insertion(int item)
         {
               node *newnode = creation(item);

               if(front==NULL)  //if(front==NULL && rear==NULL)
               {
                   front=newnode;
                   rear=newnode;
                //  front = rear = newnode;
               }

               else
               {
               	  rear->next = newnode;
	              rear = newnode;
               }
          }





        void deletion()
        {
           struct node *temp = front;

           if (front == NULL)
           {
             printf("\nQueue is Empty \n");
             return;
           }

           else
           {
               front = front->next;
               if(front == NULL)  rear = NULL;
               printf("Removed Element : %d\n", temp->data);
               free(temp);
           }
         }


        void display()
        {
            node *temp=front;

            if(front == NULL)    cout<<"Queue is Overflow\n";

            else
            {
                cout<<"Queue is :\n";
                while(temp != NULL)
                {
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
            }
            cout<<endl;
        }




   int main()
    {
      int choice, item;

      while(1)
      {
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

