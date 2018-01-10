/*********************************
 * Steven Ortiz
 * ECGR 3090 Data Structure 
 * Homework 5 
 * the program checks if the brackets are balanced 
 * *******************************/



#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
This program uses a stack to check whether an expression has balanced 
parentheses.
*/
bool parenMatch(string expression);
bool bracketmatch( char potopen , char Bclose );

int main()
{

string expr1 = "(()()()())";
string expr2 = "{[(])}";
string expr3 = "(()){}()";
string expr4 = "{[(])}";
string expr5 = "{[()]}";

if (parenMatch(expr1))
cout << "Parantheses balanced in expr1" << endl;
else
cout << "Parentheses unbalanced in expr1" << endl;

if (parenMatch(expr2))
cout << "Parantheses balanced in expr2" << endl;
else
cout << "Parentheses unbalanced in expr2" << endl;
if (parenMatch(expr3))
cout << "Parantheses balanced in expr3" << endl;
else
cout << "Parentheses unbalanced in expr3" << endl;
if (parenMatch(expr4))
cout << "Parantheses balanced in expr4" << endl;
else
cout << "Parentheses unbalanced in expr4" << endl;
if (parenMatch(expr5))
cout << "Parantheses balanced in expr5" << endl;
else
cout << "Parentheses unbalanced in expr5" << endl;


return 0;
}




bool parenMatch(string expression) 
{
	
	// initiate stack 
	stack<char> Stac; 
	/**********************
	 * 
	 * Iterirate through the string until the end of string 
	 *if it's an open bracket push the stack
	 * if it's a close bracket then compare to the top bracket in stack to see if its a pair ( helper function) 
	 * when close bracket has a pair pop the top of the stack then continue throught the array and competle until end of string 
	 * 
	 * ********************/
	for(int i=0;i < expression.size(); i++)
	{	
		if(expression[i] == '('){
				Stac.push(expression[i]);
			}
		else if(expression[i]== '{'){
				Stac.push(expression[i]);
		}
		else if(expression[i] == '['){
			Stac.push(expression[i]);
		}
		else if((expression[i] == ')' )|| (expression[i] == '}' )|| (expression[i] == ']'))
		{   // get into the checking if any close bracket has a matching pair with bracketmatch helper function 
			if(bracketmatch(Stac.top(),expression[i]))           // if brackets match  pop 
				{Stac.pop();
					//cout << "bad" << endl;
				}
			else      // if the pair does not match 
				return false; 
				
		}	
	}
	return Stac.empty();   // at the end of the for loop the stack should be empty if it's balanced 
}
/*************************
 * Compares the expression at i of the for loop  as Bclose and potopen as top of stack 
 * if a pair return true 
 * if not a pair return false 
 * 
 * ************************/

bool bracketmatch( char potopen , char Bclose ) {
	if( potopen == '(' && Bclose == ')') 
		return	true;
	if( potopen == '{' && Bclose == '}') 
		return true; 
	if( potopen == '[' && Bclose == ']')
		return true;
	else
			return false; 

}
