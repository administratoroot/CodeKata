/************************************************************************/
/* 
There are four types of common coins in US currency:
quarters (25 cents)
dimes (10 cents)
nickels (5 cents)
pennies (1 cent)

There are 6 ways to make change for 15 cents:
A dime and a nickel;
A dime and 5 pennies;
3 nickels;
2 nickels and 5 pennies;
A nickel and 10 pennies;
15 pennies.

How many ways are there to make change for a dollar
using these common coins? (1 dollar = 100 cents).

[Source http://rosettacode.org]
*/
/************************************************************************/
#include <iostream>

#include "gtest/gtest.h"
enum EnCoinType
{
    Coin_Pennie = 1,
    Coin_Nickel = 5,
    Coin_Dime = 10,
    Coin_Quarter = 25
};
//sometimes not the problem is complex,it is we make the problem complex and difficult.
//zhangxun 2017/2/25 0:16AM
int CoinCounts(int nValue)
{
    int nWays = 0;
    for (int nQuarterCount = nValue / Coin_Quarter; nQuarterCount >= 0; --nQuarterCount)
    {
        int nTotalLessQ = nValue - nQuarterCount * Coin_Quarter;
        for (int nDimeCount = nTotalLessQ / Coin_Dime; nDimeCount >= 0; --nDimeCount)
        {
            int nTotalLessD = nTotalLessQ - nDimeCount * Coin_Dime;
            for (int nNickelCount = nTotalLessD / Coin_Nickel; nNickelCount >= 0; --nNickelCount)
            {
                int nPennieCount = nTotalLessD - nNickelCount * Coin_Nickel;
                std::cout << " " << nQuarterCount << " " << nDimeCount << " " << nNickelCount << " " << nPennieCount << std::endl;
                nWays++;
            }
        }
    }
    return nWays;
}

TEST(CountCoinsTest, CountCoins_GIVEN_1_THEN_1)
{
    ASSERT_EQ(1, CoinCounts(1));
}

TEST(CountCoinsTest, CountCoins_GIVEN_2_THEN_1)
{
    ASSERT_EQ(1, CoinCounts(2));
}

TEST(CountCoinsTest, CountCoins_GIVEN_5_THEN_2)
{
    ASSERT_EQ(2, CoinCounts(5));
}

TEST(CountCoinsTest, CountCoins_GIVEN_10_THEN_4)
{
    ASSERT_EQ(4, CoinCounts(10));
}

TEST(CountCoinsTest, CountCoins_GIVEN_15_THEN_6)
{
    ASSERT_EQ(6, CoinCounts(15));
}

TEST(CountCoinsTest, CountCoins_GIVEN_20_THEN_9)
{
    ASSERT_EQ(9, CoinCounts(20));
}

TEST(CountCoinsTest, CountCoins_GIVEN_35_THEN_24)
{
    ASSERT_EQ(24, CoinCounts(35));
}

TEST(CountCoinsTest, CountCoins_GIVEN_40_THEN_31)
{
    ASSERT_EQ(31, CoinCounts(40));
}

TEST(CountCoinsTest, CountCoins_GIVEN_100_THEN_242)
{
    ASSERT_EQ(242, CoinCounts(100));
}

int main(int argc, char* argv[])
{
    //testing::InitGoogleTest(&argc, argv);
    //RUN_ALL_TESTS();
    std::cout<<CoinCounts(45);
    system("pause");
    return 0;
}