#ifndef GRAMMAR_H
#define GRAMMAR_H
#include "production.h"

bool repetido(vector<string> vec, string izq){
        for(int i=0; i<vec.size(); i++)
            if(vec[i] == izq)
                return true;
        return false;
}

class Grammar{
private:
    vector<Production> productions;
public:
    Grammar(){}
    Grammar(vector<Production> );
    ~Grammar();
    void addNewGrammar(Production);
    vector<string> getProductions(int);
    vector<string> getPrimeros(string);
    bool esTerminal(string);

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
        for(int j=0; j<grammar.size(); j++){
            if(grammar[j] == izq && !repetido(nt, izq)) 
                nt.push_back(grammar[j]);
        }
    }
    
    return nt;
}

vector<string> Grammar::getPrimeros(string txt){
    vector<string> primeros;
    for(int i=0; i<productions.size(); i++){
        if(productions[i].getIzquierda() == txt){
            if(productions[i].getPrimero() != txt && !esTerminal(productions[i].getPrimero()))
                primeros.push_back(productions[i].getPrimero());
            else if(productions[i].getPrimero() == txt)
                continue;
            else if(esTerminal(productions[i].getPrimero()))
                return getPrimeros(productions[i].getPrimero());
        }
    }

    return primeros;
}

bool Grammar::esTerminal(string txt){
    for(int i=0; i<productions.size(); i++)
        if(productions[i].getIzquierda() == txt)
            return true;
    return false;
}

#endif
