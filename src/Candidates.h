//
// Created by m0narch on 3/27/20.
//

#ifndef SRC_CANDIDATES_H
#define SRC_CANDIDATES_H
#include <string>
#include <vector>
#include "Candidate.h"

class Candidates {
private:
    std::vector<int> winners;
    std::vector<int> losers;
    std::vector<int> undecided;
    std::vector<Candidate> candidateList;
public:
    Candidates(std::vector<Candidate> candidates);

    int getWinnerCount();
    std::vector<int> getWinners();

    int getLosersCount();
    std::vector<int> getLosers();

    int getAllCount();
    int getTotalStillIn();

    std::string getName(int id);

    int setCandidate(std::string);

    int RemoveCandidate(int)
};


#endif //SRC_CANDIDATES_H
