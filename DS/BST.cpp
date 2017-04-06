
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
         if(root == NULL)                      root = GetNewNode(data);
         // if data to be inserted is lesser, insert in left subtree.
         else if(data <= root->data)           root->left = insert(root->left,data);

        // else, insert in right subtree.
          else if(data >= root->data)           root->right = insert(root->right,data);


         return root;
      }


       node* FindMin(node* root)
       {
          while(root->left != NULL) root = root->left;
          return root;
       }


      node* Delete(node *root, int data)
      {

       if(root == NULL) return root;

       else if(data < root->data)   root->left  = Delete(root->left,data);

       else if (data > root->data)  root->right = Delete(root->right,data);

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
          node *temp = FindMin(root->right);
          root->data = temp->data;
          root->right = Delete(root->right,temp->data);
        }
      }
     return root;
  }



     bool Search(node* root,int data)
     {
	    if(root == NULL)             return false;
	    else if(root->data == data)  return true;
	    else if(data <= root->data)  return Search(root->left,data);
	    else if(data >= root->data)  return Search(root->right,data);

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

          cout<<"\n1.Insertion \n2.Deletion  \n3.Preorder  \n4.Inorder. \n5.Postorder \n6.Exit\n ";

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
            root=Delete(root,data);
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
            inorder(root);
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
