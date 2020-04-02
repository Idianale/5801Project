//
// Created by m0narch on 3/27/20.
//

#ifndef SRC_CANDIDATES_H
#define SRC_CANDIDATES_H
#include <string>
#include <vector>
#include <algorithm>
#include "Candidate.h"

class Candidates {
private:
    std::vector<Candidate> winners;
    std::vector<Candidate> losers;
    std::vector<Candidate> undecided;
    std::vector<Candidate> candidateList;
public:
    enum Status_Type{
        Undecided,
        Winner,
        Loser,
        MAX_Status_Type
    };
    Candidates();
    Candidates(std::vector<Candidate> candidates);

    int getWinnerCount();
    std::vector<Candidate> getWinners();

    int getLosersCount();
    std::vector<Candidate> getLosers();

    int getAllCount();
    int getTotalStillIn();

    std::string getName(int id);

    //Add candidate to undecided
    void addCandidate(std::string);

    // Change list that candidate is in
    void setCandidate(std::string candidateName, std::vector<Candidate> moveFromList, std::vector<Candidate>moveToList);

    //Find candidate with lowest votes.
    // Returns index of candidate with lowest votes
    int findLowestVote
};


#endif //SRC_CANDIDATES_H
