#include "person.hpp"
#include "hallgato.hpp"
#include "olimpikon.hpp"
#include "olimpikonhallgato.hpp"


int main(){

	//person *Pp = new person("Kovacs Elek", 1995); //  Darf nicht funktionieren

	Hallgato *Sp = new Hallgato("Kiss Peter", 1993, 3.97);
	cout << "---------------" << endl;

	Olimpikon *Op = new Olimpikon("Egerszegi Krisztia", 1974, 1992);
	cout << "---------------" << endl;

	OlimpikonHallgato *OHp = new OlimpikonHallgato ("Cseh Laszlo", 1985, 2008, 3.14);
	cout << "---------------" << endl;

	Person *tmp[3];
	tmp[0]=(Person *) Sp;
	tmp[1]=(Person *) Op;
	tmp[2]= (Person *) OHp;

	for (int i=0; i<3; i++)
	{
		tmp[i]->print();
		delete tmp[i];
		cout << endl <<"---------------" << endl;
	}
	return 0;
}