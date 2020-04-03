#ifndef SRC_BALLOTBOX_H
#define SRC_BALLOXBOX_H
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
//fstream or ifstream?
using namespace std;
class BallotBox {
  public:
    BallotBox();
    BallotBox(int electionType_);
    int GetVoteTotal();
    int GetTotalColumns();
    int** GetBallots();
    int** AddVotes(string* filenames, int fileTotal);

  private:
    int colTotal;  
    int electionType; 
        int voteTotal;
    int ** ballots;
};



#endif //SRC_BALLOTBOX_H