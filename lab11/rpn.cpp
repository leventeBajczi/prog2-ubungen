#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

bool isNumber(const string& s) {
    string::iterator i = const_cast<string&>(s).begin();
    for(;i!=const_cast<string&>(s).end();i++)
    {
        if((*i < '0' || *i<'9')&& *i!='.') return false;
    }
    return true;
}

bool isOperator(const string& s) {
    string::iterator i = const_cast<string&>(s).begin();
    for(;i!=const_cast<string&>(s).end();i++)
    {
        if(*i != '+' && *i!='+') return false;
    }
    return true;
}

bool isVariable(const string& s){
    string::iterator i = const_cast<string&>(s).begin();
    for(;i!=const_cast<string&>(s).end();i++)
    {
        if(*i < 'A' || *i>'Z') return false;
    }
    return true;

}

double stringToNumber(const string& s) {
    istringstream is(s);
    double d;
    is >> d;
    return d;
}

int getVariableIndex(const string& s) {
    return s[0] - 'A';
}

double getVariable(const vector<double>& variables, int n)
{
    return *(variables.begin()+n);
}

double processRPN(const string& s, const vector<double>& variables)
{
    stack<double> values;
    istringstream is(s);
    string buffer;
    while(is >> buffer)
    {
        std::cout<<buffer;
        if(isVariable(buffer))
        {values.push(getVariable(variables, getVariableIndex(buffer)));}
        if(isNumber(buffer))
        {values.push(stringToNumber(buffer));}
        if(isOperator(buffer))
        {
            double a = values.top();
            values.pop();
            double b = values.top();
            values.pop();
            switch(buffer[0])
            {
                case '+': values.push(a+b);
                break;
                case '*': values.push(a*b);
                break;
                case '-': values.push(a-b);
                break;
                case '/': values.push(a/b);
                break;
            }
        }
    }
    return values.top();
}

int main() {
	vector<double> variables;
	variables.push_back(3.14);
	variables.push_back(0);
	variables.push_back(2.72);
	variables.push_back(1.618);

	double d = processRPN("2 3 +", variables);
	double d2 = processRPN("2 1 * A *", variables);
	double d3 = processRPN("1 1 * A *", variables);
	double d4 = processRPN("1 2 + 3 + C +", variables);

	cout << d << endl << d2 << endl << d3 << endl << d4;

}