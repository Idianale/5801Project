//
// Created by m0narch on 3/27/20.
//

#ifndef REPO_TEAM16_CANDIDATE_H
#define REPO_TEAM16_CANDIDATE_H
#include <string>

/***
 * Candidate Class
 */

class Candidate {
private:
    std::string name;
    int voteCount;
public:
    /***
     * Candidate
     * basic candidate constructor
     * @param name
     */
    Candidate(std::string name);

    /***
     * incrementVote
     *
     * Increase candidate vote count by one
     */
    void incrementVote();

    /***
     * resetVotes
     *
     * Set candidate vount count to 0
     */
    void resetVotes();

    /***
     * getVoteCount
     * @return int of candidate votes
     */
    int getVoteCount();

    /***
     * getname
     * @return std::string of candidate name
     */
    std::string getName();

    /***
     * setName
     * change the name of the candidate
     * @param newName
     */
    void setName(std::string newName);

    /***
     *  == operator
     * @param c1
     * @param c2
     * compare candidate objects by name.
     * @return
     */
    friend bool operator== (Candidate c1, Candidate c2);

};


#endif //REPO_TEAM16_CANDIDATE_H
