#include<bits/stdc++.h>
using namespace std;

char input[100];
char prod[100][100];
int l, pos=-1, st=-1;
char id,num;


void E();
void Ed();
void T();
void Td();
void F();
void advance();



void advance()
{
  pos++;
  if(pos<l)
  {
     if(input[pos]>='0'&& input[pos]<='9')
     {
       num=input[pos];
       id='\0';
     }
     if((input[pos]>='a' || input[pos]>='A')&&(input[pos]<='z' || input[pos]<='Z'))
     {
       id=input[pos];
       num='\0';
     }
  }
}


void E()
{
  strcpy(prod[++st],"E->TE'");
  T();
  Ed();
}


void Ed()
{
    int p=1;
    if(input[pos]=='+')
    {
      p=0;
      strcpy(prod[++st],"E'->+TE'");
      advance();
      T();
      Ed();
    }

    if(input[pos]=='-')
    {
      p=0;
      strcpy(prod[++st],"E'->-TE'");
      advance();
      T();
      Ed();
    }
                        // Recursive Descent Parser
    if(p==1)
    {
       strcpy(prod[++st],"E'->null");
    }
}

void T()
{
  strcpy(prod[++st],"T->FT'");
  F();
  Td();
}


void Td()
{
    int p=1;
    if(input[pos]=='*')
    {
        p=0;
        strcpy(prod[++st],"T'->*FT'");
        advance();
        F();
        Td();
    }
    if(input[pos]=='/')
    {   p=0;
    strcpy(prod[++st],"T'->/FT'");
    advance();
    F();
    Td();
    }
    if(p==1)
    strcpy(prod[++st],"T'->null");
}

void F()
{
    if(input[pos]==id)
    {
       strcpy(prod[++st],"F->id");
       advance();
    }
    if(input[pos]=='(')
    {
        strcpy(prod[++st],"F->(E)");
        advance();
        E();
        if(input[pos]==')')
        {
           //strcpy(prod[++st],"F->(E)");
           advance();
        }
    }
    if(input[pos]==num)
    {
       strcpy(prod[++st],"F->num");
       advance();
    }
}


int main()
{
    printf("Enter Input String ");
    scanf("%s",input);
    l=strlen(input);
    input[l]='$';
    advance();
    E();
    if(pos==l)
    {
      printf("String Accepted\n");
      for(int i=0;i<=st;i++)
      {
        printf("%s\n",prod[i]);
      }
    }
    else
    {
      printf("String rejected\n");
    }
    return 0;
}




















//Boolshit : https://ideone.com/ChGSPt
