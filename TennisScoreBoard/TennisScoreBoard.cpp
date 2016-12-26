#include "TennisScoreBoard.h"
static const std::string scoreArray[] = { "LOVE", "FIFTEEN", "THIRTY", "FORTY" };
std::string keyStatus[] = { "DEUCE", "ADVANTAGE", "WIN" };

PlayerInfo::PlayerInfo(std::string sName, int nScore) :m_sPlayerName(sName), m_nScore(nScore)
{

}

std::string PlayerInfo::getPlayerName() const
{
    return m_sPlayerName;
}

int PlayerInfo::getPlayerScore() const
{
    return m_nScore;
}

int MatchScore::calcDeltaScore(const PlayerInfo& PlayerA, const PlayerInfo& PlayerB)
{
    return PlayerA.getPlayerScore() - PlayerB.getPlayerScore();
}

std::string MatchScore::makeScoresWith(const PlayerInfo& PlayerA, const PlayerInfo& PlayerB)
{
    return scoreArray[PlayerA.getPlayerScore()] + " " + scoreArray[PlayerB.getPlayerScore()];
}

std::string MatchScore::getDeuceOrWinnaOrAdvantage(const PlayerInfo& playerA, const PlayerInfo& playerB)
{
    int nDeltaScore = MatchScore::calcDeltaScore(playerA, playerB);
    int nIndex = (abs(nDeltaScore)) > 2 ? 2 : abs(nDeltaScore);
    std::string sStatus = keyStatus[nIndex];
    std::string sPlayName = (nDeltaScore > 0) ? playerA.getPlayerName() : playerB.getPlayerName();
    return (nDeltaScore == 0) ? sStatus : sPlayName + " " + sStatus;
}

std::string MatchScore::displayMatchResult(const PlayerInfo& playerA, const PlayerInfo& playerB)
{
    if (playerA.getPlayerScore() > 3 || playerB.getPlayerScore() > 3)
    {
        return MatchScore::getDeuceOrWinnaOrAdvantage(playerA, playerB);
    }
    if (playerB.getPlayerScore() == playerA.getPlayerScore())
    {
        return (playerA.getPlayerScore() == 3) ? "DEUCE" : scoreArray[playerA.getPlayerScore()] + " ALL";
    }
    return MatchScore::makeScoresWith(playerA, playerB);
}