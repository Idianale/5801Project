#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;


int main()
{
    char key;
    while (true) {
        key = _getche();
        if (key == 'h' || key == 'H')
        {
            cout << "Help has been Pressed\n"; //If h is pressed

        }
        if (key == '\r')
        {
            cout << "Election has been presed\n"; //If enter is pressed 

        }
     
    }
   
}


