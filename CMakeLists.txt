# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)
# プロジェクト名と使用する言語を設定
project(marubatsu CXX)
# a.outという実行ファイルを指定したcppファイルから作成
add_executable(a.out marubatsu.cpp MainLoopMgr.cpp GameMgr.cpp e_SquareState.cpp)