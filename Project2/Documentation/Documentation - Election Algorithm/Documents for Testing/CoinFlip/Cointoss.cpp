#include <iostream>
#include <random>


using namespace std;


int coinToss(int candidateA, int candidateB) {
    int flip;
    flip = (rand() % 2) + 1;// assign random numbers
    
    if (flip == 1) {
        return candidateA;
    }
    else {
        return candidateB;
    }


}

//If coin toss is correct, 50% time 0 will be
int main() {



    int CandA = 0;
    int CandB = 1;
    int totalA = 0;
    int totalB = 0;
    for(int i = 0; i < 100;i++){
        if (coinToss(CandA, CandB) == 0) {
            totalA = totalA + 1;
        }
        else {
            totalB = totalB + 1;
        }

    }
    cout << totalA << "   " << totalB;
    return 0;



}