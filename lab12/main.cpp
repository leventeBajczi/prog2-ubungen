#include "stack.hpp"
#include <iostream>
using namespace std;
int main()
{
	Stack<int>S1(5);
	if(S1.isEmpty()) cout << "Stack ist leer!" << endl;
	cout << "Grosse:" << S1.getSize() << endl;
	S1.push(1);                                         //1
	S1.push(2);                                         //2 1
	S1.push(3);                                         //3 2 1

	cout << S1.pop() << endl;                           //2 1 -> 3
	cout << S1.pop() << endl;                           //1   -> 2
	
	S1.dup();                                           //1 1
	
	S1.push(9);                                         //9 1 1 
	
	S1.swap();                                          //1 9 1
	
	Stack<int> S2(S1);
	Stack<int> S3 = S2;
	cout << S1.pop() << endl;                           //9 1 -> 1
	cout << S1.pop() << endl;                           //1   -> 9
	cout << S1.pop() << endl;                           //{}  -> 1
	return 0;
}