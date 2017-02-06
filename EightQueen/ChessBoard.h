#pragma once
#include <vector>
class ChessBoard
{
public:
    ChessBoard();
    //�����ʵ����ֵ
    struct UnFitMaxValueInfo
    {
        int m_x;    //��x����
        int m_y;    //��y����
        int m_value;//��ֵ
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

    //��ȡ����
    std::vector<std::vector<int>> getChessBoard();
    //��ӡ����
    void printChessBoard();

    //��ĳ��λ������
    void insertChessPiece(int i, int j, int nTimes);
    void insertChessPiece(const Pos& pos, int nTimes);

    //�жϴ�����Ƿ��Ѿ�������
    bool isHaveChessPiece(int i, int j);
    bool isHaveChessPiece(const Pos& pos);

    //��ȡ��һ����
    Pos getNextPiecePos(int i, int j);
    Pos getNextPiecePos(const Pos& pos);

    void insertNextPiece(int i, int j);

    //��ȡ��ǰ�����ϵ����ֵ����λ��
    UnFitMaxValueInfo getMaxValueInfo();

    void cleanAllGreatThanValues(const UnFitMaxValueInfo& unFitInfo);
private:
    bool isValidCross(int i, int j);
    bool isNotHaveChessPieceInList(const std::vector<int>& vecList);

    std::vector<int> getSameRowOtherItems(int i, int j);
    std::vector<int> getSameColumnOtherItems(int i, int j);
    std::vector<int> getSameSlashOtherItems(int i, int j);
    std::vector<int> getSameBackslashOtherItems(int i, int j);

    //��ȡб�߷��������
    void getLeftTopChessPiece(std::vector<int>& vecResults, int i, int j, bool bLeft, bool bTop);
    //�ж�λ���Ƿ�Ϸ�
    bool isInBoard(int i, int j);
private:
    std::vector<std::vector<int>> m_vecChessboard;
    int m_nTimes;
    UnFitMaxValueInfo m_unFitMinValueInfo;
};

