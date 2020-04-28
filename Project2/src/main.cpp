#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <fstream>
#include <string>


#include "Election.h"
#include "BallotBox.h"

int main() {

    bool correctFiles;
    bool correctseats;
    bool correct;

    std::pair<std::string, std::string> textwrite;
    srand(static_cast<int>(time(0)));//Used for coin toss
    string auditElection;
    string resultsElection;




    cout << "Election kicked off" << endl;
    Election myElection(1);
    //1 allows us to shuffle order -- 0 keeps the order from the file
    string myString[2];
    //C:\Users\Adam\Downloads\example_election_file.csv
    //C:\Users\Adam\Downloads\example_election_file2.csv

    cin >> myString[0];
    if (std::fstream{ myString[0] }) {
        std::cout << "file exists\n";
    }

    cin >> myString[1];
    cout << "Election will now begin" << endl;
    textwrite = myElection.runElection(myString, 2, 2, 5);

    auditElection = textwrite.second;
    resultsElection = textwrite.first;

    //  cout << auditElection << "\n\nResults\n\n\n";
     // cout << resultsElection << "\n\nAudit\n\n\n";
    ofstream Audit("Result_Audit.txt");
    if (Audit.is_open())
    {
        Audit << "Results\n\n";
        Audit << resultsElection;
        Audit << "\n\nAudit\n\n";
        Audit << auditElection;

        Audit.close();
    }
    else cout << "Unable to open file";

    // delete[] resultstest;
     // string of text file location for the report

     // Report

     // Audit
    return 0;
}