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
    BallotBox(int electionType_);
    vector<vector<int>> AddVotes(string[] filenames, int fileTotal);
    // int AddVotes(vector<string> filenames);
    vector<vector<int>>* getBallots();
  private:
    int AddVotesHelper(string filename, vector<vector<int>>& votes);
    vector<vector<int>>* votes;  
    int colTotal;   // defined when AddVotes is initially called?
    int electionType; 
    // TODO: standardize electiontype convention. 
    //       ballotbox will be initially programmed to:
    //       0 = plurality, 1 = STV
    int voteTotal;
    vector<string> filenames_;
    string filename;
    ifstream fin;
};



#endif //SRC_BALLOTBOX_H