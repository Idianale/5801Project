//
// Created by m0narch on 3/27/20.
//

#ifndef REPO_TEAM16_CANDIDATE_H
#define REPO_TEAM16_CANDIDATE_H
#include <string>

class Candidate {
private:
    std::string name;
    int voteCount;
public:
    Candidate(std::string name);
    void incrementVote();
    void resetVotes();
    int getVoteCount();

    std::string getName();
    void setName(std::string newName);


};


#endif //REPO_TEAM16_CANDIDATE_H
