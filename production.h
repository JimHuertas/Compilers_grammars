#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <iostream>
#include <vector>
using namespace std;

class Production{
private:
    int production_cant;
    vector<string> productions;
    string izquierda;
public:
    Production();
    Production(int, vector<string>);
    ~Production();
    vector<string> getProductions(){ return productions; }
    int getCantProductions(){ return production_cant; }
};

Production::Production(){}
Production::Production(int cant, vector<string> content){
    this->production_cant = cant;
    this->productions = content;
}

Production::~Production(){
}


#endif







//Production aux;
//... aux = productions.getProductions()[1];

