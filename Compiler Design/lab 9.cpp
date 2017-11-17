#include<bits/stdc++.h>
using namespace std;


string InfixToPostfix(string str)
{
	stack<char> S;
	string postfix="";
	for(int i = 0; i< str.length(); i++)
	{
        if(isdigit( str[i]) || isalpha( str[i]))
		{
			postfix +=  str[i];
		}
		else if ( str[i] == '(')
		{
			S.push( str[i]);
		}
		else if( str[i] == ')')
		{
			while(!S.empty() && S.top() !=  '(')
			{
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
		else
		{
			S.push(str[i]);
		}
	}
	while(!S.empty())
	{
		postfix += S.top();
		S.pop();
	}
	return postfix;
}

int main()
{
    ios::sync_with_stdio(false);

	string expression;
	getline(cin,expression);
	string postfix = InfixToPostfix(expression);
	cout<<postfix<<endl;
}






//Modfied : https://gist.github.com/mycodeschool/7867739
//Daught : https://ideone.com/nCW6IF
