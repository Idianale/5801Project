//
// Created by m0narch on 4/2/20.
//
#include "gtest/gtest.h"
#include "CandidatesTests.cpp

Test(Candidates, DefaultConstructor){
const Candidates() testCandidates;

EXPECT_EQ(testCandidates.winners.isEmpty(), true);
EXPECT_EQ(testCandidates.undecided.isEmpty(), true);
EXPECT_EQ(testCandidates.losers.isEmpty(), true);
EXPECT_EQ(testCandidates.candidateList.isEmpty(), true);
};

Test(Candidates, GetWinnerCount){
    const Candidates() testCandidates;

    EXPECT_EQ(testCandidates.winners.size(), 0);
}

Test(Candidates, GetWinners){
    Candidates() testCandidates;
    EXPECT_EQ(testCandidates.getWinners(), {});
}

Test(Candidates, GetLoserCount){
    Candidates() testCandidates;
    EXPECT_EQ(testCandidates.getLoserCount(),0);
}

Test(Candidates, GetLosers){
    Candidates() testCandidates;
    EXPECT_EQ(testCandidates.losers.size(), 0);
}

Test(Candidates, getAllCount){
    Candidates() testCandidates;
    EXPECT_EQ(testCandidates.getAllCount(), 0);
}

Test(Candidates, getTotalStillIn){
    Candidates() testCandidates;
    EXPECT_EQ(testCandidates.getTotalStillIn, 0);
}

Test(Candidates, AddCandidates){
    Candidates() testCandidates;
    testCandidates.addCandidate("A");
    EXPECT_EQ(testCandidates.undecided.size(), 1);
}

Test(Candidates, SetCandidates){
    Candidates() testCandidates;
    testCandidates.addCandidate("A");
    testCandidates.setCandidates("A", testCandidates.undecided, testCandidates.winners);
    EXPECT_EQ(testCandidates.undecided.size(), 0);
    EXPECT_EQ(testCandidates.winners.size(), 1);
}
