http://knowfewprograms.blogspot.com/2015/03/shift-reduce-parser-to-write-c-program.html

http://3rdyearcselabprograms.blogspot.com/2010/01/shift-reduce-parser_15.html


http://www.javaprogrammingforums.com/java-theory-questions/13330-best-way-implement-abstract-syntax-tree.html

http://vipinnpillai.blogspot.com/2011/10/recursive-descent-parser-using-c_17.html


https://www.codeproject.com/Articles/17783/Predictive-Parser-to-generate-syntax-tree-and-an-I



Source : http://www.dailyfreecode.com/Code/parse-string-recursive-descent-parser-1807.aspx

#include<bits/stdc++.h>
using namespace std;


struct tree
{
    char val;
    tree *Ltr;
    tree *Rtr;
};
tree *head;
int error=0;
char equ[15];
staticint i = 0;

void main()
{
clrscr();
    void read(tree*);
    tree * pro_E();
    tree * final;
    cout << "\n Enter The Equation: ";
    cin >> equ;
    final = pro_E();
    if(error == 0)
    {    cout <<"\n Result : ";
        read(final);
    }
getch();
}

tree * pro_E()
{
char chr;
    tree *L ,*R;
    tree * pro_T();
    tree * Enode;
    L = pro_T();
    while(equ[i] == '+' || equ[i] == '-')
    {    chr = equ[i];
        i++;
        R = pro_T();
        Enode = new tree;
        Enode->val = chr;
        Enode->Ltr = L;
        Enode->Rtr = R;
        L = Enode;
    }
return(L);
}
tree * pro_T()
{
char ch;
    tree *L, *R;
    tree *Tnode;
    tree * pro_V();
    L = pro_V();
    while (equ[i] == '*' || equ[i] == '/')
    {
        ch = equ[i];
        i++;
        R = pro_V();
        Tnode = new tree;
        Tnode->val = ch;
        Tnode->Ltr = L;
        Tnode->Rtr = R;
        L = Tnode;
    }
return(L);
}

tree * pro_V()
{
    tree * Inode;
    if (isalpha(equ[i]))
    {    Inode = new tree;
        Inode->val = equ[i];
        Inode->Ltr = Inode->Rtr =  NULL;
    }
    else
    {    cout << "Error In Expression";
        error = 1;
    }
    i++;
return(Inode);
}

void read(tree *nod)
{
    cout << nod->val;
    if(nod->Ltr != NULL)
        read(nod->Ltr);
    if(nod->Rtr != NULL)
        read(nod->Rtr);
}

/**************************************************
                    Output:
***************************************************

Enter The Equation: a+b*c/d
Result  : +a/*bcd

**************************************************/
