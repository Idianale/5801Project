//
// Created by m0narch on 3/27/20.
//
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <vector>
#include <BallotBox.cpp>
#include <BallotBox.h>
#include <Candidate.h>
#include <Candidate.cpp>
#include <Candidates.h>
#include <Candidates.cpp>
#include <Election.h>
#include <Election.cpp>
#include <Reporter.h>
#include <Reporter.cpp>

int main(){

        Driver driver;
        Election Election;
        Reporter report;
    
            //Get inputs from User
            driver.Drive()

                //Run Election Algorthim
            Election.runElection(Data.getVoteFiles(), Data.getSize(), Data.getTest(), Data.getTotalSeats())
            //Inputs --- Vote files-- Total # of vote files -- Test # -- Total # of seats

            //Start Audit
            Reporter.createAudit() // Creates Audit
            Reporter.writeToFile(Data.getTest(), Data.getTotalSeats(), Cand.getAllCount(), Cand.getWinnerCount(), Cand.getLosersCount()) //Writes Audit to File
            //Inputs --- Test # -- Total # of seats -- Total Candidates -- Total Winners -- Total Losers

            Reporter.writeToScreen(Data.getTest(), BallotBox.GetVoteTotal(), Data.getTotalSeats(), Cand.getAllCount(), Cand.getWinnerCount(), Cand.getLosersCount() //Writes the results to the screen
            //Inputs --- Test # -- Total # of votes -- Total # of seats -- Total Candidates -- Total Winners -- Total Losers
                
            delete[] driver.getVoteFiles();

        system("PAUSE");
    
    }
