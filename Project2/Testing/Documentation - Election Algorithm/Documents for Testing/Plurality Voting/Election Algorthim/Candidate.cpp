//
// Created by m0narch on 3/27/20.
//  This class is currently not used in the algorthim as we were running into a lot of bugs. Currently still here because it is a much cleaner data structure to use and will be listed on the new PBI

#include "Candidate.h"

// Candidates Constructor
Candidate::Candidate(std::string candidateName)
        : name{ candidateName }, voteCount {}
{

}

// Increment vote member function
// Increase candidate vote count by one.
void Candidate::incrementVote() {
    voteCount++;
}

// Reset vote count member function
// Set candidate vote count to zero
void Candidate::resetVotes() {
    voteCount = 0;
}

int Candidate::getVoteCount() {
    return voteCount;
}

// getName member function
// receive the name of the candidate
std::string Candidate::getName(){
    return name;
}

void Candidate::setName(std::string newName) {
    name= newName;
}

bool operator== (Candidate c1, Candidate c2){
    return (c1.getName() == c2.getName());
}