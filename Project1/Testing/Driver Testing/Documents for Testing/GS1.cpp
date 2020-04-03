#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;


int main()
{
    bool cond;
    int i;
    cout << "Please enter how many seats you're election will have:\n";
    do
    {
        cin >> i; //Enter size
        cond = cin.fail(); // Makes sure that the value entered is a number
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    } while (cond);

    
    cout << abs(i); // output should always be positive and be equal to an integer -- will not allow max
   
     
    }
   



