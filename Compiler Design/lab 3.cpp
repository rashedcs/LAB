#include<bits/stdc++.h>
using namespace std;


bool checkOperator(string str)
{
    bool flag = false;
    string oper[6] = {"+", "-", "*", "/", "++", "--"};
    for(int i=0; i<6; i++)
    {
       if(oper[i]==str)
       {
         flag = true;
         false;
       }
    }
    return flag;
}

bool checkNumeric(string str)
{
      int b = str.size();
      int flag = 0;

      while(b--)
      {
         if(str[b]=='.')
		 {
			flag=1;
			break;
		 }
      }
      if(flag)  printf("Floating point\n");
      else      printf("Integer\n");
}


bool checkKeyword(string str)
{
    int flag = 0;
    string keyword []= {"auto","break","case","char","const","continue","default","printf", "double","else","enum","extern","float","for","goto","if","int","do", "long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    for(int i=0 ; i<=32 ; i++)
    {
        if(keyword[i]==str)
        {
            flag = 1;
            break;
        }
    }
   return flag;
}


bool checkIdentifier(string str)
{
    int flag=1;

    if(str[0]=='_' || isalpha(str[0]))
    {
      for(int i=1 ; i<str.size(); i++)
      {
         if(str[i]=='_' || isalpha(str[i]) || isdigit(str[i]))
         {
            continue;
         }
         else
         {
            flag=0;
            break;
         }
      }
    }
    return flag;
}





int main()
{
    ios::sync_with_stdio(false);
    string str;

    stringstream conv;
    double number;

    getline(cin, str);

    conv<<str;
    conv>>number;

    if(checkOperator(str))          puts("Operator");
    else if(conv.eof())             checkNumeric(str);
    else if(checkKeyword(str))      puts("Keyword");
    else if(checkIdentifier(str))   puts("Identifier");
    else                            puts("not Identifier");

    return 0;
}

