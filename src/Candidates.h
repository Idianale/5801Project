//
// Created by m0narch on 3/27/20.
//

#ifndef SRC_CANDIDATES_H
#define SRC_CANDIDATES_H
#include <string>
#include <vector>
#include <algorithm>
#include "Candidate.h"

/*
 * Candidates Class
 * Holds information about candidates in the election and lists of who is a winner
 * Loser, or undecided status
 */

class Candidates {
private:
public:
    std::vector<Candidate> winners; //
    std::vector<Candidate> losers;
    std::vector<Candidate> undecided;
    std::vector<Candidate> candidateList;
    enum Status_Type{
        Undecided,
        Winner,
        Loser,
        MAX_Status_Type
    };
    Candidates();
    /***
     *
     * @param candidates
     */

    Candidates(std::vector<Candidate> candidates);

    /***
     * @b
     *
     * @return
     */


    int getWinnerCount();

    /***
     *
     * @return
     */
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
    int findLowestVote();
};


#endif //SRC_CANDIDATES_H
