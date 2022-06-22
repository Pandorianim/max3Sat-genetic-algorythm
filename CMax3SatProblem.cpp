
// Created by jansk on 12.01.2022.
//

#include "CMax3SatProblem.h"

bool CMax3SatProblem::loadProblem(std::string filename) {
    std::fstream fs(filename, std::fstream::in);
    if(fs.is_open()){
        std::string temp1, temp2, temp3;
        char nawias;
        while(fs.good()){

            fs >> nawias;

            if(nawias!='('){
                fs.setstate(std::ios::failbit);
                return true;
            }

            fs >> temp1;

            fs >> temp2;

            fs >> temp3;

            klauzule.push_back(CKlauzula(temp1, temp2, temp3));

            fs >> nawias;

            if(nawias!=')'){
                fs.setstate(std::ios::failbit);
                return true;
            }


        }
    }
    return false;
}

void CMax3SatProblem::computeProblem(Solution * individual) {
    int licznik=0;
    bool * genotyp=individual->getGenotyp();

    for(int i=0;i<klauzule.size();i++) {
        if(klauzule[i].getIndex1()=="-0"){
            klauzule[i].setW1(!genotyp[0]);
        }else{
            int w1Int=stoi(klauzule[i].getIndex1());
            if(w1Int<0){
                klauzule[i].setW1(!genotyp[-w1Int]);
            }else{
                klauzule[i].setW1(genotyp[w1Int]);
            }
        }

        if(klauzule[i].getIndex2()=="-0"){
            klauzule[i].setW2(!genotyp[0]);
        }else{
            int w2Int=stoi(klauzule[i].getIndex2());
            if(w2Int<0){
                klauzule[i].setW2(!genotyp[-w2Int]);
            }else{
                klauzule[i].setW2(genotyp[w2Int]);
            }
        }

        if(klauzule[i].getIndex3()=="-0"){
            klauzule[i].setW3(!genotyp[0]);
        }else{
            int w3Int=stoi(klauzule[i].getIndex3());
            if(w3Int<0){
                klauzule[i].setW3(!genotyp[-w3Int]);
            }else{
                klauzule[i].setW3(genotyp[w3Int]);
            }
        }
        if(klauzule[i].computeKlauzula()==true){
            licznik++;
        }

    }
    individual->setFitness(licznik);
}
