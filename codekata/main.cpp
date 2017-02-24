#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include "CommonCoinsOperator.h"
using namespace std;

//int CountCoins(int nValue)
//{
//    CommonCoinsOperator oper;
//    int nMaxPenniesCount = CommonCoinsOperator::getMaxCoinCount(Coin_Pennie, nValue);
//    int nMaxNickelsCount = CommonCoinsOperator::getMaxCoinCount(Coin_Nickel, nValue);
//    int nMaxDimesCount = CommonCoinsOperator::getMaxCoinCount(Coin_Dime, nValue);
//    int nMaxQuartersCount = CommonCoinsOperator::getMaxCoinCount(Coin_Quarter, nValue);
//    int nCount = 0;
//    for (int nPenniesCount = 0; nPenniesCount <= nMaxPenniesCount; ++nPenniesCount)
//    {
//        for (int nNickelsCount = 0; nNickelsCount <= nMaxNickelsCount; ++nNickelsCount)
//        {
//            for (int nDimesCount = 0; nDimesCount <= nMaxDimesCount; ++nDimesCount)
//            {
//                for (int nQuartersCount = 0; nQuartersCount <= nMaxQuartersCount; ++nQuartersCount)
//                {
//                    oper(nPenniesCount, nNickelsCount, nDimesCount, nQuartersCount);
//                    if (oper.getFaceValue() == nValue)
//                    {
//                        ++nCount;
//                        oper.genCoinGroup();
//                    }
//                }
//            }
//        }
//    }
//    //cout << "There are " << CommonCoinsOperator::numToString(nCount) 
//    //    << " ways to make change for " << CommonCoinsOperator::numToString(nValue) 
//    //    << " cents:" << endl;
//    //oper.printCoinGroup();
//    return nCount;
//}

int CountCoins(int nValue)
{
    int k = nValue / 5;
    int sum = 0;
    for (int i = 0; i <= k; i++)
    {
        sum += deltaValue(i);
    }
    return sum;
}



TEST(CountCoinsTest, CountCoins_GIVEN_1_THEN_1)
{
    ASSERT_EQ(1, CountCoins(1));
}

TEST(CountCoinsTest, CountCoins_GIVEN_2_THEN_1)
{
    ASSERT_EQ(1, CountCoins(2));
}

TEST(CountCoinsTest, CountCoins_GIVEN_5_THEN_2)
{
    ASSERT_EQ(2, CountCoins(5));
}

TEST(CountCoinsTest, CountCoins_GIVEN_10_THEN_4)
{
    ASSERT_EQ(4, CountCoins(10));
}

TEST(CountCoinsTest, CountCoins_GIVEN_15_THEN_6)
{
    ASSERT_EQ(6, CountCoins(15));
}

TEST(CountCoinsTest, CountCoins_GIVEN_100_THEN_242)
{
    ASSERT_EQ(242, CountCoins(100));
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    //for (int i = 1; i <= 100;i++)
    //{
    //    cout  << i << " " << CountCoins(i) << " ";
    //    getMinCount(i);
    //    cout << endl;
    //}
    cout << CountCoins(100);
    system("pause");
    return 0;
}

