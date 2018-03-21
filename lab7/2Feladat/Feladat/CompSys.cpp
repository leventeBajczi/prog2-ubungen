#include <iostream>
using namespace std;

#include "Display.h"
#include "Printer.h"
#include "Computer.h"


int main()
{
	const unsigned maxEquipment = 4;
	Equipment *equipments[maxEquipment];

	equipments[0] = new Equipment(1, 200);
	equipments[1] = new Printer(2,12000,12000);
	equipments[2] = new Display(3,2000,6);
	equipments[3] = new Computer(4,10000,2200);
	
	for(int i = 0; i < maxEquipment; ++i)
	{
		equipments[i]->print();
		delete equipments[i];
		cout << endl;
	}

	return 0;
}
