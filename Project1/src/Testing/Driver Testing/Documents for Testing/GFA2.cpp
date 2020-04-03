#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

//Test display
int main()
{
    int i = .52; //CHANGE THIS INTEGER FOR TESTING STEPS 1-5
    int x;
    string* files = new (nothrow) string[i];

    if (files == nullptr || i == 0) { //Breaks with negative integer -- will restart function at main menu (size must be positive)

        //If file size or memory allocation doesnt work -- return to main menu
        cout << "\nError: memory could not be allocated -- returning to main menu\n\n";
     //   DisplayTestType();
    }
    else
    {
        for (x = 0; x < i; x++) // Done how many times the user asks for
        {
            //Enter in file locations
            cout << "Enter File Location: ";
            cin >> files[x];
        }
        //Assign files and filesize to private variables
        for (x = 0; x < i; x++) // Done how many times the user asks for
        {
            cout << files[x] << '\n';
        }
        cout << i;

    }

}


