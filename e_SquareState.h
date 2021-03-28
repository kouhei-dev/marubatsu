#pragma once
// 1マスを表す
enum class e_SquareState
{
    None = 0,
    Maru,
    Batsu,
};

void drawSquareaState(e_SquareState state);
