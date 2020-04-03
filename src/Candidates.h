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

    /***
     * Default constructor for Candidates
     * no parameters and creates an empty list of candidates
     */
    Candidates();

    /***
     * Candidates Constructor for candidates
     * @param candidates list of canidate object
     *
     */

    Candidates(std::vector<Candidate> candidates);

    /***
     *  getWinnerCount()
     *
     *
     * @returns int representing how many votes the winner recieved
     */

    int getWinnerCount();

    /***
     * getWinners()
     *
     * @return std::vector<candidate> getWinners
     */
    std::vector<Candidate> getWinners();

    /***
    *  getLosersCount()
    *
    *
    * @returns int representing how many votes the Losers recieved
    */

    int getLosersCount();

    /***
    * getLosers()
    *
    * @return std::vector<candidate> getLosers
    */
    std::vector<Candidate> getLosers();


    /***
    * getAllCount
    *
    * @return int of all votes
    */
    int getAllCount();


    /***
    * getAllCount
    *
    * @return int of candidates in undecided
    */
    int getTotalStillIn();


    /***
    * getName
    *
    * @return getName of candidate
    */
    std::string getName(int id);

    /***
     * addCandidate
     * Add candidate object to undecided list
     */
    //Add candidate to undecided
    void addCandidate(std::string);

    /***
     * setCandidate
     * @param candidateName
     * @param moveFromList
     * @param moveToList
     *
     * move candidate from undecided list to another list
     */
    // Change list that candidate is in
    void setCandidate(std::string candidateName, std::vector<Candidate> moveFromList, std::vector<Candidate>moveToList);

    /***
     *     Find candidate with lowest votes.
     *     Returns index of candidate with lowest votes
     */
    int findLowestVote();
};


#endif //SRC_CANDIDATES_H
