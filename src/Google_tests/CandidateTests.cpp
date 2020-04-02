//
// Created by m0narch on 4/2/20.
//

#include "gtest/gtest.h"
#include "Candidate.cpp"

//
// Created by m0narch on 4/2/20.
//
#include "gtest/gtest.h"
#include "CandidateTests.cpp

Test(Candidate, DefaultConstructor){
const Candidate("a") testCandidate;

EXPECT_EQ(voteCount, 0);
EXPECT_EQ(testCandidate.name, "a");
};

Test(Candidate, IncrementVote){
const Candidate("a") testCandidate;
testCandidate.incrementVote();

EXPECT_EQ(testCandidate.voteCount, 1);
}

Test(Candidate, ResetVote){
const Candidate("a") testCandidate;
testCandidate.incrementVote();

EXPECT_EQ(testCandidate.voteCount, 1);

testCandidate.resetVote();
EXPECT_EQ(testCandidate.voteCount, 0);
}

Test(Candidate, GetVoteCount){
const Candidate("a") testCandidate;
EXPECT_EQ(testCandidate.getVoteCount, 0);
}

Test(Candidate, GetName){
const Candidate("a") testCandidate;

EXPECT_EQ(testCandidate.getname, "a");
}

Test(Candidate, SetName){
const Candidate("a") testCandidate;
testCandidate.setName("b");
EXPECT_EQ(testCandidate.name, "b");
}

TestCandidate(Candidate, Equality){
const Candidate("a") test1Candidate;
const Candidate("b") test2Candidate;
bool eqTest = test1Candidate == test2Candidate;

EXPECT_EQ(eqTest, false);
}