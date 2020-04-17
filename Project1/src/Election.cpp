#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Election.h"

/*
    To do: 
    implement Shuffle()
    implement coin toss
    implement plurality election
    test elections

*/


Election::Election(bool shufflestatus_){
  shuffle_status = shufflestatus_;
}

void Election::runElection(string* filenames, int fileSize, 
                             int electionType, int seatNum){
  
  using namespace std;

  // create BallotBox values
  BallotBox* myBallotBox = new BallotBox(electionType);
  votes = myBallotBox->AddVotes(filenames, fileSize);
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
  int j=0;
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

  // Set Droop Quota
  droopCount = (voteTotal/(seatNum+1)) + 1;

  if(shuffle_status)
    votes = shuffle(ballotBox,totalVotes, totalCand);
  
  int **results;
  // STV Election Type
  if(electionType_==1){
    results = STVProtocol(candidateNames);

  }

  // Plurality Election Type
  else if(electionType_==2){
    results = PluralityProtocol(candidateNames);
  }
}


int** Election::STVProtocol(string* candidateNames){
  voteVals = new int[voteTotal];
  for(int i = 0 ; i < voteTotal ; i++){
    voteVals[i] = -1; //Associated vote not set for any given candidate
  }
  while(candidates->getTotalStillIn()!=0){
    for(int bnum = 0 ; bnum < voteTotal ; bnum ++){
      if( voteVals[bnum]==-1){
        int newVoteVal = setVoteVals(votes[bnum]);
        voteVals[bnum] = newVoteVal;
        candidates->candidateList[newVoteVal].incrementVote;
        int voteCount = candidates->candidateList[newVoteVal].getVoteCount();
        if(voteCount==droopCount)
        {
          STVWinnerProtocol(newVoteVal, candidateNames, bnum);
        }
      }
    }
    if(candidates->getTotalStillIn()>0)
      STVLoserProtocol(candidateNames);
  }
}

/*
  STVWinnerProtocol: this function
    1. adds the winning candidate to the list of winner candidates
    2. Changes remaining votes in array so that they no longer have that 
       candidate, or any previous candidate finalists, as their first choice.

*/
void Election::STVWinnerProtocol(int newWinner, string* candidateNames, int ivote){
  candidates->setCandidate(candidateNames[newWinner],candidates->undecided,candidates->winners);
  finalists.push_back(newWinner);
  ivote++;
  for(;ivote<voteTotal;ivote++){
    bool voteAltered = false;
    for(auto i = finalists.begin(); i != finalists.end() ; i++){
      if(votes[ivote][*i]==1){
        adjustVote(votes[ivote]);
        voteVals[ivote] = -1;
        voteAltered = true;
      }
    }
    if(voteAltered) // reiterate over prior vote rankings from start
      ivote--;
  }
}

void Election::STVLoserProtocol(string* candidateNames){
  int lowestvote = candidates->undecided[0].getVoteCount();
  int newLoser = findNewLoser(candidateNames, candidates->undecided[0].getName());
  for(auto i = candidates->undecided.begin(); i < candidates->undecided.end()){
    Candidate c = *i;
    int newVoteCount = c.getVoteCount;
    if(newVoteCount < lowestvote){
      lowestvote = newVoteCount;
      newLoser = findNewLoser(candidateNames, c.getName());
    }
    else if(newVoteCount==lowestvote){
      newLoser = coinToss(newLoser, findNewLoser(candidateNames, c.getName()));
    }
  }
  candidates->setCandidate(candidateNames[newLoser],candidates->undecided,candidates->losers);
  finalists.push_back(newLoser);
  for(int bnum = 0 ; bnum < voteTotal ; bnum++){
    bool adjustedVote = false;
    for(auto i = finalists.begin(); i < finalists.end(); i++){
      if(votes[bnum][*i]==1){
        adjustVote(votes[bnum]);
        voteVals[bnum] = -1;
        adjustedVote = true;
      }
      if(adjustedVote)
        bnum--;
    }
  }
}

int Election::coinToss(int loserA, int loserB){
  //TO DO 
  return loserA;
}

int Election::findNewLoser(string* candidateNames, string newName){
  int j = 0;
  for(auto i = candidates->candidateList.begin(); i < candidates->candidateList.end(); i++){
    Candidate c = *i;
    if(c.getName==newName)
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
void Election::adjustVote(int* thisVote){
  for(int i = 0 ; i < candidateTotal ; i++){
    thisVote[i]--;
  }

}

int Election::setVoteVals(int* ballot){
  for(int i = 0 ; i < candidateTotal ; i++){
    if(ballot[i]==1)
      return i;
  }
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

int** Election::PluralityProtocol(string* candidateNames){
  int votecounts[candidateTotal];
  for(int i = 0 ; i < candidateTotal ; i++)
    {votecounts[i] = 0;}
  for(int i = 0 ;  i < voteTotal ; i++){
    for(int j = 0 ; j < candidateTotal; j++){
      if(votes[i][j]!=0){
        votecounts[i]+=1;
        candidates->candidateList[j].incrementVote();
      }
    }
  }
  int winner=0;
  for(int i = 1 ; i < candidateTotal+1 ; i++){
    if(votecounts[i]>votecounts[winner])
      winner = i;
    else if(votecounts[i]==votecounts[winner])
      winner = coinToss(votecounts[i], votecounts[winner]);
  }
  std::cout << "the winner is " << candidateNames[winner] << std::endl;
  
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

int** Election::shuffle(){
    random_device rd;
    mt19937 g(rd());
    int totalVotes = ballotBox->GetVoteTotal();
    
    // Shuffling our array
    shuffle(ballotBox->GetBallots(),ballotBox->GetBallots() + totalvotes,
        g);
    
    return ballotBox->GetBallots(); //Need to test with 
}
