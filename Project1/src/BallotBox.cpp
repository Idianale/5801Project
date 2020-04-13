#include "BallotBox.h"

BallotBox::BallotBox(){
  electionType = 1;
  voteTotal = 0;
  colTotal = 0;
  ballots = NULL;

}
BallotBox::BallotBox(int electionType_){
  electionType = electionType_;
  voteTotal = 0;
  colTotal = 0;
  ballots = NULL;

}

// BallotBox::BallotBox(string* filenames,int fileTotal, int electionType_){
//   electionType = electionType_;
//   voteTotal = 0;
//   colTotal = 0;
//   ballots = NULL;
//   int**x = AddVotes(filenames, fileTotal);
// }


int BallotBox::GetVoteTotal(){return voteTotal;}
int BallotBox::GetTotalColumns(){return colTotal;}
int** BallotBox::GetBallots(){return ballots;}

int** BallotBox::AddVotes(string* filenames, int fileTotal){
  using namespace std;
  //Step 1: go through every file line by line to determine number of votes (row count for 2d votes array)
  int totalVotes = 0;
  for(int i = 0 ; i < fileTotal ; i++){
    fstream fin(filenames[i]);
    int temp =
    count(std::istreambuf_iterator<char>(fin),
          std::istreambuf_iterator<char>(),'\n');
    totalVotes += (temp - 1);
    fin.close();
  }
  // std::cout << "Total votes is " << totalVotes << endl; // debug
  voteTotal += totalVotes;

  // Step 2: Determine candidate count for column of 2d votes array
  int totalCols=0;
  fstream fin2(filenames[0]);
  std::string line;
  std::getline(fin2, line);
  std::stringstream s_row2(line);
  std::string entry;
  while(getline(s_row2,entry,','))
    totalCols++;
  // cout << "Total Columns is " << totalCols << "\n"; // debug
  colTotal = totalCols;
  fin2.close();

  // Step 3: create a 2d array containing vote values
  int** voteTable = new int*[totalVotes];
  int it = 0; //global iterator, persistent between files
  // iterate over all files:
  for(int i = 0 ; i < fileTotal ; i++){
    fstream fin(filenames[i]);
    std::string temp;
    getline(fin,line); //skip initial line containing candidate names
    // cout << line <<endl; // debug
                              // check this does not affect results
    while(getline(fin,line)&&it<totalVotes){
      // cout << line << endl; // debug

      // skip the empty line found at the end of every csv file
      if(line.empty()){
        // place row of csv file in string stream
        stringstream s_row(line);
        // create new row of ints
        int* x = new int[totalCols];
        string word;
        int j = 0;
        while(getline(s_row,word,',')&&j<totalCols){
          // cout << word << endl; // debug
          stringstream s_entry(word);
          int entry = 0;
          if(s_entry.rdbuf()->in_avail()) //TEST This (make sure plurality is coming up all zeroes)
            s_entry >> entry;
          x[j]=entry;
          j++;
        }
        voteTable[it] = x;
        it++;
      }
    }
    fin.close();
  }
  ballots = voteTable;
  return voteTable;
}
