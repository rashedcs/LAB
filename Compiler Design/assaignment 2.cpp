#include<bits/stdc++.h>
using namespace std;



void recognize(string str[], string input)
{
       int len, flag;

        len = input.size();
        if((input[0]>='0' && input[0]<='9') && ((input[1])>='a' && input[1]<='z'))
        {
            flag=10;
            goto out;
        }

        else if(input[0]>='0' && input[0]<='9')
        {
            for(int i=0; i<len; i++)
            {
                if(input[i]=='.')
                {
                        flag=2;
                        break;
                }
                else
                {
                        flag=1;
                }
            }
        }

        else if((input[0]>='a'&&input[0]<='z') || (input[0]>='A'&&input[0]<='Z') || input[0]=='_')
        {
            for(int i=0; i<32; i++)
            {
                 if(str[i]==input)
                 {
                        flag=3;
                        break;
                 }
                 else
                 {
                       flag=4;
                 }
            }
        }
        out:
            if(flag==1)
                puts("Integer Constant.");
            else if(flag==2)
                puts("Floating point Constant.");
            else if(flag==3)
                puts("Keyword.");
            else if(flag==4)
                puts("Identifier.");
            else if(flag==10)
                puts("Invalid.");
}




int main()
{
        ios::sync_with_stdio(false);
        string input;
        string str[32]={"auto","break","case","char","const","continue","default","do","double","else",
        "enum","extern","float","for","goto","if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};


           while(input!="$")
           {
                    cin>>input;
                    recognize(str, input);

           }
           return 0;
    }



















#include <iostream>
#include<vector>
#include<cctype>
#include<set>

using namespace std;

vector<string>ob,ob2;
set<string>iden,cons;
string arr[] ={"int","double","auto","char","for","if","else","while","return",
"string","using","namespace","extern","true","false","continue","break","typedef","float"};

int main()
{
    int l = sizeof(arr)/sizeof(arr[0]) ;
   string st;
   char ch[30];
   getline(cin,st,'\x1A');
   int count =0;
   int a5_6y=5;
  for(int i=0;i<st.size(); )
  {
      if(st[i]==' ')
      {
          i++;
      }
      else if(isalpha(st[i]) || (st[i]== '_'))
      {
          count = 0;
          while((isalpha(st[i])|| isdigit(st[i]) || st[i]=='_') && i<st.size())
          {
              ch[count++] = st[i];
              i++;
          }
          ch[count] = '\0';

          ob.push_back(ch);

      }
      else if(isdigit(st[i]))
      {
         count=0;

         while(isdigit(st[i])&& i<st.size() )
         {
          ch[count++] = st[i];
          i++;
         }
         ch[count]='\0';
         cons.insert(ch);

      }
      else
      {
          i++;
      }
  }
  int x=0;
  for(int i=0;i<ob.size();i++)
  {
      x = 0;
      for(int j=0;j<l;j++)
      {
          if(ob[i]==arr[j])
          {
              ob2.push_back(ob[i]);
              x =1;
              break;
          }
      }
      if(x==0)
      {

          if(ob[i]=="x1A" || ob[i]=="_")
          {

          }
          else
          iden.insert(ob[i]);
      }

  }
  cout<<endl;
  cout<<"Keyword : "<<endl;
  for(int i=0;i<ob2.size();i++)
  {
      cout<<ob2[i]<<endl;
  }
  cout<<"Identifier: "<<endl;
  set<string> :: iterator it;
  for( it=iden.begin();it != iden.end();it++)
  {
      cout<<*it<<endl;
  }
  cout<<"Constant: "<<endl;
  for( it=cons.begin();it != cons.end();it++)
  {
      cout<<*it<<endl;
  }
    return 0;
}






#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void main()
{
int i=0,flag=0;
char a[10][10]={"int","float","break","long","char","for","if","switch","else","while"},string[10];
clrscr();
printf("Enter a string :");
gets(string);
/*----Checking whether the string is in array a[][]----*/
for(i=0;i<10;i++)      
{
if((strcmp(a[i],string)==0))
flag=1;
}
/*----If it is in the array then it is a keyword----*/
if(flag==1)
printf("\n%s is a keyword ",string);
/*----Otherwise check whether the string is an identifier----*/
else
{
flag=0;
/*----Checking the 1st character*----*/
if((string[0]=='_')||(isalpha(string[0])!=0))
{
/*---Checking rest of the characters*---*/
for(i=1;string[i]!='\0';i++)
if((isalnum(string[i])==0)&&(string[i]!='_'))
flag=1;
}
else
flag=1;
if( flag==0)
printf("\n%s is an identifier ",string);
else
printf("\n%s is neither a keyword nor an identifier ",string);

}
getch();
}
