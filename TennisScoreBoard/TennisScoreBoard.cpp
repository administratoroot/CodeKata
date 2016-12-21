#include "TennisScoreBoard.h"
static const std::string scoreArray[] = { "LOVE", "FIFTEEN", "THIRTY", "FORTY" };

PlayerInfo::PlayerInfo(std::string sName, int nScore) :m_sPlayerName(sName), m_nScore(nScore)
{

}

std::string PlayerInfo::GetPlayerName() const
{
    return m_sPlayerName;
}

int PlayerInfo::GetPlayerScore() const
{
    return m_nScore;
}

int PlayerInfo::DeltaScore(const PlayerInfo& otherPlayer) const
{
    return this->m_nScore - otherPlayer.m_nScore;
}

std::string PlayerInfo::makeScoresWith(const PlayerInfo& otherPlayer) const
{
    return scoreArray[this->GetPlayerScore()] + " " + scoreArray[otherPlayer.GetPlayerScore()];
}

