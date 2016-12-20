#include "gtest/gtest.h"
#include <string>

class PlayerInfo
{
public:
    PlayerInfo(std::string sName, int nScore) :m_sPlayerName(sName), m_nScore(nScore) {};
    std::string GetPlayerName() { return m_sPlayerName; }
    int GetPlayerScore() { return m_nScore; }
    int DeltaScore(PlayerInfo& otherPlayer)
    {
        return this->m_nScore - otherPlayer.m_nScore;
    }
private:
    std::string m_sPlayerName;
    int m_nScore;
};

std::string JointScores(PlayerInfo playerA, PlayerInfo playerB)
{
    static const std::string scoreArray[] = { "LOVE", "FIFTEEN", "THIRTY", "FORTY" };

    return scoreArray[playerA.GetPlayerScore()] + " " + scoreArray[playerB.GetPlayerScore()];
}

std::string Tennis(PlayerInfo playerA, PlayerInfo playerB)
{

    if (playerA.GetPlayerScore() + playerB.GetPlayerScore() == 0)
    {

        return "LOVE ALL";

    }

    if ((playerB.GetPlayerScore() == playerA.GetPlayerScore() && playerA.GetPlayerScore() >= 3))
    {
        return "DEUCE";
    }
    else if ((playerA.GetPlayerScore() <= 3 && playerB.GetPlayerScore() <= 3))
    {
        return JointScores(playerA, playerB);
    }
    else if (playerA.GetPlayerScore() >= 4 && playerA.DeltaScore(playerB) >= 2)
    {
        return playerA.GetPlayerName() + " " + "WIN";
    }
    else if (playerB.GetPlayerScore() >= 4 && playerA.DeltaScore(playerB) <= -2)
    {
        return playerB.GetPlayerName() + " " + "WIN";
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