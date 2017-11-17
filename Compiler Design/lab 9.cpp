//Reference : mycodeschool.com

#include<bits/stdc++.h>
using namespace std;



int GetOperatorWeight(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);


	return op1Weight > op2Weight ?  true: false;
}


string InfixToPostfix(string str)
{
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
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
			while(!S.empty() && HasHigherPrecedence(S.top(),  str[i]))
			{
				postfix += S.top();
				S.pop();
			}
			S.push(str[i]);
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

int main()
{
	string expression;
	cout<<"Enter Infix Expression \n";
	getline(cin,expression);
	string postfix = InfixToPostfix(expression);
	cout<<"Output = "<<postfix<<"\n";
}










//Daught : https://ideone.com/nCW6IF
