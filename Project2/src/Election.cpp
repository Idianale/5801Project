#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
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
    cout << "in election constructor" << endl;
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
    
}

void Election::runElection(string* filenames, int fileSize,
    int electionType, int seatNum) {

    using namespace std;
    // create BallotBox values
    BallotBox* myBallotBox = new BallotBox(electionType);
    votes = myBallotBox->AddVotes(filenames, fileSize);
    if (votes == NULL)
    {
        cout << "Test does not have at least 50% valid ballots";
        return;
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
    electionType_ = electionType;
    // Set Droop Quota
    droopCount = (voteTotal / (seatNum + 1)) + 1;
    cout << "The Droop Quota is: " << droopCount << "\n";
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
        results = STVProtocol(candidateNames);
    }
    // Plurality Election Type
    else if (electionType_ == 2) {
        cout << "Plurality selected" << endl;
        results = PluralityProtocol(candidateNames);
    }
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
        cout << "there are " << getTotalUndecided() << " Candidates still in" << endl;
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
                    cout << "we have a new winner" << endl;
                    // STVWinnerProtocol(newVoteVal, candidateNames, bnum);
                    STVWinnerProtocolB(newVoteVal, candidateNames, bnum);
                }
            }
        }
        if (getTotalUndecided() != 0 && loopCatcher < 4) {
            cout << "we have a new loser" << endl;
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
    cout << "Election Complete" << endl;
    cout << "Candidate Ranking:" << endl;
    int win = 1;
    for (int i = 0; i < seatNum_; i++) {
        cout << "Winner: ";
        for (int i = 0; i < candidateTotal; i++) {
            if (candArr[i] == win) {
                cout << candidateNames[i] << " with " << candVal[i] << " votes" << endl;
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
    cout << "Latest Loser is " << candidateNames[newLoss] << " with " << candVal[newLoss] << " votes" << endl;
    for (int i = 0; i < candidateTotal; i++) {
        if (candArr[i] < 0) {
            candArr[i]--;
        }
    }
    candArr[newLoss] = -1;
    cout << "there Are now " << getTotalUndecided() << " candidates remaining" << endl;

    finalists.push_back(newLoss);
    if (getTotalUndecided()) {
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



/*

void Election::STVLoserProtocol(string* candidateNames) {
    int lowestvote = candidates->undecided[0].getVoteCount();
    int newLoser = findNewLoser(candidateNames, candidates->undecided[0].getName());
    for (auto i = candidates->undecided.begin(); i < candidates->undecided.end(); i++) {
        Candidate c = *i;
        int newVoteCount = c.getVoteCount();
        if (newVoteCount < lowestvote) {
            lowestvote = newVoteCount;
            newLoser = findNewLoser(candidateNames, c.getName());
        }
        else if (newVoteCount == lowestvote) {
            newLoser = coinToss(newLoser, findNewLoser(candidateNames, c.getName()));
        }
    }
    candidates->setCandidate(candidateNames[newLoser], candidates->undecided, candidates->losers);
    finalists.push_back(newLoser);
    for (int bnum = 0; bnum < voteTotal; bnum++) {
        bool adjustedVote = false;
        for (auto i = finalists.begin(); i < finalists.end(); i++) {
            if (votes[bnum][*i] == 1) {
                adjustVote(votes[bnum]);
                voteVals[bnum] = -1;
                adjustedVote = true;
            }
            if (adjustedVote)
                bnum--;
        }
    }
}
*/

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

    cout << "Vote Total: " << voteTotal << endl;
    for (int i = 0; i < voteTotal; i++) {
        for (int j = 0; j < candidateTotal; j++) {
            cout << votes[i][j] << "  " << i << "  " << j << endl;
            if (votes[i][j] == 1) {
                votecounts[j] = votecounts[j] + 1;
                //    candidates->candidateList[j].incrementVote(); ignore candidate class
            }
        }
    }
    int winner = 0;
    cout << votecounts[0] << endl;
    cout << votecounts[1] << endl;
    cout << votecounts[2] << endl;
    cout << votecounts[3] << endl;
    if (seatNum_ == 1) {
    for (int i = 1; i < candidateTotal; i++) {
        if (votecounts[i] > votecounts[winner])
            winner = i;
        else if (votecounts[i] == votecounts[winner])
            winner = coinToss(i, winner);
    }
    std::cout << "the winner is " << candidateNames[winner] << std::endl;
    }
    else
    {
        //Multiple Seats

    }

    return votes;
}





//Test Functions


// int Election::findLowestVoteB(){
//   int lowest = 0;
//   int votTot = candidateBypassVoteCounts[0];
//   for(int i = 0 ; i < candidateTotal ; i++){
//     if(candidateVoteCounts[i]<=votTot){
//       lowest = i;
//       votTot = candidateVoteCounts[i];
//     }
//   }
//   return lowest;

// }
void Election::newestLoserB(int loser) {
    ;
    for (int i = 0; i < candidateTotal; i++) {
        if (candidateBypassLoser[i] > 0)
            candidateBypassLoser[i]++;
    }
    candidateBypassLoser[loser] = 1;
    candidateBypassUndecided[loser] = 0;

}


int** Election::shuffleelection() {
    random_device rd;
    mt19937 g(rd());
    int totalVotes = ballotBox->GetVoteTotal();

    // Shuffling our array
    shuffle(ballotBox->GetBallots(), (ballotBox->GetBallots() + totalVotes), g);

    return ballotBox->GetBallots(); //Need to test with 
}

int main() {

    //Used for coin toss
    srand(static_cast<int>(time(0)));
    cout << "\nin main\n";
    Election myElection(0);
    string myString[1];
    //C:\Users\Adam\Downloads\example_election_file.csv
    cin >> myString[0];
    cout << "about to run election" << endl;
    myElection.runElection(myString, 1, 1, 1);
}




/*
  important function values:
    votes: 2D array containing votes,in the form
           votes[specificBallot][specificCandidateRanking]
           So votes[0] might be [0,1,0,0] or [1,2,3,4]
    candidateTotal: total number of candidates
    candidates: pointer to relevant Candidates class
    voteTotal: int, number of votes, number of rows in votes array
*/
