//
// Created by m0narch on 3/27/20.
//

#include "Candidates.h"
Candidates::Candidates()
    : candidateList{}, winners{}, losers{}, undecided{}
{

}

Candidates::Candidates(std::vector<Candidate> allCandidates)
    : candidateList{allCandidates}
{

}

int Candidates::getWinnerCount() {
    return static_cast<int>(winners.size());
}

std::vector<Candidate> Candidates::getWinners() {
    return winners;
}


int Candidates::getLosersCount() {
    return static_cast<int>(losers.size());
}

std::vector<Candidate> Candidates::getLosers() {
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
// Create a new candidate and add them to the undecided list
void Candidates::addCandidate(std::string candidateName){
    Candidate newCandidate{candidateName};
    undecided.push_back(newCandidate);
}

void Candidates::setCandidate(std::string candidateName, std::vector<Candidate> moveFromList, std::vector<Candidate>moveToList) {
    // Find candidate in moveFromList
    // move it to moveToList
    // remove candidate fromList
    for(Candidate fromElement : moveFromList){
        if(fromElement.getName() == candidateName){
            moveToList.push_back(fromElement);
            moveFromList.erase(std::remove(moveFromList.begin(),  moveFromList.end(), fromElement), moveFromList.end());
        }
    }

}

