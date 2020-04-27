//
// Created by m0narch on 3/27/20.
//
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <vector>
#include "BallotBox.cpp"
#include "BallotBox.h"
#include "Candidate.h"
#include "Candidate.cpp"
#include "Candidates.h"
#include "Candidates.cpp"
#include "Election.h"
#include "Election.cpp"
#include "Reporter.cpp"
#include "Driver.cpp"

int main() {

    Driver Data;
    Election Elect;
    Reporter report;
    Candidates Cands;
    //Get inputs from User
    Data.Drive();

    //Run Election Algorthim
    Elect.runElection(Data.getVoteFiles(), Data.getSize(), Data.getTest(), Data.getTotalSeats());
    //Inputs --- Vote files-- Total # of vote files -- Test # -- Total # of seats

    //Start Audit
    report.createAudit(); // Creates Audit
    report.writeToFile(Data.getTest(), Data.getTotalSeats(), Cands.getAllCount(), Cands.getWinnerCount(), Cands.getLosersCount()); //Writes Audit to File
        //Inputs --- Test # -- Total # of seats -- Total Candidates -- Total Winners -- Total Losers

    report.writeToScreen(Data.getTest(), BallotBox.GetVoteTotal(), Data.getTotalSeats(), Cands.getAllCount(), Cands.getWinnerCount(), Cands.getLosersCount(); //Writes the results to the screen
    //Inputs --- Test # -- Total # of votes -- Total # of seats -- Total Candidates -- Total Winners -- Total Losers

    delete[] Data.getVoteFiles();

    system("PAUSE");

}
