#include <iostream>
#include "BallotBox.h"

BallotBox::BallotBox() {
    electionType = 1;
    voteTotal = 0;
    colTotal = 0;
    ballots = NULL;

}
BallotBox::BallotBox(int electionType_) {
    electionType = electionType_;
    voteTotal = 0;
    colTotal = 0;
    ballots = NULL;

}

// BallotBox::BallotBox(string* filenames,int fileTotal, int electionType_){
//   electionType = electionType_;
//   voteTotal = 0;
//   colTotal = 0;
//   ballots = NULL;
//   int**x = AddVotes(filenames, fileTotal);
// }


int BallotBox::GetVoteTotal() { return voteTotal; }
int BallotBox::GetTotalColumns() { return colTotal; }
int** BallotBox::GetBallots() { return ballots; }

int** BallotBox::AddVotes(string* filenames, int fileTotal) {
    using namespace std;
    //Step 1: go through every file line by line to determine number of votes (row count for 2d votes array)
    cout << "inBallotBox::AddVotes\n";
    int totalVotes = 0;
    int invalidVotes = 0;
    int totalVotestemp = 0;
    for (int i = 0; i < fileTotal; i++) {
        fstream fin(filenames[i]);
        if (!fin.is_open())
        {
            cout << "Error in BallotBox.cpp; csv file is not found\n";
        }
        int temp =
            count(std::istreambuf_iterator<char>(fin),
                std::istreambuf_iterator<char>(), '\n');
        cout << "temp votes is " << temp << endl;
        totalVotes += (temp - 1);
        fin.close();
    }
    // std::cout << "Total votes is " << totalVotes << endl; // debug
    voteTotal += totalVotes;
    totalVotestemp = totalVotes;
    // Step 2: Determine candidate count for column of 2d votes array
    int totalCols = 0;
    fstream fin2(filenames[0]);
    std::string line;
    std::getline(fin2, line);
    std::stringstream s_row2(line);
    std::string entry;
    while (getline(s_row2, entry, ','))
        totalCols++;
    // cout << "Total Columns is " << totalCols << "\n"; // debug
    colTotal = totalCols;
    fin2.close();
    
    // Step 3: create a 2d array containing vote values
    cout << "about to create new int pointer table. total votes is " << totalVotes << endl;
    int** voteTable = new int* [totalVotes];
    cout << "table created\n";
    int it = 0; //global iterator, persistent between files
    // iterate over all files:
    for (int i = 0; i < fileTotal; i++) {
        fstream fin(filenames[i]);
        std::string temp;
        getline(fin, line);
        //skip initial line containing candidate names
        // cout << line <<endl; // debug
        // check this does not affect results
        while (getline(fin, line) && it < totalVotes) {
            // cout << line << endl; // debug

            // skip the empty line found at the end of every csv file
            if (!line.empty()) {
                // place row of csv file in string stream
                stringstream s_row(line);
                // create new row of ints
                int* x = new int[totalCols];
                string word;
                int j = 0;
                int emptycount = 0;
                while (getline(s_row, word, ',') && j < totalCols) {
                    int entry;
                    if (word.empty()) {
                        entry = 0;
                        emptycount = emptycount + 1;
                    }
                    else {
                        entry = stoi(word);
                    }
                    x[j] = entry;
                    j++;
                }

                // NEW -- test for if the proper number of candidates have been ranked and that the test is STV
                //Skips adding row to voteTable -- rerun next row on the same iteration
                //Deletes the last row on the voteTable array to make sure no rows are left blank
                //Set total votes to one less
                if (emptycount >= (colTotal / 2) && (electionType == 1)) {
                   
                    delete[] voteTable[totalVotes-1];
                    totalVotes = totalVotes - 1;
                    invalidVotes = invalidVotes + 1;
                }
                else{
                    voteTable[it] = x;
                    it++;
                }
            }
            else
            {
                // invalid vote is a blank vote
                invalidVotes = invalidVotes + 1;
            }
        }
        fin.close();
    }
    if (invalidVotes >= (totalVotestemp / 2))
    {
        ballots = NULL;
    }
    else {
        ballots = voteTable;
        return voteTable;
    }
    
    return NULL;
}