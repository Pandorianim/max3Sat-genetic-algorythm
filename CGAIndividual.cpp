//
// Created by jansk on 12.01.2022.
//

#include "CGAIndividual.h"
#include "Consts.h"

bool *CGAIndividual::getGenotyp() {
    return genotyp;
}

int CGAIndividual::getFitness() {
    return fitness;
}

void CGAIndividual::setFitness(int nFitness) {
    fitness=nFitness;
}


bool **CGAIndividual::crossover(Solution * other) {
    int randomIndex;
    bool **result=new bool* [ILEDZIECI];
    for(int i=0;i<2;i++){
        result[i]=new bool[PROBLEMSIZE];
    }
    for(int i=0;i<PROBLEMSIZE;i++){
        randomIndex=std::rand()%2;
        if(randomIndex==0){
            result[0][i]=genotyp[i];
            result[1][i]=other->getGenotyp()[i];
        }else {

            result[0][i]=other->getGenotyp()[i];
            result[1][i]=genotyp[i];
        }

    }

    return result;
}

void CGAIndividual::mutation(int probability){
    int randomVariable;
    for (int i=0;i<PROBLEMSIZE;i++){
        randomVariable=(std::rand()%ILEPROCENT);
        if(randomVariable<probability){
            genotyp[i]=!genotyp[i];
        }
    }
}
