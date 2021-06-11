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
    Production(int, vector<string>, string);
    ~Production();
    vector<string> getProductions(){ return productions; }
    int getCantProductions(){ return production_cant; }
    string getIzquierda(){ return izquierda;}
};

Production::Production(){}
Production::Production(int cant, vector<string> content, string izq){
    this->production_cant = cant;
    this->productions = content;
    this->izquierda = izq;
}

Production::~Production(){
}


#endif







//Production aux;
//... aux = productions.getProductions()[1];

