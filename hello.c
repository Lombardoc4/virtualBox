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

  for (int i = 0; i <= str.length() - 1; i++)
    {
      char buff1[] = "\b \b";

      for (int j = 0; j <= 27; j++)
        {
          char buff2[] = {lowerCase[j]};
          write(STDOUT_FILENO, buff2, sizeof(buff2));
          usleep(50000);
          write(STDOUT_FILENO, buff1, sizeof(buff1) - 1);
         }
      cout << str[i] << endl;
    } 

  return 0;
}
