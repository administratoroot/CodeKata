#pragma once
#include <string>
#include <vector>
static int CommonCoinFaceValue[4] = { 1, 5, 10, 25 };
static std::string CommonCoinFaceName[4] = { "pennie", "nickels", "dimes", "quarters"};
enum EnCoinType
{
    Coin_Pennie = 0,
    Coin_Nickel = 1,
    Coin_Dime = 2,
    Coin_Quarter = 3
};

class CommonCoinsOperator
{
public:
    CommonCoinsOperator();
    CommonCoinsOperator(int nPenniesCount, int nNickelsCount, int nDimesCount, int nQuartersCount);
    ~CommonCoinsOperator();
public:
    static int getMaxCoinCount(EnCoinType enCoinType, int nValue);
    static std::string numToString(int nValue);
    void operator()(int nPenniesCount, int nNickelsCount, int nDimesCount, int nQuartersCount);
    int getFaceValue();

    void setCoinCount(EnCoinType enCoinType, int nCount);
 
    void genCoinGroup();

    void printCoinGroup();
private:
    std::string getCoinStr(EnCoinType enCoinType);
    bool isFirstCoin(EnCoinType enCoinType);
    bool isLastCoin(EnCoinType enCoinType);
private:
    int m_nCoinCountArray[4];
    std::vector<std::string> m_VecOutput;
};

