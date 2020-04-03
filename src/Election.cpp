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

  //create BallotBox values
  BallotBox* myBallotBox = new BallotBox(electionType);
  int** votes = myBallotBox->AddVotes(filenames, fileSize);
  ballotBox = myBallotBox;

  //create Candidate values
  Candidates* myCandidates = new Candidates();
  fstream fin(filenames[0]);
  std::string line;
  std::string temp;
  getline(fin,line);
  stringstream s_row(line);
  string word;
  while(getline(s_row,word,',')){
    myCandidates->addCandidate(word);
  }
  candidates = myCandidates;

  int totalVotes = ballotBox->GetVoteTotal();
  int totalCand  = ballotBox->GetTotalColumns();
  electionType_ = electionType;

  if(shuffle_status)
    votes = shuffle(ballotBox,totalVotes, totalCand);
  // STV Election Type
  if(electionType_==1){

  }

  // Plurality Election Type
  else if(electionType_==2){

  }
}

int** Election::shuffle(BallotBox* ballotbox, int totalVotes, int totalCand){
  return ballotbox->GetBallots(); //TO DO
}