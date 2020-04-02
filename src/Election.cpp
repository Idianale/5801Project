#include "Election.h"

Election::Election(bool shufflestatus){
  shuffle_status = shufflestatus;

  ballotBox = new BallotBox();
  candidates = new Candidates();
}

void Election::runElection(string* filenames, int fileSize, int electionType, int seatNum){
  setCandidates(candidates,filenames);
  setBallotBox(ballotBox,filenames,fileSize);
  voteTotal = ballotBox->GetVoteTotal();
  int **votes = render(ballotBox,shuffle_status);
  int **retVotes;
  droopCount = voteTotal/(seatNum+1) + 1 ;
  if(electionType==1)
  {
    retVotes = BasicProtocol(candidates,ballotBox,votes,droopCount);
  }

}

int** BasicProtocol(Candidates* candidates_, Ballotbox* ballotBox_,int** votes, int droop){

  int** ballots = votes;
  BallotBox* ballotBox = ballotBox_;
  Candidates* candidates = candidates_;
  int candidateTotal = candidates->GetTotalCandidates();
  while(candidates->GetTotalStillIn()!=0)//at least 1 candidate is not a winner, or loser
  {
    for(int bnum = 0; bnum < ballotBox->GetTotalVotes(); bnum++) //bnum is the ballot currently being considered
    {
      if(ballots[bnum][0]==0)  // vote decision is undecided
      {
        for(int c = 1 ; c <= candidateTotal ; c++)
        {
          if(ballots[bnum][c]==1)
          {
            ballots[bnum][0]=c; // vote decision set to number 1 candidate
            candidates->VoteFor(c);
            if(candidates->AtDroop(c))
            {
              WinnerProtocol(bnum, &ballots, ballotBox, candidates);
            }
          }
        }
      }//iteration over single ballot completed
    }//iteration over every ballot completed
    if(candidates->GetTotalStilIn()>0)
      LoserProtocol(&ballots,ballotBox,candidates);
  }
  return ballots;//presumably this would be for auditing

}

void Election::WinnerProtocol(int bnum, int** ballots, BallotBox* ballotBox, Candidates* candidates)
{
  int newWinner=0;
  int candidateTotal = candidates->GetTotalCandidates();
  ballots[bnum][0]=0;//should already be zero, this is just in case
  while(ballots[bnum][newWinner]!=1)
    newWinner++;
  ballots[bnum][0]=newWinner;//set current ballot to have a winner
  candidates.SetNewWinner(newWinner);
  int* finishedCandidates = candidates->GetWinnerLoserVals();
  int finTot = candidates->getWinnerCount() + candidates->LosersCount();
  bnum++; //proceed to next ballot in list
  for(;bnum<ballotBox.GetTotalVotes();bnum++)
  {
    if(ballots[bnum][newWinner]==1)
    {
      for(int i = 0 ; i < finTot ; i++) //iterate over every value in the finalist array
      {
        for(int j = 1; j<=candidateTotal;j++) //iterate over every ranking value in the ballot at hand
        {
          if(ballots[bnum][j] == 1 && finishedCandidates[i]==j)//if the ballot's first choice is someone who has already won or lost the election
          {
            ballot[bnum][0]=0; //set current ballot status to undecided
            for(int k = 1 ; k <= candidateTotal; k++)//decrement every part of the array
              ballots[bnum][k]--;
            i = 0; //re-iterate over every finished candidate in case the ballot's second choice was also in the list
          }
        }
      }
    }
  }
}

void LoserProtocol(int**ballots,BallotBox* ballotBox, Candidates* candidates)
{
  int newLoser = candidates.GetLowestVoteCount();
  candidates.SetNewLoser(newLoser);
  int* finishedCandidates = candidates.GetWinnerLoserVals();
  int finTot = candidates.GetWinnerLoserTotal();

  for(int bnum = 0 ; bnum < ballotBox.GetTotalVotes(); bnum++) //iterate over every vote
  {
    if(ballots[bnum][0]==newLoser)
    {
      ballots[bnum][0]=0;//set vote value to undecided
      for(int i = 0; i < finTot ; i++)
      {
        for(int j = 1 ; j <= candidates.GetTotalCandidates(); j++)
        {
          if(ballots[bnum][j]==1 && finishedCandidates[i]==j)
          {
            i = 0; // re-iterate over every finalist candidate
            for(int k = 1; k <= candidates.GetTotalCandidates();k++)
              ballots[bnum][k]--;
          }
        }
      }
    }
  }
}
