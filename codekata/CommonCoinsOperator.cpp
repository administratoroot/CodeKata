#include "CommonCoinsOperator.h"
#include <iostream>

using namespace std;

CommonCoinsOperator::CommonCoinsOperator() 
{
    m_nCoinCountArray[Coin_Pennie] = 0;
    m_nCoinCountArray[Coin_Nickel] = 0;
    m_nCoinCountArray[Coin_Dime] = 0;
    m_nCoinCountArray[Coin_Quarter] = 0;
}                                         

CommonCoinsOperator::CommonCoinsOperator(int nPenniesCount, int nNickelsCount, int nDimesCount, int nQuartersCount)
{ 
    m_nCoinCountArray[Coin_Pennie] = nPenniesCount;
    m_nCoinCountArray[Coin_Nickel] = nNickelsCount;
    m_nCoinCountArray[Coin_Dime] = nDimesCount;
    m_nCoinCountArray[Coin_Quarter] = nQuartersCount;
}


CommonCoinsOperator::~CommonCoinsOperator()
{
}

int CommonCoinsOperator::getFaceValue()
{
    return  m_nCoinCountArray[Coin_Pennie] * CommonCoinFaceValue[Coin_Pennie]
        + m_nCoinCountArray[Coin_Nickel] * CommonCoinFaceValue[Coin_Nickel]
        + m_nCoinCountArray[Coin_Dime] * CommonCoinFaceValue[Coin_Dime]
        + m_nCoinCountArray[Coin_Quarter] * CommonCoinFaceValue[Coin_Quarter];
}

int CommonCoinsOperator::getMaxCoinCount(EnCoinType enCoinType, int nValue)
{
    return nValue / CommonCoinFaceValue[enCoinType];
}

void CommonCoinsOperator::setCoinCount(EnCoinType enCoinType, int nCount)
{
    m_nCoinCountArray[enCoinType] = nCount;
}

void CommonCoinsOperator::genCoinGroup()
{
    std::string str = getCoinStr(Coin_Pennie)
        + getCoinStr(Coin_Nickel)
        + getCoinStr(Coin_Dime)
        + getCoinStr(Coin_Quarter);
    m_VecOutput.push_back(str);
    //"There are 6 ways to make change for 15 cents:"
    //A dime and a nickel;
    //A dime and 5 pennies;
    //3 nickels;
    //2 nickels and 5 pennies;
    //A nickel and 10 pennies;
    //15 pennies.
}

std::string CommonCoinsOperator::getCoinStr(EnCoinType enCoinType)
{
    std::string result;
    if (m_nCoinCountArray[enCoinType] == 0)
    {
        return "";
    }
    else if (m_nCoinCountArray[enCoinType] == 1)
    {
        result = (isFirstCoin(enCoinType) ? "A" : "a");
        result += " " + CommonCoinFaceName[enCoinType];
    }
    else
    {
        result = numToString(m_nCoinCountArray[enCoinType]) + " " + CommonCoinFaceName[enCoinType] + "s";
    }
    result += (isLastCoin(enCoinType)) ? "" : " and ";
    return result;
}

bool CommonCoinsOperator::isFirstCoin(EnCoinType enCoinType)
{
    int i = static_cast<int>(enCoinType);
    --i;
    while (i >= 0)
    {
        if (m_nCoinCountArray[i] != 0)
        {
            return false;
        }
        --i;
    }
    return true;
}

bool CommonCoinsOperator::isLastCoin(EnCoinType enCoinType)
{
    int i = static_cast<int>(enCoinType);
    ++i;
    while (i < 4)
    {
        if (m_nCoinCountArray[i] != 0)
        {
            return false;
        }
        ++i;
    }
    return true;
}

std::string CommonCoinsOperator::numToString(int nValue)
{
    std::string str;
    char buffer[256];
    sprintf(buffer, "%d", nValue);
    str = buffer;
    return str;
}

void CommonCoinsOperator::printCoinGroup()
{
    int nSize = m_VecOutput.size();
    for (int i = 0; i < nSize;++i)
    {
        cout << m_VecOutput[i];
        if (i != (nSize - 1))
        {
            cout << ";";
        }
        else
        {
            cout << ".";
        }
        cout << endl;
    }
}

void CommonCoinsOperator::operator()(int nPenniesCount, int nNickelsCount, int nDimesCount, int nQuartersCount)
{
    m_nCoinCountArray[Coin_Pennie] = nPenniesCount;
    m_nCoinCountArray[Coin_Nickel] = nNickelsCount;
    m_nCoinCountArray[Coin_Dime] = nDimesCount;
    m_nCoinCountArray[Coin_Quarter] = nQuartersCount;
}

