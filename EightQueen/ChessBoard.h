#pragma once
#include <vector>
class ChessBoard
{
public:
    ChessBoard();
    //不合适的最大值
    struct UnFitMaxValueInfo
    {
        int m_x;    //点x坐标
        int m_y;    //点y坐标
        int m_value;//数值
    };
    struct Pos
    {
        public:
            int m_x;
            int m_y;
        public:
            Pos(int x, int y);
            Pos();
            bool isPointValid();
    };

    //获取棋盘
    std::vector<std::vector<int>> getChessBoard();
    //打印棋盘
    void printChessBoard();

    //在某个位置落子
    void insertChessPiece(int i, int j, int nTimes);
    void insertChessPiece(const Pos& pos, int nTimes);

    //判断传入点是否已经有棋子
    bool isHaveChessPiece(int i, int j);
    bool isHaveChessPiece(const Pos& pos);

    //获取下一个点
    Pos getNextPiecePos(int i, int j);
    Pos getNextPiecePos(const Pos& pos);

    void insertNextPiece(int i, int j);

    //获取当前棋盘上的最大值，及位置
    UnFitMaxValueInfo getMaxValueInfo();

    void cleanAllGreatThanValues(const UnFitMaxValueInfo& unFitInfo);
private:
    bool isValidCross(int i, int j);
    bool isNotHaveChessPieceInList(const std::vector<int>& vecList);

    std::vector<int> getSameRowOtherItems(int i, int j);
    std::vector<int> getSameColumnOtherItems(int i, int j);
    std::vector<int> getSameSlashOtherItems(int i, int j);
    std::vector<int> getSameBackslashOtherItems(int i, int j);

    //获取斜线方向的棋子
    void getLeftTopChessPiece(std::vector<int>& vecResults, int i, int j, bool bLeft, bool bTop);
    //判断位置是否合法
    bool isInBoard(int i, int j);
private:
    std::vector<std::vector<int>> m_vecChessboard;
    int m_nTimes;
    UnFitMaxValueInfo m_unFitMinValueInfo;
};

