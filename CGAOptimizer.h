//
// Created by jansk on 14.01.2022.
//

#ifndef MINIPROJEKTV2_CGAOPTIMIZER_H
#define MINIPROJEKTV2_CGAOPTIMIZER_H

#include "Solution.h"
#include "Problem.h"
#include "Consts.h"
#include <vector>
#include <iostream>

template <typename T>
class CGAOptimizer {
public:
    CGAOptimizer ( Problem * nProblem,  int nSize, int npKrzyzowania, int npMutacji){
        if(Solution * test=dynamic_cast<Solution*>(rozwiazania);test!= nullptr){
            problem=nProblem;
            size=nSize;
            pKrzyzowania=npKrzyzowania;
            pMutacji=npMutacji;
            for(int i=0;i<size;i++) {
                osobniczki.push_back(new T());
                problem->computeProblem(osobniczki[i]);
            }

        }else{
            std::cout << WRONGTYPE << std::endl;
        }


    }

    ~CGAOptimizer(){
        delete rozwiazania;
        for(int i=0;i<osobniczki.size();i++){
            delete osobniczki.at(i);
        }

        for(int i=0;i<noweOsobniczki.size();i++){
            delete noweOsobniczki.at(i);
        }
    }

    void initialize() {
        if (Solution *test = dynamic_cast<Solution *>(rozwiazania);test != nullptr) {

            osobniczki.clear();
            noweOsobniczki.clear();
            for (int i = 0; i < size; i++) {
                osobniczki.push_back(new T());
                problem->computeProblem(osobniczki[i]);
            }

        } else {
            std::cout << WRONGTYPE << std::endl;
        }
    }


    std::vector<Solution*> getDefault(){
        return osobniczki;
    }

   Solution* runIteration(){
        Solution * absoluteChad=new T();
        int maxFitness=0;

        Solution * rodzic1;
        Solution * rodzic2;
        Solution * dziecko1;
        Solution * dziecko2;
        bool ** dzieci;

        int czyKrzyzuje;

        while(osobniczki.size()>=noweOsobniczki.size()){
            rodzic1= wybierzRodzica(3);
            rodzic2= wybierzRodzica(3);

            while(rodzic1==rodzic2){
                rodzic1= wybierzRodzica(3);
            }

            czyKrzyzuje=rand()%ILEPROCENT;
            if(pKrzyzowania<czyKrzyzuje){
                dzieci= rodzic1->crossover(rodzic2);

                dziecko1= new T(dzieci[0]);
                dziecko2= new T(dzieci[1]);

                dziecko1->mutation(pMutacji);
                dziecko2->mutation(pMutacji);

            }else{
                dziecko1=new T(rodzic1->getGenotyp());
                dziecko2=new T(rodzic2->getGenotyp());
            }

            problem->computeProblem(dziecko1);
            problem->computeProblem(dziecko2);


            noweOsobniczki.push_back(dziecko1);
            noweOsobniczki.push_back(dziecko2);

        }
        delete dzieci[0];
        delete dzieci[1];
        delete dzieci;

        delete rodzic1;
        delete rodzic2;
        delete dziecko1;
        delete dziecko2;


        for(int k=0;k<size;k++){
            if(noweOsobniczki[k]->getFitness()>maxFitness){
                maxFitness=noweOsobniczki[k]->getFitness();
                absoluteChad=noweOsobniczki[k];
            }
        }
        return absoluteChad;
    }


    std::vector<Solution*> getWynik(){
        return noweOsobniczki;
    }

private:
    int size;
    int pKrzyzowania;
    int pMutacji;


    Problem* problem;

    std::vector<Solution*>  osobniczki;
    std::vector<Solution*>  noweOsobniczki;

    T * rozwiazania=new T();


    Solution * wybierzRodzica(int turniejSize){
        Solution * rodzic;
        int maxFitness=0;
        int randomIndex;
        int * juzByli=new int[turniejSize];


        int flag=0;
        for(int i=0;i<turniejSize;i++){
            randomIndex=rand()%size;
            for(int j=0;j<turniejSize && !flag;j++){
                flag = (randomIndex==juzByli[j]);
            }
            if(!flag){
                if(osobniczki[randomIndex]->getFitness()> maxFitness){
                    rodzic=osobniczki[randomIndex];
                }
            }

            flag=0;
        }
        delete juzByli;
        return rodzic;
    };
};


#endif //MINIPROJEKTV2_CGAOPTIMIZER_H
