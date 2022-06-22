//
// Created by jansk on 12.01.2022.
//

#ifndef MINIPROJEKTV2_SOLUTION_H
#define MINIPROJEKTV2_SOLUTION_H
#include <iostream>
class Solution {
public:
    virtual bool* getGenotyp()=0;
    virtual int getFitness()=0;
    virtual void setFitness(int fitness)=0;
    virtual bool ** crossover (Solution * other)=0;
    virtual void mutation (int probability)=0;
};
#endif //MINIPROJEKTV2_SOLUTION_H
