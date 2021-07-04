#ifndef GRAMMAR_H
#define GRAMMAR_H
#include "production.h"

bool estaEnElVector(vector<string> vec, string izq){
    for(int i=0; i<vec.size(); i++)
        if(vec[i] == izq)
            return true;
    return false;
}


void eliminar(vector<string> &prod, string state){
    bool find = false;
    for(int i=0; i<prod.size(); i++){
        if(prod[i] == state)
            find = true;
        if(find && i!= prod.size()-1)
            prod[i]=prod[i+1];
    }
    if(find){prod.pop_back();}
}

void agregar(vector<string> &siguientes, vector<string> &vec2){
    for(int j=0; j<vec2.size(); j++)
        if(!estaEnElVector(siguientes, vec2[j]))
            siguientes.push_back(vec2[j]);
}

int reglas(Production prod, string state){
    vector<string> derecha = prod.getProductions();
    if(prod.getIzquierda() == state){return 0;}
    else if(derecha[0] == state && derecha.size()==1){return 3;}
    
    for(int i=0; i<derecha.size();i++){
        if(derecha[i] == state && i!=derecha.size()-1) 
            return i+1;
    }

    if(derecha[derecha.size()-1] == state)
        return 3;
    return 0;
}

class Grammar{
private:
    vector<Production> productions;
public:
    Grammar(){}
    Grammar(vector<Production> );
    ~Grammar();
    int getSize() {return productions.size();}
    void addNewGrammar(Production);
    vector<string> getProductions(int);
    vector<string> getPrimeros(string);
    vector<string> getSiguientes(string);
    string getInicial(){ return productions[0].getIzquierda();}
    vector<string> getAllProductions(string izq){
        vector<string> a;
        for(int i=0; i<productions.size(); i++)
            if(productions[i].getIzquierda() == izq)
                return productions[i].getProductions();
        return a;
    }
    vector<string> getAllProductions(string izq, string nt){
        vector<string> a;
        for(int i=0; i<productions.size(); i++)
            if(productions[i].getIzquierda() == izq && productions[i].getProductions()[0] == nt)
                return productions[i].getProductions();
        return a;
    }
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
            if(grammar[j] == izq && !estaEnElVector(nt, izq)) 
                nt.push_back(grammar[j]);
        }
    }
    
    return nt;
}

vector<string> Grammar::getPrimeros(string txt){
    vector<string> primeros;
    for(int i=0; i<productions.size(); i++){
        if(productions[i].getIzquierda() == txt){
            if(productions[i].getInicial() != txt && !esTerminal(productions[i].getInicial()))
                primeros.push_back(productions[i].getInicial());
            else if(productions[i].getInicial() == txt)
                continue;
            else if(esTerminal(productions[i].getInicial()))
                return getPrimeros(productions[i].getInicial());
        }
    }
    if(primeros.size() == 0){ primeros.push_back(txt);}
    return primeros;
}

vector<string> Grammar::getSiguientes(string txt){
    vector<string> siguientes;
    if(productions[0].getIzquierda() == txt){
        siguientes.push_back("$");
    }
    for(int i=0; i<productions.size(); i++){
        if(estaEnElVector(productions[i].getProductions(), txt)){
            int regla = reglas(productions[i], txt);
            if(regla != 0 && regla != 3){
                string prod = productions[i].getProductions()[regla];
                vector<string> aux = getPrimeros(prod);
                if(estaEnElVector(aux, "\'\'")){
                    eliminar(aux, "\'\'");
                    string prod = productions[i].getIzquierda();
                    vector<string> aux = getSiguientes(prod);
                    agregar(siguientes, aux);
                }
                agregar(siguientes, aux);
            }
            else if(regla == 3){
                string prod = productions[i].getIzquierda();
                vector<string> aux = getSiguientes(prod);
                agregar(siguientes, aux);
            }
        }
    }
    return siguientes;
} 

bool Grammar::esTerminal(string txt){
    for(int i=0; i<productions.size(); i++)
        if(productions[i].getIzquierda() == txt)
            return true;
    return false;
}

#endif
