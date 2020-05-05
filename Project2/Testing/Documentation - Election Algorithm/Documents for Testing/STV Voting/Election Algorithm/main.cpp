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
    //C:\Users\Adam\Documents\example_election_file2.csv

    TestResults = MyElection.runElection(file, 1, 1, 2);
    //First # Parameter -- number of .csv files used
    //Second # Parameter-- election type -- STV equals 1 -- Plurality equals 2

    //Third # Parameter-- total number of winners


    results = TestResults.first;

    audit = TestResults.second;



    cout << "\n\n\nResults\n\n";

    cout << results << endl << endl;

    cout << "Audit\n\n";


    cout << audit << endl << endl;


}
