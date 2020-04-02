#include "BallotBox.h" 

BallotBox::BallotBox(int electionType)
{
  votes = NULL;
  voteTotal = 0;
  electionType_ = electionType;

}

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




int BallotBox::AddVotes(std::string filename){
  std::ifstream fin(filename);
  if(!fin.is_open())  {
    return 1; //given name is not pointing to an openable file
  }
  
  int voteTotal + = std::count(std::istreambuf_iterator<char>(fin), 
                               std::istreambuf_iterator<char>(), '\n');
  int rowTotal = 1 + std::count(std::istreambuf_iterator<char>(fin), 
                                std::istreambuf_iterator<char>(), '\n');       
  colTotal                                                    

  std::string candidateRow;

  fin.getline(candidateRow);

  std::stringstream row_stream(candidateRow);
  char delim = ',';
  std::string tmp;

  int colTemp = 0;
  vector<string> names;
  while(std::getline(candidateRow,tmp,delim)){
    colTemp++;
  }
  colTotal = colTemp;



}