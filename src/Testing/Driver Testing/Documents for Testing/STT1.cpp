#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

class driver {
private:
    int test;
public:
    void setTestType(string x) {
        if (x == "STV"){
            test = 1;
        }
        else if (x == "Plurality") {
            test = 2;
        }
        else
        {
            test = 0;

        }
    }
    int getTesttype() {
        return test;

    }
};
int main()
{
    string testtemp;
    driver drive;
    cin >> testtemp;
    drive.setTestType(testtemp);

    cout << drive.getTesttype();

       
     
    }
   



