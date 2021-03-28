#include <iostream>
#include <string>

#include "MainLoopMgr.h"

int main(){
	MainLoopMgr::getInstance().run();
	return 0;
}
