
//
// Created by jansk on 06.01.2022.
//



#ifndef MINIPROJEKT2_CMAX3SATPROBLEM_H
#define MINIPROJEKT2_CMAX3SATPROBLEM_H

#include "Problem.h"
#include "Klauzula.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#define PROBLEMSIZE 50

class CMax3SatProblem: public Problem {
private:
    std::vector <CKlauzula> klauzule;

public:

    CMax3SatProblem(){
    }

    ~CMax3SatProblem(){
        klauzule.clear();
    }

    std::vector <CKlauzula> getKlauzule(){
        return klauzule;
    }

    bool loadProblem(std::string filename) override;

    void computeProblem(Solution * individual) override;


};


#endif //MINIPROJEKT2_CMAX3SATPROBLEM_H



