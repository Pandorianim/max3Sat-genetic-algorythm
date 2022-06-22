//
// Created by jansk on 12.01.2022.
//

#ifndef MINIPROJEKTV2_PROBLEM_H
#define MINIPROJEKTV2_PROBLEM_H

#include "Solution.h"
#include <string>
class Problem {
public:
    virtual bool loadProblem(std::string filename)=0;
    virtual void computeProblem(Solution * individual)=0;
};
#endif //MINIPROJEKTV2_PROBLEM_H
