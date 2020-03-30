//
// Created by m0narch on 3/27/20.
//

#include "Candidates.h"

Candidates::Candidates(std::vector<Candidate> allCandidates)
    : candidateList{allCandidates}
{

}

int Candidates::getWinnerCount() {
    return static_cast<int>(winners.size());
}

std::vector<int> Candidates::getWinners() {
    return winners;
}


int Candidates::getLosersCount() {
    return static_cast<int>(losers.size());
}

std::vector<int> Candidates::getLosers() {
    return losers;
}

int Candidates::getAllCount(){
    return static_cast<int>(losers.size()+winners.size()+undecided.size());
}

int Candidates::getTotalStillIn() {
    return static_cast<int>(undecided.size());
}

std::string Candidates::getName(int id){
    return candidateList[id].getName();
}



