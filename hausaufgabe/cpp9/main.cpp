#include "person.hpp"
#include "team.hpp"
#include "spielertrainer.hpp"
#include "wurftrainer.hpp"

int main()
{
    Team Lakers;
    Team Heat;
    Team Celtics;

    Person *p1 = new Spieler("Kobe Bryant", 24);
    Person *p2 = new Trainer("Gregg Popovich", 'A');
    Person *p3 = new WurfTrainer("Larry Bird", 'C');
    Person *p4 = new Spieler("Lebron James", 6);
    Person *p5 = new SpielerTrainer("Michael Jordan", 23, 'B');

    Lakers.hire(p1);
    Lakers.hire(p2);
    Lakers.hire(p3);

    Heat.hire(p4);
    Heat.hire(p5);

    Lakers.printteam();
    // Kobe Bryant (Spieler), 24
    // Gregg Popovich (Trainer), A Licence
    // Larry Bird (Wurf Trainer), C Licence

    Heat.printteam();
    // Lebron James (Spieler), 6
    // Michael Jordan (Spieler und Trainer), 23, B Licence

    Celtics.printteam();
    // Es gibt keine Angestellter

    return 0;
}
