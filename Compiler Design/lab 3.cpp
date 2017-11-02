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


void check(string str)
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
        else  flag++;
    }
   if(flag==1) puts("Keyword");
   else if(!isdigit(str[0])) puts("Identifier"); //never space
   else                      puts("Invalid");
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

    else                            check(str);

    return 0;

}

