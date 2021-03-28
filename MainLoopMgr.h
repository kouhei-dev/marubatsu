#pragma once
#include <iostream>
#include <string>

class MainLoopMgr
{
public:
	static MainLoopMgr& getInstance();
	void run();

private:
	std::string input();
	MainLoopMgr() = default;
	bool m_bGameEnd = false;
};
