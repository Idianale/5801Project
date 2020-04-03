#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Election.h"

/*
    To do: 
    implement Shuffle()

*/


Election::Election(bool shufflestatus_){
  shuffle_status = shufflestatus_;
}

void Election::runElection(string* filenames, int fileSize, 
                             int electionType, int seatNum){
  
  using namespace std;

  // create BallotBox values
  BallotBox* myBallotBox = new BallotBox(electionType);
  int** votes = myBallotBox->AddVotes(filenames, fileSize);
  ballotBox = myBallotBox;

  int tmp = myBallotBox->GetTotalColumns;
  string candidateNames[tmp];
  // create Candidate values
  Candidates* myCandidates = new Candidates();
  fstream fin(filenames[0]);
  std::string line;
  std::string temp;
  getline(fin,line);
  stringstream s_row(line);
  string word;
  int j=1;
  while(getline(s_row,word,',')&&j<tmp){
    myCandidates->addCandidate(word);
    candidateNames[j]=word;
    j++;
  }
  candidates = myCandidates;

  int totalVotes = ballotBox->GetVoteTotal();
  voteTotal = totalVotes;
  int totalCand  = candidates->getAllCount();
  candidateTotal = totalCand;
  electionType_ = electionType;

  if(shuffle_status)
    votes = shuffle(ballotBox,totalVotes, totalCand);
    int **results;
  // STV Election Type
  if(electionType_==1){
    results = STVProtocol(votes, candidateNames);

  }

  // Plurality Election Type
  else if(electionType_==2){
    results = PluralityProtocol(votes);
  }
}

int** Election::STVProtocol(int** votes, string* candidateNames){




  while(candidates->getTotalStillIn()!=0){

 candidates[c]->incrementVotes();

    for(int bnum = 0 ; bnum < voteTotal ; bnum ++){
      // if vote decision is undecided
      if(votes[bnum][0]==0){
        for(int c = 1 ; c <= candidateTotal ; c++){
          if(ballots[bnum][c]==1){
            ballots[bnum][0]=c;
             candidates[c]->incrementVotes();
            candidateNames[c]
            //TODO find a way to get this info into Candidates class
          }
        }
      } 


    }
  }
}






int** Election::PluralityProtocol(int** votes){
  //A little help?
}



int** Election::shuffle(BallotBox* ballotbox, int totalVotes, int totalCand){
  return ballotbox->GetBallots(); //TO DO
}