  // Cris Lombardo   February 13th, 2018
  // Ferhad Chohan
  // Iffat Siqqidi
  // John Slater

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  char lowerCase[] = "abcdefghijklmnopqrstuvwxyz" ;
  string str = ("Hello World!");

  // These are spaces used to create the diagonal patterns
  string holder1 = " ";
  string space1 = holder1;
  string holder2 = "              ";
  string space2 = holder2;
  string temp = " ";

  for (int i = 0; i <= 95; i++)
    {
      char buff1[] = "\b \b"; // removes last char from string

      // Runs the alphabet loop, prints letter then removes it
      for (int j = 0; j <= 27; j++)
        {
          char buff2[] = {lowerCase[j]};
          write(STDOUT_FILENO, buff2, sizeof(buff2));
          usleep(20000);
          write(STDOUT_FILENO, buff1, sizeof(buff1) - 1);
        }

      // position of value to be printed
      int printVal = i % (str.length() * 2);

      // prints the string to the right diagonal
      if (printVal <= str.length()-1){
        space1 = space1 + temp;
        cout << space1;
        cout << str[printVal] << endl;
      }
      // prints the string to the left diagonal
      else {
        space2 = space2 + buff1;
        cout << space2;
        cout << str[printVal - str.length()] << endl;
      }

      // inserts newline after complete diagonal string
      if (printVal == (str.length() * 2 - 1) || printVal == (str.length()-1))
      {
        space1 = holder1;
        space2 = holder2;
        cout << "\n";
      }

    } 

  return 0;
}
