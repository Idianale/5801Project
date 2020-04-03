#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

//Test display
int main()
{
    int i;
    bool cond;
    cout << "Please enter how many files you would like to run elections on:\n";
    do
    {
        cin >> i; //Enter size
        cond = cin.fail(); // Makes sure that the value entered is a number
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    } while (cond);

    cout << i;

}


