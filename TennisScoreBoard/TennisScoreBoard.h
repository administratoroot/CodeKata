#pragma once

#include <string>

class PlayerInfo
{
public:
    PlayerInfo(std::string sName, int nScore);
public:
    std::string GetPlayerName() const;
    int GetPlayerScore() const;

    int DeltaScore(const PlayerInfo& otherPlayer) const;
    std::string makeScoresWith(const PlayerInfo& otherPlayer) const;
private:
    std::string m_sPlayerName;
    int m_nScore;
};




