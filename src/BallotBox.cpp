#include "BallotBox.h" 

using namespace std;

BallotBox::BallotBox(int electionType_)
{
  // votes = NULL;
  voteTotal = 0;
  electionType = electionType_;

}
//how to ensure this returns the correct value?

vector<vector<int>> BallotBox::AddVotes(string[] filenames, int fileTotal)
{
  bool error_check = false;
  // vector<vector<int>> votes;

  for(int i = 0 ; i < fileTotal ; i++){
    if(BallotBox::AddVotesHelper(filenames[i],&votes)){
      error_check = true;
    }
  }
  if(error_check)
    votes.clear();
  
  return votes;
}


// int BallotBox::AddVotes(string[] filenames, int fileTotal)
// {
//   bool error_check = false;
//   // vector<vector<int>> votes;

//   for(int i = 0 ; i < fileTotal ; i++){
//     if(BallotBox::AddVotesHelper(filenames[i],&votes)){
//       return 1;
//     }
//   }
  
//   return 0;
// }


// vector<vector<int>> BallotBox::GetVotes(){
//   return votes;
// }



int BallotBox::AddVotesHelper(string filename, vector<vector<int>>& votes){ //does this work?
  fstream fin;
  fin.open(filename);
  if(!fin.is_open())  {
    return 1; //given name is not pointing to an openable file
  }
  vector<int> row;
  string line, word, temp;
  // vector<vector<int>> votes;
  getline(fin, line); // skip candidate names

  while(fin >> temp)
  {
    row.clear();
    getline(fin, line);
    stringstream s_row(line);
    // row.push_back(0);//initial column for election related activites (maybe do in election directly)
    while(getline(s,word,',')){
      stringstream s_entry(word);
      int x = 0;
      if(s_entry.rdbuf()->in_avail()) //to account for plurality files
        s_entry >> x;
      row.push_back(x);
    }
    votes->push_back(row); //. to ->?
                           //might push_front run quicker? Might not matter

  }
  return 0;
}









//broken prior attempts

// int BallotBox::AddVotes(std::string filename)
// {
//   using namespace std;
//   std::ifstream fin(filename);
//   if(!fin.is_open())  {
//     return 1; //given name is not pointing to an openable file
//   }

//   std::string candidateRow;

//   fin.getline(candidateRow);

//   std::stringstream row_stream(candidateRow);
//   char delim = ',';
//   std::string tmp;

//   int colTemp = 0;
//   vector<string> names;
//   while(std::getline(candidateRow,tmp,delim)){
//     colTemp++;
//   }
//   colTotal = colTemp;
// //top row is now read;


//   fin.close();
// }




// int BallotBox::AddVotes(std::string filename){
//   std::ifstream fin(filename);
//   if(!fin.is_open())  {
//     return 1; //given name is not pointing to an openable file
//   }
  
//   int voteTotal + = std::count(std::istreambuf_iterator<char>(fin), 
//                                std::istreambuf_iterator<char>(), '\n');
//   int rowTotal = 1 + std::count(std::istreambuf_iterator<char>(fin), 
//                                 std::istreambuf_iterator<char>(), '\n');       
//   colTotal                                                    

//   std::string candidateRow;

//   fin.getline(candidateRow);

//   std::stringstream row_stream(candidateRow);
//   char delim = ',';
//   std::string tmp;

//   int colTemp = 0;
//   vector<string> names;
//   while(std::getline(candidateRow,tmp,delim)){
//     colTemp++;
//   }
//   colTotal = colTemp;



// }