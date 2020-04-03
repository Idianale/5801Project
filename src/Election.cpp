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

int candidateStatus[candidateTotal+1];
int votecounts[candidateTotal+1];
for(int i = 0 ; i < candidateTotal+1 ; i++)
  {votecounts[i] = 0;
  candidateStatus[i]=0;}


while(candidates->getTotalStillIn()!=0){
  for(int bnum = 0 ; bnum < voteTotal ; bnum ++){
    // if vote decision is undecided
    if(votes[bnum][0]==0){
      for(int c = 1 ; c <= candidateTotal ; c++){
        if(ballots[bnum][c]==1){
          ballots[bnum][0]=c;
            candidates->candidateList[c-1]->incrementVotes();
            votecounts[c]+=1;
            if(votecounts[c]>=droopCount)
            {
              STVWinnerProtocol(bnum, votes, candidateNames &votecounts, c);
            }
          //candidateNames[c]
          //TODO find a way to get this info into Candidates class
        }
      }
    } 


  }
}
  if(candidates->getTotalStillIn()!=0)
    LoserProtocol(votes, candidateNames, &votecounts);
}






int** Election::PluralityProtocol(int** votes,string* candidateNames){
  int votecounts[candidateTotal+1];
  for(int i = 0 ; i < candidateTotal+1 ; i++)
    {votecounts[i] = 0;}
  for(int i = 0 ;  i < voteTotal ; i++){
    for(int j = 1 ; j <= candidateTotal; j++){
      if(votes[i]!=0){
        votecounts[i]+=1;
        candidates->candidateList[j-1].incrementVote();
      }
    }
  }
  int winner=0;
  for(int i = 1 ; i < candidateTotal+1 ; i++){
    if(votecounts[i]>votecounts[i-1])
      winner = i;
  }
  std::cout << "the winner is " candidateNames[winner]<<std::endl;
  
}



int** Election::shuffle(BallotBox* ballotbox, int totalVotes, int totalCand){
  return ballotbox->GetBallots(); //TO DO
}