cmake_minimum_required(VERSION 3.20)
project(miniProjektv2)

set(CMAKE_CXX_STANDARD 23)

add_executable(miniProjektv2 main.cpp Problem.h Solution.h CMax3SatProblem.cpp CMax3SatProblem.h Klauzula.h CGAIndividual.cpp CGAIndividual.h CGAOptimizer.cpp CGAOptimizer.h Consts.h)
