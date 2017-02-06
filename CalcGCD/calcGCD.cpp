#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
using namespace std;
int CalcGCD(int num1, int num2)
{
    if (num1 > num2) std::swap(num1, num2);
    if (num1 < 0 || num2 < 0 || (num2 == 0)) return -1;
    if (num1 == 0) return num2;
    int i = num2 % num1;
    while (i >= 1)
    {
        if ((num1%i == 0)) return i;
        num2 = num1;
        num1 = i;
        i = num2 % num1;
    }
    return num1;
}
//for (int i = num2 % num1; i >= 1; num2 = num1, num1 = i, i = num2 % num1)
//{
//    if ((num1%i == 0))
//    {
//        return i;
//    }
//    
//}
TEST(CALCGCD, CalcGCD_GIVEN_2VS3_THEN_1)
{
    ASSERT_EQ(1, CalcGCD(2, 3));
}

TEST(CALCGCD, CalcGCD_GIVEN_3_3_THEN_3)
{
    ASSERT_EQ(3, CalcGCD(3, 3));
}

TEST(CALCGCD, CalcGCD_GIVEN_2_4_THEN_2)
{
    ASSERT_EQ(2, CalcGCD(2, 4));
}

TEST(CALCGCD, CalcGCD_GIVEN_4_2_THEN_2)
{
    ASSERT_EQ(2, CalcGCD(4, 2));
}

TEST(CALCGCD, CalcGCD_GIVEN_8_2_THEN_2)
{
    ASSERT_EQ(2, CalcGCD(8, 2));
}
TEST(CALCGCD, CalcGCD_GIVEN_7_2_THEN_1)
{
    ASSERT_EQ(1, CalcGCD(7, 2));
}
TEST(CALCGCD, CalcGCD_GIVEN_20_6_THEN_2)
{
    ASSERT_EQ(2, CalcGCD(20, 6));
}
TEST(CALCGCD, CalcGCD_GIVEN_6_20_THEN_2)
{
    ASSERT_EQ(2, CalcGCD(6, 20));
}
TEST(CALCGCD, CalcGCD_GIVEN_0_1_THEN_1)
{
    ASSERT_EQ(1, CalcGCD(0, 1));
}
TEST(CALCGCD, CalcGCD_GIVEN_0_0_THEN_neg1)
{
    ASSERT_EQ(-1, CalcGCD(0, 0));
}
TEST(CALCGCD, CalcGCD_GIVEN_neg2_neg2_THEN_neg1)
{
    ASSERT_EQ(-1, CalcGCD(-2, -2));
}
TEST(CALCGCD, CalcGCD_GIVEN_27_18_THEN_9)
{
    ASSERT_EQ(9, CalcGCD(27, 18));
}
TEST(CALCGCD, CalcGCD_GIVEN_27_9_THEN_9)
{
    ASSERT_EQ(9, CalcGCD(27, 9));
}

TEST(CALCGCD, CalcGCD_GIVEN_42_12_THEN_3)
{
    ASSERT_EQ(6, CalcGCD(42, 12));
}
TEST(CALCGCD, CalcGCD_GIVEN_42_14_THEN_14)
{
    ASSERT_EQ(14, CalcGCD(42, 14));
}
TEST(CALCGCD, CalcGCD_GIVEN_64_18_THEN_2)
{
    ASSERT_EQ(2, CalcGCD(64, 18));
}
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    system("pause");
    return 0;
}