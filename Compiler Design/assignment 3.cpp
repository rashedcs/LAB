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

bool checkDigit(string str)
{
   int cnt=0;
   for(int i=0; i<str.size(); i++)
   {
       if(isdigit(str[i])) cnt++;
   }
   if(str.size()>=cnt) return true;
   else                return false;
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
   else if(!isdigit(str[0])) puts("Identifier");
   else                      puts("Invalid");
}







int main()
{
    ios::sync_with_stdio(false);
    string str;
    getline(cin, str);
    if(checkOperator(str))          puts("Operator");
    else if(checkDigit(str))        puts("Constant");
    else                            check(str);

    return 0;
}





#include <iostream>
#include<string>
#include<cctype>
using namespace std;
void callspecificdatatype(string st)
{
    bool x = true ;
    for(int i=0;i<st.size();i++)
    {
        if(st[i]=='.')
        {
            x = false ;
            break;
        }
    }
    if(x)
    {
        cout<<"Integer"<<endl;
    }
    else
    {
        cout<<"Float"<<endl;
    }
}
int main()
{
    string st;
    string keyword[] = {"do","while","for","int","double","float","if","else","break","continue"};
    getline(cin,st);
    bool x;
    if(st[0]=='"' && st[st.size()-1]=='"' && st.size()!=1)
    {
        cout<<"String"<<endl;
    }
    else if(st.size()==1 && (st[0]=='+' || st[0]=='-' || st[0]=='*' || st[0]=='/' || st[0]=='<' || st[0]=='>' || st[0]=='!' || st[0]=='='))
    {

        if(st[0]=='<' || st[0]=='>')
        {
            cout<<"Relational operator\n";
        }
        else if(st[0]=='=')
        {
            cout<<"Assignment Operator\n";
        }
        else if(st[0]=='!')
        {
            cout<<"Logical Operator\n";
        }
        else if(st[0]=='+' || st[0]=='-' || st[0]=='*' || st[0]=='/')
        {
           cout<<"Arithmetic Operator"<<endl;
        }
    }
    else if(st.size()==2 && (st=="&&" || st=="||" || st=="!=" || st=="<=" || st==">=" || st=="++" || st=="--"))
    {
        if(st=="&&" || st=="||")
        {
            cout<<"Logical Operator\n";
        }
        else if(st=="++")
        {
            cout<<"Increment Operator\n";
        }
        else if(st=="--")
        {
            cout<<"Decrement Operator\n";
        }
        else
        {
            cout<<"Relational Operator\n";
        }
    }
    else if(st[0]=='+' || st[0]=='-' || isdigit(st[0]) || st[0]=='.')
    {
        if(!isdigit(st[0]))
        {
            x = true ;
            for(int i=1;i<st.length();i++)
            {
                if(isdigit(st[i]) || st[i]=='.')
                {
                    ;
                }
                else
                {
                    x = false ;
                    break ;
                }
            }
            if(x)
            {
                callspecificdatatype(st);
            }
        }
        else if(isdigit(st[0]))
        {
             x = true ;
            for(int i=1;i<st.length();i++)
            {
                if(isdigit(st[i]) || st[i]=='.')
                {
                    ;
                }
                else
                {
                    x = false ;
                    break ;
                }
            }
            if(x)
            {
                callspecificdatatype(st);
            }

        }
    }
    else
    {
        x = false ;
        int b = 0;
        int l = sizeof(keyword)/sizeof(keyword[0]);
        for(int i=0;i<l;i++)
        {
            if(keyword[i]==st)
            {
                x = true;
                break;
            }
        }
        if(x)
        {
            cout<<"Keyword\n";
            b = 1;
        }
        bool iden = true;

        if(b==0 && isalpha(st[0]))
        {
            for(int i=0;i<st.size();i++)
            {
                if(isalpha(st[i]) || st[i]=='_' || isdigit(st[i]))
                {
                    ;
                }
                else
                {
                    iden = false;
                    break;
                }

            }
            if(iden)
            {
                cout<<"Identifier\n";
            }
        }

    }
    return 0;
}











/**Pa**/

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    string x;
    cin>>x;
      if((x=="do" )|| (x=="for")|| (x=="while") ||(x=="if")||(x=="double") ||(x=="char"))
    {
        cout<<"keyword"<<endl;
    }
    else if(x=="+"||x=="-"||x=="*"||x=="/"){
        cout<<"arithmetic operator"<<endl;
    }
     else if(x=="++"){
       cout<<"increment"<<endl;
    }
    else if(x=="--"){
       cout<<"decrement"<<endl;
    }
     else if(isdigit(x.at(0))||x.at(0)=='.'){

        int l=x.length();
        int i=0;
        int p=1;
        if(x.at(0)=='.'){
            p=0;
        }else{
             while(i<l){

            if(!isdigit(x.at(i)))
            {
                p=0;
            }
            i++;
        }

        }

        if(p==1)
        {
            cout<<"integer"<<endl;
        }else{
           cout<<"float"<<endl;
        }
     }else{
       cout<<"sorry sir we have not type of record"<<endl;
     }
    return 0;
}














