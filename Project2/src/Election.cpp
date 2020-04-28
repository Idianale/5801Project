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
    To do:
    implement coin toss
    implement plurality election
    test elections
*/


Election::Election(bool shufflestatus_) {
    cout << "Election being initilized" << endl;
    shuffle_status = shufflestatus_;
    ballotBox = NULL;
    candArr = NULL;
    candVal = NULL;
    candidateBypassLoser = NULL;
    candidateBypassUndecided = NULL;
    candidateBypassVoteCounts = NULL;
    candidateBypassWinner = NULL;
    candidateTotal = 0;
    candidates = NULL;
    cbl = NULL;
    droopCount = 0;
    electionType_ = 0;
    results = NULL;
    seatNum_ = 0;
    voteTotal = 0;
    voteVals = 0;
    votes = NULL;
    Audit = "";
    TextResults = "";
}

std::pair<std::string,std::string> Election::runElection(string* filenames, int fileSize,
    int electionType, int seatNum) {

    using namespace std;
    // create BallotBox values
    BallotBox* myBallotBox = new BallotBox(electionType);
    votes = myBallotBox->AddVotes(filenames, fileSize);
    if (votes == NULL)
    {
      //  string noTest[2] = { "Test does not have at least 50% valid ballots -- no election was run" ,"" };
        return std::make_pair("Test does not have at least 50% valid ballots -- no election was run", "");
    }
    ballotBox = myBallotBox;
    seatNum_ = seatNum;
    int tmp = myBallotBox->GetTotalColumns();
    string* candidateNames = new string[tmp];
    // create Candidate values
    Candidates* myCandidates = new Candidates();
    fstream fin(filenames[0]);
    std::string line;
    std::string temp;
    getline(fin, line);
    stringstream s_row(line);
    string word;
    int j = 0;
    while (getline(s_row, word, ',') && j < tmp) {
        myCandidates->addCandidate(word);
        candidateNames[j] = word;
        j++;
    }
    candidates = myCandidates;

    voteTotal = ballotBox->GetVoteTotal();
    candidateTotal = candidates->getAllCount();
    if (candidateTotal < seatNum || seatNum < 0)
    {
        return std::make_pair("Number of winners not a valid number", "");
    }
    electionType_ = electionType;
    // Set Droop Quota
    droopCount = (voteTotal / (seatNum + 1)) + 1;
    Audit.append("The Droop Quota is: ");
    Audit.append(to_string(droopCount) + "\n");
    // cout << "The Droop Quota is: " << droopCount << "\n";
    if (shuffle_status)
        votes = shuffleelection(); //DEBUG, re-enable later
        int** results;

    //CandidateBypass
    candArr = new int[candidateTotal];
    candVal = new int[candidateTotal];
    for (int i = 0; i < candidateTotal; i++) {
        candArr[i] = 0;
        candVal[i] = 0;
    }

    // STV Election Type
    if (electionType_ == 1) {
        Audit.append("STV Election selected.\n");
        //cout << "STV Election selected" << endl;
        results = STVProtocol(candidateNames);
    }
    // Plurality Election Type
    else if (electionType_ == 2) {
        Audit.append("Plurality Election selected.\n");
       // cout << "Plurality Election selected" << endl;
        results = PluralityProtocol(candidateNames);
    }
   // string Testdone[2] = {TextResults,Audit};
   // cout << endl << TextResults << endl;
    //cout << endl << Audit << endl;
    return std::make_pair(TextResults,Audit);
  //  return { Audit,TextResults };

}

int Election::getTotalUndecided() {
    int j = 0;
    for (int i = 0; i < candidateTotal; i++) {
        if (candArr[i] == 0) {
            // cout << "Candidate " << i << " is still in"<<endl;
            j++;
        }
    }
    return j;
}

