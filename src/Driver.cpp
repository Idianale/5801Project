// Driver Class 
/*
#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

inline bool FileExists(const string& name);


class Driver
{
private:
    string testType;
    int test;
    string * voteFiles;
public:

  //  int[][] RunElection(int);
  //  void RunAudit(int[][]);
 
    //DONE!
    void StartUp() {
        
        char key;

        cout << "Welcome to the Election Voting System...\nThis Software is created to count ballots and display results of an election.\n\n";
        cout << "To Begin an Election: Press Enter\n";
        cout << "To Learn About the Software: Press h\n\n";

        while (true) {
            key = _getche();
            cout << key;
            if (key == 'h' || key == 'H')  {
                    DisplayHelp();
             }
            if (key == '\r') {
                DisplayTestType();
            }

        }

    }

    void DisplayTestType()
    {
        cout << "Please enter Election Type: Plurality or STV\n";
        cin >> testType;
        if (testType == "STV") {
            SetTestType(1);
        }
        else if (testType == "Plurality")
        {
            SetTestType(2);
        }
        else
        {
            cout << "Test Type not found - Please re-eneter\n\n";
            DisplayTestType();
            
        }

    }

    void SetTestType(int in) {
        if (in == 1) {
            test = 1;
        }
        if (in == 2) {
            test = 2;
        }
        GetFolderaddress();

    }



    void GetFolderaddress()
    {
        int i, x;
        string* files;
        cout << "Please enter how many files you would like to run elections on:";
        cin >> i;
        files = new (nothrow) string[i];
        if (files == nullptr) {
            cout << "Error: memory could not be allocated -- returning to main menu\n\n";
            StartUp();
        }
        else
        {
            for (x = 0; x < i; x++)
            {
                cout << "Enter File Location: ";
                cin >> files[x];
                if (FileExists(files[x]) == false)
                {
                    cout << "File: " + files[x] + " does not exist -- please reenter file names\n\n";
                    GetFolderaddress();
                }
            }
            voteFiles = files;
            delete[] files;
            //CALL ELECTION!
        }
    }

    



    //DONE!
    void ClearScreen()
    {
        //Enters in empty spaces to clear console and start new window
        cout << string(300, '\n');
    }

    //DONE!
    void DisplayHelp()
    {
        ClearScreen();
            //Displays on terminal paragraphs for the user to read on how the software is run
            //Title
            cout << "Help Window -- Press Backspace to Return to Main Menu \n\n";
        
            //Introduction
            cout << "This software has been created to count votes in an election.\n";
            cout << "Two types of election can be run with an .CSV file of ballots...\n...a Plurality election and a Single Transferable Vote (STV) election.\n\n";
       
            //User Input instructions
            cout << "When a election is run, the software will ask for a file location of the vote you wish to run...\n";
            cout << "...The Software will also ask for which specific method of test should be done.\n\n";

            //Running Software description -- Plurality
            cout << "If Plurality voting is selected...\nCandidates will be found within the election file, votes will counted one by one from each ballot.\nThe winner will be the candidate with the most votes.\n\n";
                //Running Software descriptiion -- STV
            cout << "If STV voting is selected...\nCandidates will be found within the election file.\nA Droop Quota will be determined using the number of ballots and number of candiates.\nThis voting system uses the droop quota to determine a list of winner and losers.\nWinners can be determined from four steps of counting votes.\n\n";
            cout << "1. A candidate reaches the droop quota, they is declared a winner.\n\n";
            cout << "2. If a candidate has more votes than listed in the droop quota, extra votes transfer to candadites who have not reached the quota based on ranked voting.\nThis could result in more candidates reaching the droop quota and being nominated winners.\n\n";
            cout << "3. If no-one reaches the droop quota, the candidate with the fewest votes is eliminated and the ballots are transfered to other candidates based on ranked voting.\n\n";
            cout << "4. This process is repeated until every candidate is named a winner or eliminated from the election.\n\n";
            cout << "This is the process the software takes to determine winners in the election.\n\n\n";

            //Results and Audit
            cout << "Once winners have been determined...\nThis system will display a results screen with the winning and losing candidates.\nIt will also display the order they came in, and how many votes they achieved.\n";
            cout << "The system will also create an audit of the election and place it into the folder with the ballot file.\n";
            cout << "When desired, the software will return to the main menu to run another election if desired.\n\n\n";
            

            //Backspace to exit function and return to main
            char key;
        while (true) {
            key = _getche();
            if (key == '\b'){
                ClearScreen();
                StartUp();
            }
        }
    }
};





inline bool FileExists(const string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}





int main(){
    int number;
    Driver Election;
    Sets up and gets value from user!
    Election.StartUp();
    cout << "Run Election!\n\n\n";

    cout << "Run Audit\n\n\n";


}

*/

