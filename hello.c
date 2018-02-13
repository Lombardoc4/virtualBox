#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  char lowerCase[] = "abcdefghijklmnopqrstuvwxyz" ;
  string str = ("Hello World!");
  unsigned int microseconds;
  string space1 = " ";
  string space2 = " ";
  string space3 = "           ";

  for (int i = 0; i <= 100; i++)
    {
      char buff1[] = "\b \b";

      for (int j = 0; j <= 27; j++)
        {
          char buff2[] = {lowerCase[j]};
          write(STDOUT_FILENO, buff2, sizeof(buff2));
          usleep(50000);
          write(STDOUT_FILENO, buff1, sizeof(buff1) - 1);
         }
      int printVal = i % (str.length() * 2);
      if (printVal <= str.length()){
        space1 = space1 + space2;
        cout << space1;
        cout << str[printVal] << endl;
      }
      else {
        cout << "\b \b";
        // space3 = space1 - space2;
        // cout << space3;
        // Fix this shit how can we print the space then subtract
        // also fix print val its printing ello World! (without H)
        cout << str[printVal - str.length()] << endl;
      }

    }


  return 0;
}
