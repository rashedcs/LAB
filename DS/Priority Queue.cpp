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

            if(start == NULL)
            {
               cout<<"Queue is Underflow\n";
            }

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




/*
#include <iostream>
#include <algorithm>
using namespace std;


int partition(int arr[], int start, int end)
{
    ///The pivot element is taken to be the element at
    ///The start of the subrange to be partitioned.
     int pivotPosition = start;
    int pivotValue = arr[start];


    // Rearrange the rest of the array elements to
    // partition the subrange from start to end.
    for (int i=start+1; i<=end; i++)
    {
        if (arr[i] < pivotValue)
        {
             /// arr[pos] is the "current" item.
            /// Swap the current item with the item to the
            /// right of the pivot element.
            swap(arr[pivotPosition+1], arr[i]);
            /// Swap the current item with the pivot element.
            swap(arr[pivotPosition] , arr[pivotPosition+1]);
            /// Adjust the pivot position so it stays with the
            /// pivot element.
            pivotPosition++;
        }
        for(int k = 0; k<end+1; k++)   cout<<arr[k]<<" ";
        cout<<endl;
    }

    return pivotPosition;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main()
{
    int arr[10],n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
      cin>>arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int k = 0; k<n; k++)   cout<<arr[k]<<" ";

    return 0;
}
*/
