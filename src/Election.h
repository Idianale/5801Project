#ifndef SRC_ELECTION_H
#define SRC_ELECTION_H

#include "BallotBox.h"
#include "Candidates.h"

class Election {

  public:
//   virtual void runElection() = 0;
    Election(bool shufflestatus_);
    void runElection(string* filenames, int fileSize, int electionType, int seatNum);
    int GetVoteTotal() {return voteTotal;}

  private: 
    int droopCount;
    bool shuffle;
    std::string testType;
    BallotBox * ballotBox;
    Candidates * candidates;
    void setCandidates(BallotBox* box);
    int electionType_; // 1 = STV, 2 = Plurality
    int** results;
    bool shuffle_status;
    int voteTotal;
    int candidateTotal;

    int** STVProtocol(int** votes);
    int** PluralityProtocol(int** votes);

    void setCandidates(Candidates* candidates_, string* filenames);
    void setBallotBox(BallotBox* ballotBox_, string* filenames, int fileTotal);
    int** shuffle(BallotBox* ballotbox, int totalVotes, int totalCand);
    int** BasicProtocol(Candidates* candidates_, BallotBox* ballotBox_,int** votes);
    void WinnerProtocol(int bnum, int** ballots, BallotBox* ballotBox, Candidates* candidates);
    void LoserProtocol(int**ballots,BallotBox* ballotBox, Candidates* candidates);
  



};


#endif // SRC_ELECTION_H
