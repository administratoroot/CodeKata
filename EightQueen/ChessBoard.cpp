#include "ChessBoard.h"
#include <iostream>
ChessBoard::ChessBoard()
{
    m_nTimes = 0;
    for (int i = 0; i < 8; ++i)
    {
        std::vector<int> vecRow;
        for (int j = 0; j < 8; ++j)
        {
            vecRow.push_back(0);
        }
        m_vecChessboard.push_back(vecRow);
    }
}

std::vector<std::vector<int>> ChessBoard::getChessBoard()
{
    return m_vecChessboard;
}

void ChessBoard::insertChessPiece(int i, int j, int nTimes)
{
    m_vecChessboard[i][j] = nTimes;
}

void ChessBoard::insertChessPiece(const Pos& pos, int nTimes)
{
    m_vecChessboard[pos.m_x][pos.m_y] = nTimes;
}

bool ChessBoard::isHaveChessPiece(int i, int j)
{
    if (m_vecChessboard[i][j] > 0)
    {
        return true;
    }
    return false;
}

bool ChessBoard::isHaveChessPiece(const Pos& pos)
{
    return isHaveChessPiece(pos.m_x, pos.m_y);
}

std::vector<int> ChessBoard::getSameRowOtherItems(int i, int j)
{
    std::vector<int> vecResults;

    for (int k = 0; k < 8; ++k)
    {
        if (k != j)
        {
            vecResults.push_back(m_vecChessboard[i][k]);
        }
    }
    return vecResults;
}

std::vector<int> ChessBoard::getSameColumnOtherItems(int i, int j)
{
    std::vector<int> vecResults;
    for (int k = 0; k < 8; ++k)
    {
        if (k != i)
        {
            vecResults.push_back(m_vecChessboard[k][j]);
        }
    }
    return vecResults;
}

std::vector<int> ChessBoard::getSameSlashOtherItems(int i, int j)
{
    std::vector<int> vecResults;
    getLeftTopChessPiece(vecResults, i, j, true, false);
    getLeftTopChessPiece(vecResults, i, j, false, true);
    return vecResults;
}

std::vector<int> ChessBoard::getSameBackslashOtherItems(int i, int j)
{
    std::vector<int> vecResults;
    getLeftTopChessPiece(vecResults, i, j, true, true);
    getLeftTopChessPiece(vecResults, i, j, false, false);
    return vecResults;
}

bool ChessBoard::isInBoard(int i, int j)
{
    if (i >= 0 && i < 8 && j >= 0 && j < 8)
    {
        return true;
    }
    return false;
}

void ChessBoard::getLeftTopChessPiece(std::vector<int>& vecResults, int i, int j, bool bLeft, bool bTop)
{
    int x = i;
    int y = j;
    while (true)
    {
        x = bTop ? x - 1 : x + 1;
        y = bLeft ? y - 1 : y + 1;
        if (isInBoard(x, y))
        {
            vecResults.push_back(m_vecChessboard[x][y]);
        }
        else
        {
            break;
        }
    }
}

bool ChessBoard::isValidCross(int i, int j)
{
    bool bValid = !isHaveChessPiece(i, j);
    if (!bValid)
    {
        return false;
    }
    std::vector<int> vecSameRowOtherItems = getSameRowOtherItems(i, j);
    bValid =isNotHaveChessPieceInList(vecSameRowOtherItems);
    if (!bValid)
    {
        return false;
    }

    std::vector<int> vecSameColumnOtherItems = getSameColumnOtherItems(i, j);
    bValid = isNotHaveChessPieceInList(vecSameColumnOtherItems);
    if (!bValid)
    {
        return false;
    }

    std::vector<int> vecSameSlashOtherItems = getSameSlashOtherItems(i, j);
    bValid = isNotHaveChessPieceInList(vecSameSlashOtherItems);
    if (!bValid)
    {
        return false;
    }

    std::vector<int> vecSameBackslashOtherItems = getSameBackslashOtherItems(i, j);
    bValid = isNotHaveChessPieceInList(vecSameBackslashOtherItems);
    if (!bValid)
    {
        return false;
    }
    return true;
}

bool ChessBoard::isNotHaveChessPieceInList(const std::vector<int>& vecList)
{
    for (auto it = vecList.begin(); it != vecList.end();++it)
    {
        if (*it != 0)
        {
            return false;
        }
    }
    return true;
}

ChessBoard::Pos ChessBoard::getNextPiecePos(int i, int j)
{
    Pos result;
    if (j < 8)
    {
        result.m_x = i;
        result.m_y = j + 1;
    }
    else
    {
        result.m_x = i + 1;
        result.m_y = 0;
    }
    if (result.isPointValid())
    {
        return result;
    }
    else
    {
        return Pos(-1, -1);
    } 
}

ChessBoard::Pos ChessBoard::getNextPiecePos(const Pos& pos)
{
    return getNextPiecePos(pos.m_x, pos.m_y);
}

void ChessBoard::insertNextPiece(int i, int j)
{
    bool bFirst = true;
    for (int x = i; x < 8; ++x)
    {
        if (x != i)
        {
            bFirst = false;
        }
        for (int y = (bFirst ? j : 0); y < 8; ++y)
        {
            if (isValidCross(x, y))
            {
                insertChessPiece(x, y, m_nTimes + 1);
                ++m_nTimes;
                if (m_nTimes == 8)
                {
                    return;
                }
                else
                {
                    insertNextPiece(0, 0);
                }
            }
            else
            {
                continue;
            }
        }
    }
    if (m_nTimes < 8)
    {

    }
}

void ChessBoard::printChessBoard()
{
    for (int i = 0; i < m_vecChessboard.size();++i)
    {
        std::vector<int>& vecRow = m_vecChessboard[i];
        for (int j = 0; j < vecRow.size(); ++j)
        {
            std::cout << m_vecChessboard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

ChessBoard::UnFitMaxValueInfo ChessBoard::getMaxValueInfo()
{
    UnFitMaxValueInfo info;
    info.m_value = -1;
    for (int i = 0; i < m_vecChessboard.size(); ++i)
    {
        std::vector<int>& vecRow = m_vecChessboard[i];
        for (int j = 0; j < vecRow.size(); ++j)
        {
            int nTemp = m_vecChessboard[i][j];
            if (info.m_value < nTemp)
            {
                info.m_value = nTemp;
                info.m_x = i;
                info.m_y = j;
            }
        }
    }
    return info;
}

bool ChessBoard::Pos::isPointValid()
{
    if (this->m_x >= 0 && this->m_x < 8 && this->m_y >= 0 && this->m_y < 8)
    {
        return true;
    }
    return false;
}

ChessBoard::Pos::Pos(int x, int y) :m_x(x), m_y(y)
{

}

ChessBoard::Pos::Pos() : m_x(0), m_y(0)
{

}
