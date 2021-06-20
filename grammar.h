#ifndef GRAMMAR_H
#define GRAMMAR_H
#include "production.h"

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

void agregar(vector<string> &vec1, vector<string> &vec2){
    for(int i=0; i<vec2.size(); i++)
        vec1.push_back(vec2[i]);
}

int reglas(vector<string> prod, string state){
    if(prod.size()==2 && prod[prod.size()-1] == state)
        return 3;
    else if(prod.size()==3 && prod[prod.size()-2] == state)
        return 2;
    return 0;
}

bool estaEnElVector(vector<string> vec, string izq){
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
    int getSize() {return productions.size();}
    void addNewGrammar(Production);
    vector<string> getProductions(int);
    vector<string> getPrimeros(string);
    vector<string> getSiguientes(string);
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
            if(productions[i].getPrimero() != txt && !esTerminal(productions[i].getPrimero()))
                primeros.push_back(productions[i].getPrimero());
            else if(productions[i].getPrimero() == txt)
                continue;
            else if(esTerminal(productions[i].getPrimero()))
                return getPrimeros(productions[i].getPrimero());
        }
    }
    if(primeros.size() == 0){ primeros.push_back(txt);}
    return primeros;
}

vector<string> Grammar::getSiguientes(string txt){
    cout<<"Production: "<<txt<<endl;
    vector<string> siguientes;
    if(productions[0].getIzquierda() == txt){
        cout<<"entro"<<endl;
        siguientes.push_back("$");
    }
    for(int i=0; i<productions.size(); i++){
        if(estaEnElVector(productions[i].getProductions(), txt)){
            if(reglas(productions[i].getProductions(), txt) == 2){
                cout<<"cumplio regla 3 ->"<<txt<<endl;
                string prod = productions[i].getProductions()[2];
                vector<string> aux = getPrimeros(prod);
                if(estaEnElVector(aux, "\'")){
                    eliminar(aux, "\'");
                    string prod = productions[i].getIzquierda();
                    vector<string> aux = getSiguientes(prod);
                    agregar(siguientes, aux);
                }
                agregar(siguientes, aux);
            }
            else if(reglas(productions[i].getProductions(), txt) == 3){
                cout<<"cumplio regla 2 ->"<<txt<<endl;
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
