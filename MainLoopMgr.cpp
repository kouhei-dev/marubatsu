#include <cstdlib> // system
#include "MainLoopMgr.h"
#include "GameMgr.h"

void clearConsole() {
	system("clear");
}

// static
MainLoopMgr& MainLoopMgr::getInstance() {
    static MainLoopMgr instance;
    return instance;
}

void MainLoopMgr::run() {
    GameMgr gameMgr;
    while (!m_bGameEnd)
    {
        clearConsole();
        gameMgr.draw();
        auto inputLine = input();
        if (inputLine != "") {
            if (gameMgr.update(inputLine)) {
                m_bGameEnd = true;
                break;
            }
        }
    }
}

std::string MainLoopMgr::input()
{
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.eof()) { // ctrl + Dで強制終了
        std::cout << "ゲームを強制終了します" << std::endl;
        m_bGameEnd = true;
        return "";
    }
    return line;
}
