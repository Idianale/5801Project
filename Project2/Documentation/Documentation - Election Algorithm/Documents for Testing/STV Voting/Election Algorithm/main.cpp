#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <fstream>
#include <string>

#include "Election.h"
#include "BallotBox.h"
#include "Candidates.h"


/*
    This is the "Test" for our election algorithm. Currently, inputs from the user such as the total winners and the location of the .csv file are not properly implmented with the GUI as seen in the turned in algorthim. This is a test project that...
    ...shows how our algorthim works. Inputs are typed into the main function and the whole project can be compiled and run. Our GUI also has a results page that needs to be fully implmented taking the strings that are resulted from running an election.
    These strings include an Audit, Ballot Validation section, and a results section. For this test algorthim for grading purposes and to see progress, these string will be output in the terminal to show how an election is run. The parameters within the RunElection
    function are used to vary the algorthim.
*/

int main()
{

    Election MyElection(0);

    string file[1];
    string results;
    string audit;   


    std::pair<std::string, std::string> TestResults;
    using namespace std;

    cin >> file[0];

   
      

    // First number parameter in runElection function 
    //If one is selected -- STV election is run
    //IF two is selected -- Plurality election is run
    //C:\Users\Adam\Downloads\example_election_file2.csv
   // cout << file[0];
    TestResults = MyElection.runElection(file, 2, 1, 2);
    //First # Parameter -- Election Type
    //Second # Parameter-- number of .csv files used
    //Third # Parameter-- total number of winners

    
    results = TestResults.first;

    audit = TestResults.second;



    cout << "\n\n\nResults\n\n";

    cout << results << endl << endl;

    cout << "Audit\n\n";


    cout << audit << endl << endl;


}