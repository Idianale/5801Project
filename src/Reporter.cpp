//Reporter Class

#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <errno.h>
using namespace std;


//responsible for creating audit file and reporting election results to screen
class Reporter {
private:
	vector<string> auditTextToWrite;
	FILE* auditFile;

public:
	
	//function used to create file to send audit data to
	void createAudit() {
		errno_t err = fopen_s(&auditFile, "auditFile","w" );
	}
	
	//function used to append data to string that will be printed to audit text file
	void appendToString(string data) {

		//appends data to string
		auditTextToWrite.push_back(data);

		//appends new line after each data block is written
		auditTextToWrite.push_back("\n");
	}

	//function used to write to audit text file
	void writeToFile(int type, int seats, int candidates, vector<string> winners, vector<string> losers) {


		//outputs election type
		string electionType;
		if (type == 1) {
			electionType = "STV";
		}
		else if (type == 2) {
			electionType = "Plurality";
		}
		string t = "Election Type: ";
		t.append(electionType);
		t.append("\n");
		fputs(t.c_str(), auditFile);

		//outputs number of seats
		string s = "Number of Seats: ";
		s.append(to_string(seats));
		s.append("\n");
		fputs(s.c_str(), auditFile);

		//outputs number of candidates
		string c = "Number of Candidates: ";
		c.append(to_string(candidates));
		c.append("\n");
		fputs(c.c_str(), auditFile);

		//outputs winners
		string w = "Winners: ";
		for (size_t i = 0; i < winners.size(); i++) {
			w.append(winners[i]);
			w.append(", ");
		}
		w.append("\n");
		fputs(w.c_str(), auditFile);

		//outputs losers
		string l = "Losers: ";
		for (size_t i = 0; i < losers.size(); i++) {
			l.append(losers[i]);
			l.append(", ");
		}
		l.append("\n");
		fputs(l.c_str(), auditFile);


		//outputs ballots assigned to a candidate
		for (size_t i = 0; i < auditTextToWrite.size(); i++) {
			string data = auditTextToWrite[i];
			fputs(data.c_str(), auditFile);
		}

	}

	//function used to write results of election to screen
	void writeToScreen(int type, int ballots, int seats, int candidates, vector<string> winners, vector<string> losers) {
		
		//outputs election type
		string electionType;
		if (type == 1) {
			electionType = "STV";
		}
		else if (type == 2) {
			electionType = "Plurality";
		}
		string t = "Election Type: ";
		t.append(electionType);
		t.append("\n");
		cout << t;

		//outputs number of ballots
		string b = "Number of Ballots: ";
		b.append(to_string(ballots));
		b.append("\n");
		cout << b;

		//outputs number of seats
		string s = "Number of Seats: ";
		s.append(to_string(seats));
		s.append("\n");
		cout << s;

		//outputs number of candidates
		string c = "Number of Candidates: ";
		c.append(to_string(candidates));
		c.append("\n");
		cout << c;

		//outputs winners
		string w = "Winners: ";
		for (size_t i = 0; i < winners.size(); i++) {
			w.append(winners[i]);
			w.append(", ");
		}
		w.append("\n");
		cout << w;

		//output losers
		string l = "Losers: ";
		for (size_t i = 0; i < losers.size(); i++) {
			l.append(losers[i]);
			l.append(", ");
		}
		l.append("\n");
		cout << l;

	}


};


