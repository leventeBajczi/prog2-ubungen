#include <iostream>
#include <ctime>
const std::string correctName = "haweb";
const std::string correctPasswort = "cppklasse2017";

bool enter(std::string name, std::string passwort)
{
  if(!name.compare(correctName)&& !passwort.compare(correctPasswort))
  {
    time_t tt;
    struct tm * tinfo;
    time ( &tt );
    tinfo = localtime ( &tt );
    std::cout << "Richtige Benutzername und Passwort!" << std::endl << "Hello Haweb!" << std::endl << asctime (tinfo); 
    return true;
  }
  std::cout<< "Error!" <<std::endl;
  return false;
}


int main()
{
  bool correct = false;
  while(!correct)
  {
    std::string a, b;
    std::cout<< "Benutzername: ";
    std::cin >> a;
    std::cout<< "Passwort: ";
    std::cin >> b;

    correct = enter(a, b);

  }

  

  
  return 0;
}