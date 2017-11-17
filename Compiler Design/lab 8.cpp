#include<bits/stdc++.h>
using namespace std;


int main()
{
   ios::sync_with_stdio(false);
   string str;
   int flag;

   while(getline(cin, str))
   {
      flag=0;
      if(!isdigit( str[0]) || !isalpha(str[0]))
      {
         flag = 1;
         break;
      }
      else
      {
         for(i=1;i<n-1;i++)
         {
            if( (s[i]=='*' || s[i]=='+' || s[i]=='/' || s[i]=='-') && 
               (s[i+1]=='*' || s[i+1]=='+' ||  s[i+1]=='/' || s[i+1]=='-') )
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
