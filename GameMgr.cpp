#include <iostream>
#include "GameMgr.h"

GameMgr::GameMgr(int width/*= 3*/, int height/* = 3*/)
    : m_width(width)
    , m_height(height)
{
    m_board.resize(width * height, e_SquareState::None);
}

void GameMgr::draw()
{
    int count = 0;
    for(const e_SquareState state : m_board)
    {
        drawSquareaState(state);
        ++count;
        if ( count == m_width ) {
            count = 0;
            std::cout << std::endl;
        }
    }
    std::cout << "プレイヤー" << getCurrentTurnPlayer() + 1 << "のターンです" << std::endl;
}

bool GameMgr::update(const std::string& strInput)
{
    int index;
    try {
        index = std::stoi( strInput );
    } catch (std::exception) {
        std::cout << "無効な入力です" << std::endl;
        return false;
    }
    index--; // 0始まりに補正
    try {
        auto& square = getSquare(index);
        if (square != e_SquareState::None) {
            std::cout << "既に書き込まれています" << std::endl;
            return false;
        }
        square = getSquareStateByCurrentPlayer();
        if(checkGameEnd()) {
            std::cout << "プレイヤー" << getCurrentTurnPlayer() + 1 << "の勝利です" << std::endl;
            return true;
        }
    } catch (std::out_of_range) {
        std::cout << "範囲外です" << std::endl;
        return false;
    }
    m_currentTurnPlayer = 1 - m_currentTurnPlayer;
    return false;
}

bool GameMgr::checkGameEnd() const
{
    for(int i = 0; i < m_board.size(); ++i) {
        // あるマスから右方向、下方向、右下方向、左下方向をチェック
        auto state = m_board[i];
        if (state == e_SquareState::None) continue;
        // 右
        if (i % m_width == 0) // 右方向に揃うのは左端のマスのみ
        {
            bool ok = true;
            for(int j = 1; j < m_width; ++j) {
                if (m_board[i + j] != state) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        // 下方向
        if (i < m_width) // 下方向に揃うのは上端のマスのみ
        {
            bool ok = true;
            for(int j = 1; j < m_height; ++j) {
                if (m_board[i + m_width * j] != state) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        if (m_width != m_height) {
            continue; // ボードが正方形ではない場合は斜め無し
        }
        // 右下方向
        if (i == 0) // 右下方向に揃うには左上のマスのみ
        {
            bool ok = true;
            for(int j = 1; j < m_width; ++j) {
                if (m_board[i + ( m_width + 1) * j] != state) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        // 左下方向
        if (i == m_width - 1) // 左下方向に揃うには右上のマスのみ
        {
            bool ok = true;
            for(int j = 1; j < m_width; ++j) {
                if (m_board[i + ( m_width - 1) * j] != state) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
    }
    return false;
}