int** Election::STVProtocol(string* candidateNames) {
    int loopCatcher = 0;
    voteVals = new int[voteTotal];
    for (int i = 0; i < voteTotal; i++) {
        voteVals[i] = -1; //Associated vote not set for any given candidate
    }
    while (getTotalUndecided() > 0 && loopCatcher < 4) {
        Audit.append("There Are " + to_string(getTotalUndecided()) + " Candidates still in.\n");
     //   cout << "there are " << getTotalUndecided() << " Candidates still in" << endl;
        for (int bnum = 0; bnum < voteTotal; bnum++) {
            if (voteVals[bnum] == -1) {
                int newVoteVal = setVoteVals(votes[bnum]); // newVoteVal is current vote's winning candidate (rank 1)
                voteVals[bnum] = newVoteVal;
                candVal[newVoteVal]++; // inc local vote

               // Candidate* CNew;
                int obnoxiousBypass = 0;

                for (auto i = candidates->candidateList.begin(); i != candidates->candidateList.end(); i++) {
              //      CNew = &*i;
                    if (obnoxiousBypass != newVoteVal)
                        obnoxiousBypass++;
                    else
                        break;
                }
             //   CNew->incrementVote();

                if (candVal[newVoteVal] == droopCount)
                {
                    Audit.append("A new winner has been found with the lastest count.\nThe winner will now be identified and votes will be redistributed\n");
                    //cout << "A new winner has been found with the lastest count" << endl;
                    // STVWinnerProtocol(newVoteVal, candidateNames, bnum);
                    STVWinnerProtocolB(newVoteVal, candidateNames, bnum);
                }
            }
        }
        if (getTotalUndecided() != 0 && loopCatcher < 4) {
            
            Audit.append("A new loser has been found with the lastest count.\nThe loser will now be identified and votes will be redistributed\n");
          //  cout << "A new loser has been fond with the lastest count" << endl;
            loopCatcher++;
            // STVLoserProtocol(candidateNames);
            STVLoserProtocolB(candidateNames);
        }
    }
    int lastWin = 0;
    for (int i = 0; i < candidateTotal; i++) {
        if (candArr[i] >= lastWin) {
            lastWin = candArr[i];
        }
    }
    for (int i = 0; i < candidateTotal; i++) {
        if (candArr[i] < 0) {
            candArr[i] = lastWin - candArr[i];
        }
    }
    Audit.append("Election has now been complete.\n");

        // cout << "Election Complete" << endl;
    TextResults.append("Candidate Ranking:\n");

    //    cout << "Candidate Ranking:" << endl;
    int win = 1;
    for (int i = 0; i < seatNum_; i++) {
      //  cout << "Winner " << (i+1) << ": ";
        TextResults.append("Winner " + to_string((i + 1))+ ": ");
        for (int i = 0; i < candidateTotal; i++) {
            if (candArr[i] == win) {
                TextResults.append(candidateNames[i] + " with " + to_string(candVal[i]) + " votes.\n");
                //cout << candidateNames[i] << " with " << candVal[i] << " votes" << endl;
                win++;
                i = candidateTotal;
            }
            else
            {
       //         cout << "Loser: " << candidateNames[i] << " with " << candVal[i] << " votes" << endl;
            }
        }
    }
    return votes;

}

/*
  STVWinnerProtocol: this function
    1. adds the winning candidate to the list of winner candidates
    2. Changes remaining votes in array so that they no longer have that
       candidate, or any previous candidate finalists, as their first choice.
*/

void Election::STVWinnerProtocolB(int newWinner, string* candidateNames, int ivote) {
    candidates->setCandidate(candidateNames[newWinner], candidates->undecided, candidates->winners);
    finalists.push_back(newWinner);

    //bypass
    int newWinVal = 0;
    for (int i = 0; i < candidateTotal; i++)
        if (candArr[i] >= newWinVal)
            newWinVal = candArr[i];
    newWinVal++;
    candArr[newWinner] = newWinVal;

    ivote++;
    for (; ivote < voteTotal; ivote++) {
        bool voteAltered = false;
        for (auto i = finalists.begin(); i != finalists.end(); i++) {
            if (votes[ivote][*i] == 1) {
                adjustVote(votes[ivote]);
                voteVals[ivote] = -1;
                voteAltered = true;
            }
        }
        if (voteAltered) // reiterate over prior vote rankings from start
            ivote--;
    }
}


void Election::STVWinnerProtocol(int newWinner, string* candidateNames, int ivote) {
    candidates->setCandidate(candidateNames[newWinner], candidates->undecided, candidates->winners);
    finalists.push_back(newWinner);
    ivote++;
    for (; ivote < voteTotal; ivote++) {
        bool voteAltered = false;
        for (auto i = finalists.begin(); i != finalists.end(); i++) {
            if (votes[ivote][*i] == 1) {
                adjustVote(votes[ivote]);
                voteVals[ivote] = -1;
                voteAltered = true;
            }
        }
        if (voteAltered) // reiterate over prior vote rankings from start
            ivote--;
    }
}

bool Election::nonFinalist(int candVal) {
    return candArr[candVal] == 0;
}

