#include "gtest/gtest.h"
#include "TennisScoreBoard.h"

TEST(MatchScoreTest, GIVEN_A0VSB0_THEN_LOVE_ALL)
{
    EXPECT_EQ("LOVE ALL", MatchScore::displayMatchResult(PlayerInfo("A", 0), PlayerInfo("B", 0)));
}

TEST(MatchScoreTest, GIVEN_A1VSB0_THEN_FIFTEEN_LOVE)
{
    EXPECT_EQ("FIFTEEN LOVE", MatchScore::displayMatchResult(PlayerInfo("A", 1), PlayerInfo("B", 0)));
}

TEST(MatchScoreTest, GIVEN_A0VSB1_THEN_LOVE_FIFTEEN)
{
    EXPECT_EQ("LOVE FIFTEEN", MatchScore::displayMatchResult(PlayerInfo("A", 0), PlayerInfo("B", 1)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A2VSB2_THEN_THIRTY_ALL)
{
    EXPECT_EQ("THIRTY ALL", MatchScore::displayMatchResult(PlayerInfo("A", 2), PlayerInfo("B", 2)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A2VSB1_THEN_THIRTY_FIFTEEN)
{
    EXPECT_EQ("THIRTY FIFTEEN", MatchScore::displayMatchResult(PlayerInfo("A", 2), PlayerInfo("B", 1)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A1VSB2_THEN_FIFTEEN_THIRTY)
{
    EXPECT_EQ("FIFTEEN THIRTY", MatchScore::displayMatchResult(PlayerInfo("A", 1), PlayerInfo("B", 2)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A1VSB1_THEN_FIFTEEN_ALL)
{
    EXPECT_EQ("FIFTEEN ALL", MatchScore::displayMatchResult(PlayerInfo("A", 1), PlayerInfo("B", 1)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A3VSB1_THEN_FORTY_FIFTEEN)
{
    EXPECT_EQ("FORTY FIFTEEN", MatchScore::displayMatchResult(PlayerInfo("A", 3), PlayerInfo("B", 1)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A3VSB0_THEN_FORTY_LOVE)
{
    EXPECT_EQ("FORTY LOVE", MatchScore::displayMatchResult(PlayerInfo("A", 3), PlayerInfo("B", 0)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A3VSB2_THEN_FORTY_THIRTY)
{
    EXPECT_EQ("FORTY THIRTY", MatchScore::displayMatchResult(PlayerInfo("A", 3), PlayerInfo("B", 2)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A3VSB3_THEN_DEUCE)
{
    EXPECT_EQ("DEUCE", MatchScore::displayMatchResult(PlayerInfo("A", 3), PlayerInfo("B", 3)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A2VSB3_THEN_THIRTY_FORTY)
{
    EXPECT_EQ("THIRTY FORTY", MatchScore::displayMatchResult(PlayerInfo("A", 2), PlayerInfo("B", 3)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A1VSB3_THEN_FIFTEEN_FORTY)
{
    EXPECT_EQ("FIFTEEN FORTY", MatchScore::displayMatchResult(PlayerInfo("A", 1), PlayerInfo("B", 3)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A0VSB3_THEN_LOVE_FORTY)
{
    EXPECT_EQ("LOVE FORTY", MatchScore::displayMatchResult(PlayerInfo("A", 0), PlayerInfo("B", 3)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A4VSB0_THEN_A_WIN)
{
    EXPECT_EQ("A WIN", MatchScore::displayMatchResult(PlayerInfo("A", 4), PlayerInfo("B", 0)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A4VSB4_THEN_DEUCE)
{
    EXPECT_EQ("DEUCE", MatchScore::displayMatchResult(PlayerInfo("A", 4), PlayerInfo("B", 4)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A0VSB4_THEN_DEUCE)
{
    EXPECT_EQ("B WIN", MatchScore::displayMatchResult(PlayerInfo("A", 0), PlayerInfo("B", 4)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A4VSB2_THEN_A_WIN)
{
    EXPECT_EQ("A WIN", MatchScore::displayMatchResult(PlayerInfo("A", 4), PlayerInfo("B", 2)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A5VSB3_THEN_A_WIN)
{
    EXPECT_EQ("A WIN", MatchScore::displayMatchResult(PlayerInfo("A", 5), PlayerInfo("B", 3)));
}

TEST(MatchScoreTest, Tennis_GIVEN_A3VSB5_THEN_B_WIN)
{
    EXPECT_EQ("B WIN", MatchScore::displayMatchResult(PlayerInfo("A", 3), PlayerInfo("B", 5)));
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    system("pause");
    return 0;
}