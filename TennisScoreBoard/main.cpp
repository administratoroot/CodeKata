#include "gtest/gtest.h"
#include "TennisScoreBoard.h"
std::string Scores[] = {"DEUCE", "ADVANTAGE", "WIN" };
std::string getDeuceOrWinnaOrAdvantage(const PlayerInfo& playerA, const PlayerInfo& playerB)
{
    if (playerA.GetPlayerScore() == playerB.GetPlayerScore())
    {
        return Scores[0];
    }
    return (playerA.GetPlayerScore() > playerB.GetPlayerScore()) ? 
        playerA.GetPlayerName() + " " + ((playerA.DeltaScore(playerB) < 2) ? Scores[1] : Scores[2])
      : playerB.GetPlayerName() + " " + ((playerB.DeltaScore(playerA) < 2) ? Scores[1] : Scores[2]);
}

std::string Tennis(const PlayerInfo& playerA, const PlayerInfo& playerB)
{
    if (playerA.GetPlayerScore() + playerB.GetPlayerScore() == 0)
    {
        return "LOVE ALL";
    }

    if ((playerA.GetPlayerScore() <= 3 && playerB.GetPlayerScore() <= 3))
    {
        if (playerB.GetPlayerScore() == playerA.GetPlayerScore())
        {
            if (playerA.GetPlayerScore() == 0)
            {
                return "LOVE ALL";
            }
            else if (playerA.GetPlayerScore() == 3)
            {
                return "DEUCE";
            }
        }
        return playerA.makeScoresWith(playerB);
    }
    else if (playerA.GetPlayerScore() > 3 || playerB.GetPlayerScore() > 3)
    {
        return getDeuceOrWinnaOrAdvantage(playerA, playerB);
    }
    return "";
}

TEST(Tennis, GIVEN_A0VSB0_THEN_LOVE_ALL)
{
    EXPECT_EQ("LOVE ALL", Tennis(PlayerInfo("A", 0), PlayerInfo("B", 0)));
}

TEST(Tennis, GIVEN_A1VSB0_THEN_FIFTEEN_LOVE)
{
    EXPECT_EQ("FIFTEEN LOVE", Tennis(PlayerInfo("A", 1), PlayerInfo("B", 0)));
}

TEST(Tennis, GIVEN_A0VSB1_THEN_LOVE_FIFTEEN)
{
    EXPECT_EQ("LOVE FIFTEEN", Tennis(PlayerInfo("A", 0), PlayerInfo("B", 1)));
}

TEST(Tennis, Tennis_GIVEN_A2VSB2_THEN_THIRTY_THIRTY)
{
    EXPECT_EQ("THIRTY THIRTY", Tennis(PlayerInfo("A", 2), PlayerInfo("B", 2)));
}

TEST(Tennis, Tennis_GIVEN_A2VSB1_THEN_THIRTY_FIFTEEN)
{
    EXPECT_EQ("THIRTY FIFTEEN", Tennis(PlayerInfo("A", 2), PlayerInfo("B", 1)));
}

TEST(Tennis, Tennis_GIVEN_A1VSB2_THEN_FIFTEEN_THIRTY)
{
    EXPECT_EQ("FIFTEEN THIRTY", Tennis(PlayerInfo("A", 1), PlayerInfo("B", 2)));
}

TEST(Tennis, Tennis_GIVEN_A1VSB1_THEN_FIFTEEN_FIFTEEN)
{
    EXPECT_EQ("FIFTEEN FIFTEEN", Tennis(PlayerInfo("A", 1), PlayerInfo("B", 1)));
}

TEST(Tennis, Tennis_GIVEN_A3VSB1_THEN_FORTY_FIFTEEN)
{
    EXPECT_EQ("FORTY FIFTEEN", Tennis(PlayerInfo("A", 3), PlayerInfo("B", 1)));
}

TEST(Tennis, Tennis_GIVEN_A3VSB0_THEN_FORTY_LOVE)
{
    EXPECT_EQ("FORTY LOVE", Tennis(PlayerInfo("A", 3), PlayerInfo("B", 0)));
}

TEST(Tennis, Tennis_GIVEN_A3VSB2_THEN_FORTY_THIRTY)
{
    EXPECT_EQ("FORTY THIRTY", Tennis(PlayerInfo("A", 3), PlayerInfo("B", 2)));
}

TEST(Tennis, Tennis_GIVEN_A3VSB3_THEN_DEUCE)
{
    EXPECT_EQ("DEUCE", Tennis(PlayerInfo("A", 3), PlayerInfo("B", 3)));
}

TEST(Tennis, Tennis_GIVEN_A2VSB3_THEN_THIRTY_FORTY)
{
    EXPECT_EQ("THIRTY FORTY", Tennis(PlayerInfo("A", 2), PlayerInfo("B", 3)));
}

TEST(Tennis, Tennis_GIVEN_A1VSB3_THEN_FIFTEEN_FORTY)
{
    EXPECT_EQ("FIFTEEN FORTY", Tennis(PlayerInfo("A", 1), PlayerInfo("B", 3)));
}

TEST(Tennis, Tennis_GIVEN_A0VSB3_THEN_LOVE_FORTY)
{
    EXPECT_EQ("LOVE FORTY", Tennis(PlayerInfo("A", 0), PlayerInfo("B", 3)));
}

TEST(Tennis, Tennis_GIVEN_A4VSB0_THEN_A_WIN)
{
    EXPECT_EQ("A WIN", Tennis(PlayerInfo("A", 4), PlayerInfo("B", 0)));
}

TEST(Tennis, Tennis_GIVEN_A4VSB4_THEN_DEUCE)
{
    EXPECT_EQ("DEUCE", Tennis(PlayerInfo("A", 4), PlayerInfo("B", 4)));
}

TEST(Tennis, Tennis_GIVEN_A0VSB4_THEN_DEUCE)
{
    EXPECT_EQ("B WIN", Tennis(PlayerInfo("A", 0), PlayerInfo("B", 4)));
}

TEST(Tennis, Tennis_GIVEN_A4VSB2_THEN_A_WIN)
{
    EXPECT_EQ("A WIN", Tennis(PlayerInfo("A", 4), PlayerInfo("B", 2)));
}

TEST(Tennis, Tennis_GIVEN_A5VSB3_THEN_A_WIN)
{
    EXPECT_EQ("A WIN", Tennis(PlayerInfo("A", 5), PlayerInfo("B", 3)));
}

TEST(Tennis, Tennis_GIVEN_A3VSB5_THEN_B_WIN)
{
    EXPECT_EQ("B WIN", Tennis(PlayerInfo("A", 3), PlayerInfo("B", 5)));
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    system("pause");
    return 0;
}