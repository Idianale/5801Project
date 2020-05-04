#include <random>
#include <iostream>
using namespace std;

int** shuffleelection(int** ballotbox, int totalvotes) {
    random_device rd;
    mt19937 g(rd());
    // Shuffling our array
    shuffle(ballotbox, ballotbox + totalvotes, g);

    return ballotbox;
}


int main(){
  
    //Initalize 2D array
        int** newarr;
        int rows = 100;
        int columns = 15;


    int** a = new int* [rows];
    for (int i = 0; i < rows; ++i)
            a[i] = new int[columns];



    for(int i = 0; i < rows;i++){
        for (int j = 0; j < columns; j++) {
            //Array value is the row
            a[i][j] = i;



        }
    
    }

    //Output inital array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            //Array value is the row
            cout << a[i][j] << " ";



        }
        cout << endl;
    }
    cout << endl << endl;
    newarr = shuffleelection(a,rows);

    //Output shuffled array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            //Array value is the row
            cout << newarr[i][j] << " ";



        }
        cout << endl;
    }


}