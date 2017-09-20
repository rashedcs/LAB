#include <iostream>
#include<stack>
#include<cstring>
using namespace std;

char str[10],a='\0',b='\0',c='\0',ch;
int i=0,l;
int shiftReduceParser()
{
        if( b == '\0' && c == '\0' && a !='T' )
        {
            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tReduced by F -> id"<<endl;
            a='F';

            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tReduced by T -> F"<<endl;
            a='T';

            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tShift"<<endl;
            b=str[i++];

            if( b >= 'A' && b <= 'z' )
            {
                cout <<a<<b<<c<<"\t\t";
                for( int j = i ; j <= l ; j++ )
                    cout<<str[j];
                cout<< "\t\tError"<<endl;
                return 0;
                c=str[i++];
            }
            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tShift"<<endl;
            c=str[i++];

            if( !(c >= 'A') && !(c <= 'z') )
            {
                cout <<a<<b<<c<<"\t\t";
                for( int j = i ; j <= l ; j++ )
                    cout<<str[j];
                cout<< "\t\tError"<<endl;
                return 0;
                c=str[i++];
            }
            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tReduced by F -> id"<<endl;
            c='F';

            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tReduced by T -> F"<<endl;
            c='T';
        }
        else if( i < l)
        {
            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tShift"<<endl;
            b=str[i++];

            if( b >= 'A' && b <= 'z' )
            {
                cout <<a<<b<<c<<"\t\t";
                for( int j = i ; j <= l ; j++ )
                    cout<<str[j];
                cout<< "\t\tError"<<endl;
                return 0;
                c=str[i++];
            }
            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tShift"<<endl;
            c=str[i++];

            if( !(c >= 'A') && !(c <= 'z') )
            {
                cout <<a<<b<<c<<"\t\t";
                for( int j = i ; j <= l ; j++ )
                    cout<<str[j];
                cout<< "\t\tError"<<endl;
                return 0;
                c=str[i++];
            }
            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tReduced by F -> id"<<endl;
            c='F';

            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tReduced by T -> F"<<endl;
            c='T';

        }

        if( a=='T' && c=='T' && (b=='+' || b=='*' || b=='-' || b=='/'))
        {
           cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tReduced by T -> T"<<b<<"T"<<endl;
            a='T';
            b='\0';
            c='\0';
            shiftReduceParser();
        }
        else
        {
            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tReduced by E -> T"<<endl;
            a='E';

            cout <<a<<b<<c<<"\t\t";
            for( int j = i ; j <= l ; j++ )
                cout<<str[j];
            cout<< "\t\tAccept"<<endl;
        }

    return 0;
}
int main()
{
    cout << "Input a expression:"<< endl;

    cin>> str;
    cout<<str<<endl;
    l=strlen(str)-1;
    cout <<"Stack\t\tInput\t\tAction"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<a<<b<<c<<"\t\t";
    for( int j = i ; j <= l ; j++ )
        cout<<str[j];
    cout<< "\t\tShift" <<endl;
    ch=str[i++];
    a=ch;
    shiftReduceParser();

    return 0;
}
