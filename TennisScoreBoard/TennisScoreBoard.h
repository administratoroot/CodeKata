#pragma once

#include <string>

class PlayerInfo
{
public:
    PlayerInfo(std::string sName, int nScore);
public:
    std::string getPlayerName() const;
    int getPlayerScore() const;

private:
    std::string m_sPlayerName;
    int m_nScore;
};

class MatchScore
{
public:
    static std::string displayMatchResult(const PlayerInfo& playerA, const PlayerInfo& playerB);
protected:
    static std::string getDeuceOrWinnaOrAdvantage(const PlayerInfo& playerA, const PlayerInfo& playerB);
    static int calcDeltaScore(const PlayerInfo& PlayerA, const PlayerInfo& PlayerB);
    static std::string makeScoresWith(const PlayerInfo& PlayerA, const PlayerInfo& PlayerB);
private:

};




