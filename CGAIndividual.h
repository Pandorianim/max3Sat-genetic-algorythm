//
// Created by jansk on 12.01.2022.
//

#ifndef MINIPROJEKTV2_CGAINDIVIDUAL_H
#define MINIPROJEKTV2_CGAINDIVIDUAL_H


#include "CMax3SatProblem.h"
#include "Solution.h"
#include <random>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <initializer_list>
class CGAIndividual: public Solution {
private:

    bool* genotyp;
    int fitness;
public:
    CGAIndividual(bool value){
        genotyp=new bool[PROBLEMSIZE];
        for(int i=0;i<PROBLEMSIZE;i++){

            genotyp[i]=value;
        }
    }

    CGAIndividual(){
        genotyp=new bool[PROBLEMSIZE];
        for(int i=0;i<PROBLEMSIZE;i++){
            genotyp[i]=0 + (rand() % 2);
        }
    }


    CGAIndividual(bool* newGen){
        genotyp=new bool[PROBLEMSIZE];
        for(int i=0;i<PROBLEMSIZE;i++){
            genotyp[i]=newGen[i];
        }
    }

    CGAIndividual(CGAIndividual * other){
        fitness=other->fitness;
        genotyp=new bool[PROBLEMSIZE];
        for(int i=0;i<PROBLEMSIZE;i++){
            genotyp[i]=other->genotyp[i];
        }
    }

    ~CGAIndividual(){
        delete genotyp;
    }

    bool *getGenotyp() override;

    int getFitness() override;

    void setFitness(int fitness) override;

    bool **crossover(Solution * other) override;

    void mutation(int probability) override;


};
#endif //MINIPROJEKTV2_CGAINDIVIDUAL_H
