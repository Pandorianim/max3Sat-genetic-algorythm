//
// Created by jansk on 06.01.2022.
//

#ifndef MINIPROJEKT2_CKLAUZULA_H
#define MINIPROJEKT2_CKLAUZULA_H
#include <string>


class CKlauzula {
private:
    bool w1;
    bool w2;
    bool w3;

    std::string index1;
    std::string index2;
    std::string index3;

    bool value;

public:
    CKlauzula(std::string x, std::string y, std::string z){
        index1=x;
        index2=y;
        index3=z;
    }

    bool computeKlauzula(){
        value=w1 || w2 || w3;
        return value;
    }

    bool getValue(){
        return value;
    }

    void setW1(bool w1) {
        CKlauzula::w1 = w1;
    }

    void setW2(bool w2) {
        CKlauzula::w2 = w2;
    }

    void setW3(bool w3) {
        CKlauzula::w3 = w3;
    }

    const std::string &getIndex1() const {
        return index1;
    }

    const std::string &getIndex2() const {
        return index2;
    }

    const std::string &getIndex3() const {
        return index3;
    }


};



#endif //MINIPROJEKT2_CKLAUZULA_H
