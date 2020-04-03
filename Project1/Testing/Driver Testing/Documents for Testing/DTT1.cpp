#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;


int main()
{
    string testtemp;

    cin >> testtemp;
  
        if (testtemp == "Plurality")
        {
            cout << "PLurality detected\n"; //If h is pressed

        }
        else if (testtemp == "STV")
        {
            cout << "STV detected\n"; //If enter is pressed 

        }
        else {
            cout << "Test Type not Found\n";
        }
     
    }
   



