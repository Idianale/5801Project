#include <iostream>
#include "BallotBox.h"


//Initalizes a Ballotbox
BallotBox::BallotBox() {
    electionType = 1;
    voteTotal = 0;
    colTotal = 0;
    ballots = NULL;

}

//Initalizes a Ballotbox with a input election type 
BallotBox::BallotBox(int electionType_) {
    electionType = electionType_;
    voteTotal = 0;
    colTotal = 0;
    ballots = NULL;

}

//Get values within Ballot Box
int BallotBox::GetVoteTotal() { return voteTotal; }
int BallotBox::GetTotalColumns() { return colTotal; }
int** BallotBox::GetBallots() { return ballots; }



/*The main function within ballot box that creates a 2D array of ballots for counting.
 This function also includes ballotbox validatiion where invalid votes are flagged and not counted.
This function also determines is a proper filename address has been entered and if the election is considered valid.*/
int** BallotBox::AddVotes(string* filenames, int fileTotal) {
    using namespace std;
    cout << "Invalid Ballot Report" << endl << endl;
    //Step 1: go through every file line by line to determine number of votes (row count for 2d votes array)
  //  cout << "inBallotBox::AddVotes\n";
    int totalVotes = 0;
    int invalidVotes = 0;
    int totalVotestemp = 0;
    for (int i = 0; i < fileTotal; i++) {
      //  cout << filenames[i];
        fstream fin(filenames[i]);
        if (!fin.is_open())
        {
        //    cout << "test";
            cout << "Error - .csv file is not found\n";
            return NULL;
        }
        int temp =
            count(std::istreambuf_iterator<char>(fin),
                std::istreambuf_iterator<char>(), '\n');
    //    cout << "temp votes is " << temp << endl;
        totalVotes += (temp);
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
   // cout << "about to create new int pointer table. total votes is " << totalVotes << endl;
    int** voteTable = new int* [totalVotes];
    int* InvalidBallot = new int[totalVotes];

  //  cout << "table created\n";
    int it = 0; //global iterator, persistent between files
    // iterate over all files:
    int temptotal = totalVotes;
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
                    InvalidBallot[it] = 1;
                    invalidVotes = invalidVotes + 1;
                    cout << "Invalid Ballot found in row: " << it << endl;

                    for (int t = 0; t < 4; t++)
                    {
                        cout << x[t] << " ";

                    }
                    cout << endl;
                    voteTable[it] = x;
                    it++;
                }
                else{
                    voteTable[it] = x;
                    it++;
                }
            }
            else
            {
                // invalid vote is a blank vote
          //      invalidVotes = invalidVotes + 1;
            }
        }
        fin.close();
    }
    if (invalidVotes >= (totalVotestemp / 2))
    {
        ballots = NULL;
    }
    else {
        //Delete any invalid Ballots
        int totalgone = 0;
        for (int j = 0; j < totalVotes; j++) {
            if (InvalidBallot[j] == 1) {
                
                int rowToDel = (j-totalgone);
                delete[] voteTable[rowToDel];
                int** tmp = new int* [totalVotes - 1];
                int tmpI = 0;
                for (int i = 0; i < totalVotes; ++i)
                    if (i != rowToDel)
                        tmp[tmpI++] = voteTable[i];
                delete[] voteTable;
                voteTable = tmp;
                voteTotal = voteTotal - 1;
             //   cout << "Row: " << rowToDel << endl;
               // cout << voteTotal << endl;
                totalgone = totalgone + 1;
            }

        }
        for (int i = 0; i < voteTotal; i++)
        {
            for (int j = 0; j < colTotal; j++)
            {
            //    cout << voteTable[i][j] << "   ";

            }
          //  cout << endl;
        }

        ballots = voteTable;
        return voteTable;
    }
    
    return NULL;
}