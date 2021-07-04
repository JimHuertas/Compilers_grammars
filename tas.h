#ifndef TAS_H
#define TAS_H
#include "grammar.h"

vector<string> tas(Grammar &gramatica, string no_terminal, string terminal){
    vector<string> resultado;
    vector<string> firsts = gramatica.getPrimeros(no_terminal);

    bool vacio = false;
    for(int i=0; i<firsts.size(); i++){
        if(firsts[i] == terminal){
            return gramatica.getAllProductions(no_terminal);
        }
        else if(firsts[i] == "\'\'"){
            vacio = true;
        }
    }

    if(vacio){
        vector<string> follows = gramatica.getSiguientes(no_terminal);
        for(int j=0; j<follows.size(); j++){
            if(follows[j] == terminal){
                resultado.push_back("\'\'");
                return resultado; 
            }
        }        
    }

    return resultado;
}


#endif