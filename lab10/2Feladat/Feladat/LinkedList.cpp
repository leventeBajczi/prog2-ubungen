#include <iostream>
#include "List.h"

using namespace std;
using namespace LinkedList;



int main()
{
	SList<int> intList;

	POSITION p1=intList.push_back(1);
	POSITION p2=intList.push_back(2);
	POSITION p3=intList.push_back(3);
	POSITION p4=intList.push_back(4);
	POSITION p5=intList.push_back(5);

	for(POSITION p=intList.start();p!=intList.end();p=intList.next(p))
	{
		cout<<intList.getAt(p)<<endl;
	}

	cout<<"Remove: "<<intList.remove(p2)<<endl;
	cout<<"Remove: "<<intList.remove(p1)<<endl;
	cout<<"Remove: "<<intList.remove(p5)<<endl;
	cout<<"Remove: "<<intList.remove(p3)<<endl;
	
	intList.insert_after(p4,10);

	for(POSITION p2=intList.start();p2!=intList.end();p2=intList.next(p2))
	{
		cout<<intList.getAt(p2)<<endl;
	}

	
	return 0;
}

