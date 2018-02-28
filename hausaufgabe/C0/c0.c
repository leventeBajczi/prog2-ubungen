#include <time.h>
#include <stdio.h>

int main()
{
  time_t tt;
  struct tm * tinfo;
  time ( &tt );
  tinfo = localtime ( &tt );
  printf ( "Helllo Haweb!\nProgram startet am: %s", asctime (tinfo) );

  return 0;
}