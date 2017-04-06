
     #include<bits/stdc++.h>
     using namespace std;

     struct node
      {
         int data;
         node *left;
         node *right;
      }*root=NULL;

      node* GetNewNode(int data)
      {
        node* newNode = new node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
      }


      node* insert(node* root,int data)
      {
         // empty tree
         if(root == NULL)                 root = GetNewNode(data);
         // if data to be inserted is lesser, insert in left subtree.
         else if(data <= root->data)  root->left = insert(root->left,data);

        // else, insert in right subtree.
         else                         root->right = insert(root->right,data);


         return root;
      }


       node* FindMin(node* root)
       {
          while(root->left != NULL)   root = root->left;
          return root;
       }

/*
    Node *FindMin(Node *root)
     {
        if (root == NULL || root->left == NULL)  return root;
        else                                     return FindMin(root->left);
    }

*/




       node* deleteNode(node *root, int x)
       {

         if(root == NULL) return root;

         else if(x < root->data)  root->left  = deleteNode(root->left,x);

         else if (x > root->data) root->right = deleteNode(root->right,x);

         else
         {
          ///Case 1:  No child
           if(root->left == NULL && root->right == NULL)
           {
             delete root;
             root = NULL;
           }

          ///Case 2: One child
           else if(root->left == NULL)
          {
            struct node *temp = root;
            root= root->right;
            delete temp;
          }

          else if(root->right == NULL)
          {
            struct node *temp = root;
            root = root->left;
            delete temp;
          }

          ///case 3: 2 children
          else
          {
            node *temp  = FindMin(root->right);
            root->data  = temp->data;
            root->right = deleteNode(root->right,temp->data);
          }
        }
      return root;
  }





     bool Search(node* root,int data)
     {
	    if(root == NULL)            return false;
	    else if(root->data == data) return true;
	    else if(data <= root->data) return Search(root->left,data);
	    else                        return Search(root->right,data);

      }
     void preorder(node *root)
      {
            if(root!=NULL)
            {
                 cout<<root->data<<" ";
                 preorder(root->left);
                 preorder(root->right);
            }
      }

     void inorder(node *root)
      {
            if(root!=NULL)
            {
                 inorder(root->left);
                 cout<<root->data;
                 inorder(root->right);

            }
      }

     void postorder(node *root)
      {
          if(root!=NULL)
           {
                postorder(root->left);
                postorder(root->right);
                cout<<root->data;

           }
      }





   int main()
    {

        int choice,ele,data,s;

        while(1)
        {

          cout<<"\n1.Insertion \n2.Deletion  \n3.Preorder  \n4.Postorder. \n5.Find Min \n6.Exit\n ";

          cout<<"\nPlease enter your choice  : ";
          cin>>choice;



          if(choice==1)
          {
            cin>>ele;
            root=insert(root,ele);

          }

          else if(choice==2)
          {
            cin>>data;
            root=deleteNode(root,data);
          }

          else if(choice==3)
          {
            preorder(root);
          }

          else if(choice==4)
          {
            postorder(root);
          }


          else if(choice==5)
          {
            //node *temp = FindMin(root);
            cout<<FindMin(root)->data;
          }

          else if(choice==6)
          {
            cin>>s;
            Search(root,s);
            if(Search(root,s) == true) cout<<"Found\n";
	        else cout<<"Not Found\n";

          }

         else
         {
            cout<<"Sorry wrong number "<<endl;
         }

       }
      return 0;
   }
