#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

//Test display
inline bool FileExists(const string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0); // returns boolean of this name is found within system
}

int main()
{

    //Test.txt is a blank text file created by me --- used for testing
    string file1; // Should be True 
    string file2; // Should be True!
    string file3; //Should be false! 

    cin >> file1;// C:\Users\Adam\Documents\Test.txt typed in
    cin >> file2;// C:\Test.txt typed in
    cin >> file3;// aewrhgwaeliku124906 typed in



    cout << FileExists(file1) << "   " << FileExists(file2) << "   " << FileExists(file3) << "   ";
}


