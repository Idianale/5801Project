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
    EXPECT_EQ();
}

Test(Candidates, GetWinners){
    EXPECT_EQ();
}

Test(Candidates, GetLoserCount){
    EXPECT_EQ();
}

Test(Candidates, GetLosers){
    EXPECT_EQ();
}

Test(Candidates, getAllCount){
    EXPECT_EQ();
}

Test(Candidates, getTotalStillIn){
    EXPECT_EQ();
}

Test(Candidates, AddCandidates){
    EXPECT_EQ();
}

Test(Candidates, SetCandidates){
    EXPECT_EQ();
}

Test(Candidates, FindLowestVotes){
    EXPECT_EQ();
}