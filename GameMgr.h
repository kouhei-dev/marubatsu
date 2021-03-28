#pragma once
#include <vector>
#include <string>
#include "e_SquareState.h"

class GameMgr
{
public:
    GameMgr(int width = 3, int height = 3);
    void draw();
    // @return : ゲームが終了したらtrue
    bool update(const std::string& strInput);

    int getCurrentTurnPlayer() const { return m_currentTurnPlayer; }
    e_SquareState getSquareStateByCurrentPlayer() const {
        return (getCurrentTurnPlayer() == 0) ? e_SquareState::Maru : e_SquareState::Batsu;
    }
    e_SquareState& getSquare(int index)
    {
        return m_board.at(index);
    }

private:
    bool checkGameEnd() const;

    int m_currentTurnPlayer = 0;
    const int m_width;
    const int m_height;
    std::vector<e_SquareState> m_board;
};
