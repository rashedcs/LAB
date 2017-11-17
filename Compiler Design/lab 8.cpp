#include<bits/stdc++.h>
using namespace std;


int main()
{
   ios::sync_with_stdio(false);
   string s;
   int flag;

   while(getline(cin, s))
   {
      size_t found= s.find("(");

      if(found!=std::string::npos)
      {
              cout<<"parenthesis\n";
      }
      else
      {
          flag=0;
          if(!isdigit(s[0]) || !isalpha(s[0]))
          {
             flag = 1;
             break;
          }
          else
          {
             for(int i=1; i<s.size()-1; i++)
             {
                if((s[i]=='*' || s[i]=='+' ||
                   s[i]=='/' || s[i]=='-') &&
                   (s[i+1]=='*' || s[i+1]=='+' ||
                   s[i+1]=='/' || s[i+1]=='-'))
                   {
                        flag = 1;
                        break;
                   }
             }
          }

          if(flag==0)
          {
               printf("Valid\n");
          }
          else
          {
               printf("Invalid\n");
          }
      }
    }
    return 0;
  }
