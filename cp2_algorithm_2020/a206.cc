#include <iostream>
#include <string>
#include <map>

using std::string;
using std::cin;
using std::cerr;
using std::endl;

/*****************************************************************************/
namespace Lexer
{
	enum Token{
		NAME, NUMBER, END, PLUS='+', MINUS='-', MUL='*', DIV='/',
		PRINT=';', ASSIGN='=', LP='(', RP=')'
	};

	Token currToken;
	double numberValue;
	string stringValue;

	Token getToken();
}

/*****************************************************************************/
namespace Parser
{
	double prim(bool);
	double term(bool);
	double expr(bool);

	std::map<string,double> table;
	int noOfErrors;
	double error(const string& s);

	using Lexer::getToken;
	using Lexer::currToken;
	using Lexer::numberValue;
	using Lexer::stringValue;
}

/***************************************************************************/
/*
program:
END
expr_list END

expr_list:
expression PRINT
expression PRINT expr_list

expression:
term + expression
term - expression
term

term:
primary / term
primary * term
primary

primary:
NUMBER
NAME
NAME = expression
- primary
( expression )
 */
int main(int argc, char* argv[])
{
	//string inputStr;
	//scanf("%[^\n]",inputStr);
	while(cin)
	{

		Lexer::getToken(); 

		if(Lexer::currToken == Lexer::END) break;

		if(Lexer::currToken == Lexer::PRINT) continue;

		std::cout << Parser::expr(false) << std::endl;
	}
	return 0;
}
Lexer::Token Lexer::getToken()
{
	char ch =0;

	do
	{
		if(!cin.get(ch)) return currToken = END;

	}while(ch !='\n' && isspace(ch) );

	switch (ch)
	{

		case ';':
		case '\n':
			return currToken = PRINT;


		case '*': case '/': case '+': case '-':
		case '(': case ')': case '=':
			return currToken = Token(ch);


		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		case '.':
			cin.putback(ch);
			cin >> numberValue;
			return currToken = NUMBER;

		default: 
			if (isalpha(ch))
			{

				stringValue = ch;
				while (cin.get(ch) && isalnum(ch)) 
					stringValue.push_back(ch); //build up the string


				cin.putback(ch);
				return currToken = NAME;
			}
			
		//	error("Bad taken");
			return currToken = PRINT;
	}
}

double Parser::prim(bool get)
{
	if (get) getToken();

	switch (currToken)
	{
		case Lexer::NUMBER:
			{
				double v = Lexer::numberValue;
				getToken();
				return v;
			}
		case Lexer::NAME:
			{
				double& v = table[stringValue];
				if(getToken() == Lexer::ASSIGN) 
					v = expr(true);
				return v;
			}
		case Lexer::MINUS:
			{
				return -prim(true);
			}
		case Lexer::LP:
			{
				double e = expr(true);
				if (currToken != Lexer::RP)
					return error(") expected");
				getToken();
				return e;
			}
	//	default:
			//return error("primary expected.");
	}
}

double Parser::term(bool get)
{
	double left = prim(get);

	for(;;)
	{
		switch (currToken)
		{
			case  Lexer::MUL:
				left *= prim(true);
				break;
			case Lexer::DIV:
				if (double d = prim(true))
				{
					left /= d;
					break;
				}
				return Parser::error("Divide by 0");
			default:
				return left;
		}
	}
}

double Parser::expr(bool get)
{
	double left = term(get); 

	for(;;) 
	{
		switch (currToken)
		{
			case Lexer::PLUS:
				left += term(true);
				break;
			case Lexer::MINUS:
				left -= term(true);
				break;
			default:
				return left;
		}
	}
}

double Parser::error(const string& s)
{
	noOfErrors++;
	cerr << "Error: " << s << endl;
	return 1;
}



