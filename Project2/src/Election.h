#pragma once
#ifndef SRC_ELECTION_H
#define SRC_ELECTION_H

#include "BallotBox.h"
#include "Candidates.h"

class Election {

public:
    //   virtual void runElection() = 0;
    Election(bool shufflestatus_);
    void runElection(string* filenames, int fileSize, int electionType, int seatNum);
    int GetVoteTotal() { return voteTotal; }

private:
    int droopCount;
    std::string testType;
    BallotBox* ballotBox;
    Candidates* candidates;
    void setCandidates(BallotBox* box);
    int electionType_; // 1 = STV, 2 = Plurality
    int** results;
    bool shuffle_status;
    int voteTotal;
    int candidateTotal;
    int* voteVals;
    std::vector<int> finalists;
    int** votes;

    int** shuffleelection();
    int** STVProtocol(string* candidateNames);
    int** PluralityProtocol(string* candidateNames);
    int coinToss(int candidateA, int candidateB);
    void setCandidates(Candidates* candidates_, string* filenames);
    void setBallotBox(BallotBox* ballotBox_, string* filenames, int fileTotal);
    // int** shuffle(BallotBox* ballotbox, int totalVotes, int totalCand);
    int** BasicProtocol(Candidates* candidates_, BallotBox* ballotBox_, int** votes);
    //void WinnerProtocol(int bnum, int** ballots, BallotBox* ballotBox, Candidates* candidates);
    void STVWinnerProtocol(int newWinner, string* candidateNames, int ivote);
    void LoserProtocol(int** ballots, BallotBox* ballotBox, Candidates* candidates);
    void STVLoserProtocol(string* candidateNames);
    int setVoteVals(int* ballot);
    void adjustVote(int* thisVote);
    int findNewLoser(string* candidateNames, string newName);
    int seatNum_;

    //for testing purposes
    int* candidateBypassVoteCounts;
    int* candidateBypassUndecided;
    int* candidateBypassWinner;
    int* candidateBypassLoser;
    int* cbl;
    void STVLoserBypassProtocol(string* candidateNames);
    int getTotalUndecided();
    int findLowestVoteB();
    void incLoserB();
    void incWinnerB();
    void newLoserB(int loser);
    void newWinnerB(int winner);
    void newestLoserB(int loser);
    void STVWinnerProtocolB(int newWinner, string* candidateNames, int ivote);
    void STVLoserProtocolB(string* candidateNames);
    int* candArr;
    int* candVal;
    bool nonFinalist(int candVal);
};


#endif // SRC_ELECTION_H