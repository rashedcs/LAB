#include<bits/stdc++.h>
using namespace std;


int isKeyword(char buffer[])
{
    string keywords[32] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int flag = 0;

    for(int i=0; i<32; i++)
    {
        if(keywords[i]==buffer)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}


int main()
{
    ios::sync_with_stdio(false);

    char ch, buffer[15], operators[8] = "+-*/%=";

    ifstream fin("input .txt");

    int j=0;

    if(!fin.is_open())
    {
        cout<<"error while opening the file\n";
        exit(0);
    }
    else
    {
          while(!fin.eof())
          {
               ch = fin.get();
               cout<<ch<<endl;

               for(int i=0; i<6; i++)
               {
                   if(ch == operators[i])
                   {
                      cout<<ch<<" is operator\n";
                   }
               }
               
               if(isalnum(ch))
               {
                   buffer[j++] = ch;
               }
               else if((ch == ' ' || ch == '\n') && (j!=0))
               {
                  buffer[j] = '\0';
                  j = 0;

                  (isKeyword(buffer)==1)? cout<<buffer<<" is keyword\n" : cout<<buffer<<" is indentifier\n";
               }
          }
    }
    fin.close();

    return 0;
}