void Election::STVLoserProtocolB(string* candidateNames) {
    int lowVote = candVal[0];
    int newLoss = 0;
    for (int i = 0; i < candidateTotal; i++) {
        if (candVal[i] <= lowVote && nonFinalist(i))
        {
            lowVote = candVal[i];
            newLoss = i;
        }
    }
    Audit.append("Latest Loser is " + candidateNames[newLoss] + " with " + to_string(candVal[newLoss]) + " votes.\n");

  //  cout << "Latest Loser is " << candidateNames[newLoss] << " with " << candVal[newLoss] << " votes." << endl;
    for (int i = 0; i < candidateTotal; i++) {
        if (candArr[i] < 0) {
            candArr[i]--;
        }
    }
    candArr[newLoss] = -1;
    Audit.append("There are now " + to_string(getTotalUndecided()) + " candidates remaining.\n");
   // cout << "There are now " << getTotalUndecided() << " candidates remaining." << endl;

    finalists.push_back(newLoss);
    if (getTotalUndecided()) {
        Audit.append("Votes will now be redistributed based on rankings\n");
     //   cout << "Votes will now be redistributed based on rankings" << endl;
        for (int bnum = 0; bnum < voteTotal; bnum++) {
            bool adjustedVote = false;
            for (auto i = finalists.begin(); i < finalists.end(); i++) {
                if (bnum >= 0) {
                    if (votes[bnum][*i] == 1) {
                        //       cout << "vote " << bnum << " reads " << votes[bnum][0] << " " << votes[bnum][1]<<endl;
                        adjustVote(votes[bnum]);
                        //      cout << "vote " << bnum << " reads " << votes[bnum][0] << " " << votes[bnum][1]<<endl;
                        voteVals[bnum] = -1;
                        adjustedVote = true;
                    }
                    if (adjustedVote){
                        bnum--;
                        }
                }
            }
        }
    }
}

//Picks one number of the other randomly
int Election::coinToss(int candidateA, int candidateB) {
    int flip;
    flip = rand() % 2 + 1;// assign random numbers
    if (flip == 1) {
        return candidateA;
    }
    else {
        return candidateB;
    }
 
    
}

int Election::findNewLoser(string* candidateNames, string newName) {
    int j = 0;
    for (auto i = candidates->candidateList.begin(); i < candidates->candidateList.end(); i++) {
        Candidate c = *i;
        if (c.getName() == newName)
            return j;
        else
            j++;
    }
    // default case, will only happen if candidate is not found somehow
    return -1;
}

/*
  adjustVote changes votes to have a new rank-1 candidate value
  e.g. if given votes v1  = [1,2,3,4] v2  = [-1,2, 0,1]
       they become    v1 == [0,1,2,3] v2 == [-2,1,-1,0]
*/
void Election::adjustVote(int* thisVote) {
    for (int i = 0; i < candidateTotal; i++) {
        thisVote[i]--;
    }

}

int Election::setVoteVals(int* ballot) {
    for (int i = 0; i < candidateTotal; i++) {
        if (ballot[i] == 1)
            return i;
    }
    return 0;
}






/*
  important function values:
    votes: 2D array containing votes,in the form
          votes[specificBallot][specificCandidateRanking]
          So votes[0] might be [0,1,0,0]
    candidateTotal: int, total number of candidates
    candidates: pointer to relevant Candidates class
    voteTotal: int, total number of votes
*/

int** Election::PluralityProtocol(string* candidateNames) {
    int* votecounts = new int[candidateTotal];
    for (int i = 0; i < candidateTotal; i++)
    {
        votecounts[i] = 0;
    }
    Audit.append("Total Number of Votes cast: " + to_string(voteTotal) + "\n");
  //  cout << "Total Number of Votes cast: " << voteTotal << endl;
    for (int i = 0; i < voteTotal; i++) {
        for (int j = 0; j < candidateTotal; j++) {
           // cout << votes[i][j] << "  " << i << "  " << j << endl;
            if (votes[i][j] == 1) {
                votecounts[j] = votecounts[j] + 1;
            }
        }
    }
    int winner = 0;
    if (seatNum_ == 1) {
    for (int i = 1; i < candidateTotal; i++) {
        if (votecounts[i] > votecounts[winner])
            winner = i;
        else if (votecounts[i] == votecounts[winner])
            winner = coinToss(i, winner);
        Audit.append("Due to a tie, a winner will be determined by a coin toss.\n");

    }
    TextResults.append("The winner is Candidate " + candidateNames[winner] + " with " + to_string(votecounts[winner]) + " votes.\n");
          }
    else
    {
        //Multiple Seats
        int* tempvotecounts = new int[candidateTotal];
        tempvotecounts = votecounts;
        sort(tempvotecounts, tempvotecounts + candidateTotal, greater<int>());
        for (int i = 0; i < seatNum_; i++) {
            for (int j = 0; j < candidateTotal; j++)
            {
                if (tempvotecounts[i] == votecounts[j])
                {
               
                    TextResults.append("Winner " + to_string((i + 1)) + ": " + candidateNames[j] + " with " + to_string(votecounts[j]) + " votes.\n");
                    j = candidateTotal;

                //    cout << "Winner " << (i+1) << ": " << candidateNames[j] << " with " << votecounts[j] << " votes." << std::endl;
                }
            }

        }
        delete[] tempvotecounts;
    }

    return votes;
}






//Shuffles the ballots so that randomness and fairness can occur
// Returns a set of ballots that are shuffled 
int** Election::shuffleelection() {
    random_device rd;
    mt19937 g(rd());
    int totalVotes = ballotBox->GetVoteTotal();
    // Shuffling our array
    Audit.append("Election is being shuffled.\n");
    shuffle(ballotBox->GetBallots(), (ballotBox->GetBallots() + totalVotes), g);

    return ballotBox->GetBallots();
}
