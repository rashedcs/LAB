#include<bits/stdc++.h>
using namespace std;


int main()
{
     ios::sync_with_stdio(false);
     while(1)
     {
        string str[63]={"asm","auto","bool","break","case","catch","char","class","const","const_cast","continue","default","delete","do","double","dynamic_cast",
        "else","enum","explicit","export","extern","false","float","for","friend","goto","if","inline","int","long","mutable","namespace",
        "new","operator","private","protected","public","register","reinterpret_cast","return","short","signed","sizeof","static","static_cast",
        "struct","switch","template","this","throw","true","try","typedef","typeid","typename","union","unsigned","using","virtual",
        "void","volatile","wchar_t","while"};
        string input;


        printf("\n Enter the string : ");
        cin>>input;

        for(int i=0; i<63; i++)
        {
           if(str[i]==input)
           {
             flag=1;
             break;
           }
        }

        if(flag==0)
        printf("\n It is not a keyword in C/C++ language.\n");
        else
        printf("\n It is a keyword in C/C++ language.\n");
    }
    return 0;
}

  









#include<bits/stdc++.h>
using namespace std;


int main()
{
     ios::sync_with_stdio(false);
     while(1)
     {
        string str[63]={"asm","auto","bool","break","case","catch","char","class","const","const_cast","continue","default","delete","do","double","dynamic_cast",
        "else","enum","explicit","export","extern","false","float","for","friend","goto","if","inline","int","long","mutable","namespace",
        "new","operator","private","protected","public","register","reinterpret_cast","return","short","signed","sizeof","static","static_cast",
        "struct","switch","template","this","throw","true","try","typedef","typeid","typename","union","unsigned","using","virtual",
        "void","volatile","wchar_t","while"};
        string input;


        printf("\n Enter the string : ");
        cin>>input;

        for(int i=0; i<63; i++)
        {
           if(str[i]==input)
           {
             flag=1;
             break;
           }
        }

        if(flag==0)
        printf("\n It is not a keyword in C/C++ language.\n");
        else
        printf("\n It is a keyword in C/C++ language.\n");
    }
    return 0;
}





#include <iostream>
#include<vector>
#include<cctype>

using namespace std;

vector<string>ob,ob2;
string arr[] ={"int","double","auto","char","for","if","else","while","return",
"string","using","namespace","extern","true","false","continue","break","typedef","float"};

int main()
{
    int l = sizeof(arr)/sizeof(arr[0]) ;
   string st;
   char ch[30];
   getline(cin,st,'\x1A');
   int count =0;
  for(int i=0;i<st.size(); )
  {
      if(st[i]==' ')
      {
          i++;
      }
      else if(isalpha(st[i]))
      {
          count = 0;
          while(isalpha(st[i]) && i<st.size())
          {
              ch[count++] = st[i];
              i++;
          }
          ch[count] = '\0';
          ob.push_back(ch);

      }
      else
      {
          i++;
      }
  }
  for(int i=0;i<ob.size();i++)
  {
      for(int j=0;j<l;j++)
      {
          if(ob[i]==arr[j])
          {
              ob2.push_back(ob[i]);
          }
      }
  }
  cout<<endl<<"keyword :"<<endl;
  for(int i=0;i<ob2.size();i++)
  {
      cout<<ob2[i]<<endl;
  }
    return 0;
