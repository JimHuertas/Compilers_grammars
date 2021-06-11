#ifndef GRAMMAR_H
#define GRAMMAR_H
#include "production.h"
class Grammar{
private:
    vector<Production> productions;
public:
    Grammar(){}
    Grammar(vector<Production> );
    ~Grammar();
    void addNewGrammar(Production);
    vector<string> getProductions(int pos);
};

Grammar::Grammar(vector<Production> prods){
    this->productions = prods;
}

void Grammar::addNewGrammar(Production prod){
    this->productions.push_back(prod);
}

Grammar::~Grammar(){
}

vector<string> Grammar::getProductions(int pos){
    vector<string> grammar = productions[pos].getProductions();

    vector<string> nt;
    for(int i=0; i<productions.size(); i++){
        string izq = productions[i].getIzquierda();
        vector<string> prod = productions[i].getProductions();
        for(int j=0; j<grammar.size(); i++){
            if(grammar[j] == izq) 
                nt.push_back(prod[j]);
        }
    }
    
    return nt;
}

#endif
