#include<iostream>
#include "gtest/gtest.h"
#include "ChessBoard.h"
using namespace std;


TEST(ChessBoardTest, Given_ConstructChessBoard_then_DefultChessBoard)
{
    ChessBoard chessBoard;
    vector<vector<int>>& vecChessBoard = chessBoard.getChessBoard();
    EXPECT_EQ(8, vecChessBoard.size());
    for (int i = 0; i < 8; ++i)
    {
        std::vector<int>& vecRow = vecChessBoard.at(i);
        EXPECT_EQ(8, vecRow.size());
        for (int j = 0; j < 8; ++j)
        {
            EXPECT_EQ(0, vecRow.at(j));
        }
    }
}

TEST(ChessBoardTest, Given_Insert_2_3_then_ChessBoard_2_3_HaveChessPiece)
{
    ChessBoard chessBoard;
    chessBoard.insertChessPiece(2, 3, 1);
    vector<vector<int>>& vecChessBoard = chessBoard.getChessBoard();
    EXPECT_EQ(8, vecChessBoard.size());
    for (int i = 0; i < 8; ++i)
    {
        std::vector<int>& vecRow = vecChessBoard.at(i);
        EXPECT_EQ(8, vecRow.size());
        for (int j = 0; j < 8; ++j)
        {
            if (i==2 && j==3)
            {
                EXPECT_EQ(1, vecRow.at(j));
            }
            else
            {
                EXPECT_EQ(0, vecRow.at(j));
            }
        }
    }
}

int main(int argc,char* argv[])
{
    //testing::InitGoogleTest(&argc, argv);
    //RUN_ALL_TESTS();
    ChessBoard chessBoard;
    chessBoard.insertNextPiece(0, 0);
    chessBoard.printChessBoard();
    system("pause");
    return 0;
}