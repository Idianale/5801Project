// Driver Class 

#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <vector>


using namespace std;


//Checks if a string file exists
inline bool FileExists(const string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0); // returns boolean of this name is found within system
}


class Driver
{
private:
    //Test #
    int test;

    //array of voteFiles
    string* voteFiles;
    //Total number of files
    int filesize;

    //Total seats
    int Seats;
public:

    //This method displays the Main Menu 
    void StartUp() {

        // Display the welcome screen
        cout << "Welcome to the Election Voting System...\nThis Software is created to count ballots and display results of an election.\n\n";
        cout << "To Begin an Election: Press Enter\n";
        cout << "To Learn About the Software: Press h\n\n";

    }

    /**
      *  This Method Prompts the user for a specific test type and sets a private variable as that.
      *  It takes a case sensitive string from the user and identifies which method is being used.
         It then moves to setting the testtype.*/
    void DisplayTestType()
    {
        string testType;
        cout << "Please enter Election Type: Plurality or STV (CASE SENSITIVE)\n";
        cin >> testType;
        //This is case sensitive and the testType
        if (testType == "STV") {
            SetTestType(1);  //STV test is allocated to integer 1
        }
        else if (testType == "Plurality")
        {
            SetTestType(2); // Plurality test is allocated to integer 2
        }
        else
        {
            // One of these values must be entered to continue on
            cout << "Test Type not found - Please re-eneter\n\n";
            DisplayTestType();

        }

    }
    
    // Sets test type to private variable
    void SetTestType(int in) {
        if (in == 1) {
            test = 1; //Sets private test to 1 (STV)
        }
        if (in == 2) {
            test = 2;//Sets private test to 2 (Plurality)
        }
        GetSeats();

    }

    //Gets Cin from user, this is total number of seats must be positive and an integer
    void GetSeats() {

        bool cond;
        int i;
        cout << "Please enter how many seats you're election will have:\n";
        do
        {
            cin >> i; //Enter seats
            cond = cin.fail(); // Makes sure that the value entered is a number
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } while (cond);



        Seats = abs(i); //Seats will be only a positive integer -- if negative is input -- turns it positive
        GetFolderaddress(); // Go to Folder Address 




    }
    /**This function is dedicated to getting the folder addresses from the user.
    *  It takes in the how many file a user wants, it makes sure that the
    * the user inputs a correct value. The function then makes sure a array has been made and then
    * applys the string names to the user. If a part of this process is incorrect, it returns the user to the main menu or
    * asks the user to reinput data.
    */ 
    void GetFolderaddress()
    {
        int x;
        int i;
        bool cond;
        // i is our size
        cout << "Please enter how many files you would like to run an election on:\n";
        do
        {
            cin >> i; //Enter size
            cond = cin.fail(); // Makes sure that the value entered is a number
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } while (cond);

        //Creates a new temporary array
        string* files = new (nothrow) string[i];

        if (files == nullptr) { //Breaks with negative integer -- will restart function at main menu (size must be positive)

            //If file size or memory allocation doesnt work -- return to main menu
            cout << "\nError: memory could not be allocated -- returning to main menu\n\n";
            delete[] files;
            DisplayTestType();
        }
        else
        {
            for (x = 0; x < i; x++) // Done how many times the user asks for
            {
                //Enter in file locations
                cout << "Enter File Location: ";
                cin >> files[x];
                if (FileExists(files[x]) == false) //If file location doesnt exists - start process over again
                {
                    cout << "File: " + files[x] + " does not exist -- please reenter file names\n\n";
                    delete[] files;
                    GetFolderaddress();
                    return;
                }
            }
            //Assign files and filesize to private variables
            voteFiles = files;
            filesize = i;

        }

    }




    //Adds spaces to the screen
    void ClearScreen()
    {
        //Enters in empty spaces to clear console and start new window
        cout << string(300, '\n');
    }


    //Displays the help window to the user
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
        cout << "When a election is run, the software will ask for a file location(s) of the vote you wish to run...\n";
        cout << "...The Software will also ask for which specific method of test should be done.\n\n";

        //Running Software description -- Plurality
        cout << "If Plurality voting is selected...\nCandidates will be found within the election file(s), votes will counted one by one from each ballot.\nThe winner will be the candidate with the most votes.\n\n";
        //Running Software descriptiion -- STV
        cout << "If STV voting is selected...\nCandidates will be found within the election file(s).\nA Droop Quota will be determined using the number of ballots and number of candiates.\nThis voting system uses the droop quota to determine a list of winner and losers.\nWinners can be determined from four steps of counting votes.\n\n";
        cout << "1. A candidate reaches the droop quota, they is declared a winner.\n\n";
        cout << "2. If a candidate has more votes than listed in the droop quota, extra votes transfer to candadites who have not reached the quota based on ranked voting.\nThis could result in more candidates reaching the droop quota and being nominated winners.\n\n";
        cout << "3. If no-one reaches the droop quota, the candidate with the fewest votes is eliminated and the ballots are transfered to other candidates based on ranked voting.\n\n";
        cout << "4. This process is repeated until every candidate is named a winner or eliminated from the election.\n\n";
        cout << "This is the process the software takes to determine winners in the election.\n\n\n";

        //Results and Audit
        cout << "Once winners have been determined...\nThis system will display a results screen with the winning and losing candidates.\nIt will also display the order they came in, and how many votes they achieved.\n";
        cout << "The system will also create an audit of the election and place it into the folder with the ballot file.\n";
        cout << "When desired, the software will return to the main menu to run another election if desired.\n\n\n";

    }

    //Gets the test value
    int getTest() {
        return test;
    }

    //Gets the voter files
    string* getVoteFiles() {
        return voteFiles;
    }

    //Gets the Total Seats
    int getTotalSeats() {
        return Seats;
    }

    //Gets the number of files
    int getSize() {
        return filesize;

    }




    /* Movement of the driver. It takes the user from the main menu through all of the input methods to up until the election
    *  starts. It uses the getche function which is a keyboard logger and moves through each of the input steps needed for an election.
    */
    void Drive() {
        int number;
        Driver Data;


      //  Sets up and gets value from user!
        Data.StartUp();
        // Algorthim for key input
        while (true) {
            char key;
            key = _getche();
            //If "h" is pressed -- display help
            if (key == 'h' || key == 'H') {
                //Displays Help
                Data.DisplayHelp();


                char key; // If Backspace is pressed -- return to main menu
                while (true) {
                    key = _getche();
                    if (key == '\b') {
                        //Adds Space

                        Data.ClearScreen();


                        Data.StartUp(); // Returns to Main Menu
                        break;
                    }
                }
            }
            //If enter is pressed -- start election and get data
            if (key == '\r') {
                //Gets the filenames and election type from the user
                Data.DisplayTestType();
                break;
            }

        }
    }
};
