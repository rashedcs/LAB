//Problem Name : Write C++ a program to recognize keyword, identifier and constant

//Solution are given below : 

#include<bits/stdc++.h>
using namespace std;



bool checkKeyword(string str)
{
    int flag = 0;
    string keyword []= {"auto","break","case","char","const","continue","default","printf", "double","else","enum",
                        "extern","float","for","goto","if","int","do", "long","register","return","short","signed",
                        "sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
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
    int flag;

    if(isalpha(str[0]))
    {
       flag = 1;
       for(int i=1; str[i]!='\0'; i++)
       {
          if(!isdigit(str[i]) && !isalpha(str[i]))
          {
             flag=0;
             break;
          }
       }
       return flag;
    }
    else
    {
        flag = 0;
        return flag;
    }
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

    if(conv.eof())                  puts("Constant");
    else if(checkKeyword(str))      puts("Keyword");
    else if(checkIdentifier(str))   puts("Identifier");
    else                            puts("not Identifier");

    return 0;
}
