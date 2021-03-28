#include "e_SquareState.h"
#include <iostream>
#include <cassert>

void drawSquareaState(e_SquareState state)
{
    char c;
    switch (state)
    {
    case e_SquareState::None:
        c = '-';
        break;
    case e_SquareState::Maru:
        c = 'o';
        break;
    case e_SquareState::Batsu:
        c = 'x';
        break;
    default:
        assert(false);
    }
    std::cout << c;
}
