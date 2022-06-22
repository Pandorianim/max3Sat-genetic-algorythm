#include <iostream>
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
#include "CGAOptimizer.h"

int main() {

    srand( time(NULL) );
    int ileOsobnikow=20;
    int ileSerii=3;

    CMax3SatProblem *problem=new CMax3SatProblem();
    problem->loadProblem("C:\\Users\\jansk\\CLionProjects\\miniProjekt\\max3dane\\50\\m3s_50_11.txt");

    CGAOptimizer<CGAIndividual>*  opt=new CGAOptimizer<CGAIndividual>(problem,ileOsobnikow, 50, 20);


    Solution* chad;

    for(int i=0;i<ileSerii;i++){
        opt->initialize();
        chad=opt->runIteration();
        std::cout << "Fitness najlepszego osobnika: "<< chad->getFitness() << std::endl << "A oto jego genotyp:\n";
        for(int j=0;j<PROBLEMSIZE;j++){
            std::cout << chad->getGenotyp()[j];
        }
        std::cout << "\nFitness pozostalych osobnikow "<< i+1 << " proby:\n";
        for(int j=0;j<ileOsobnikow;j++){
            std::cout << opt->getWynik()[j]->getFitness() << std::endl;
        }
    }
    delete chad;
    delete problem;







}
