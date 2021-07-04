#ifndef ANALISIS_CADENA_H
#define ALALISIS_CADENA_H
#include "tas.h"
#include <stack>
#include <queue>

void agregarCadena(queue<string> &cola, string &cadena){
    int start =0;
    int end =0;
    while(end < cadena.size()){
        end = cadena.find_first_of(' ',start);
        if(end == -1){end = cadena.size();}
        string txt = cadena.substr(start, end-start);
        cola.push(txt);
        start = end+1;
    }
    cola.push("$");
}

void agregarPila(stack<string> &pila, vector<string> &prods){
    for(int i=prods.size()-1; i>=0; i--)
        pila.push(prods[i]);
}

bool analiza(string cadena, Grammar gramatica){
    queue<string> entrada; //cola
    stack<string> pila; //pila
    pila.push("$");

    pila.push(gramatica.getInicial());
    agregarCadena(entrada, cadena);

    while(!pila.empty() && !entrada.empty()){
        cout<<"Pila: "<<pila.top()<<"         Entrada: "<<entrada.front()<<endl;
        if(pila.top() == entrada.front()){
            entrada.pop();
            pila.pop();
        } else {
            vector<string> paraPila = tas(gramatica, pila.top(), entrada.front());
            if(paraPila.size()==0){ return false; }
            else if(!gramatica.esTerminal(paraPila[0]) && paraPila[0]!= "\'\'"){
                paraPila = gramatica.getAllProductions(pila.top(), entrada.front());
            }
            if(paraPila.size()==0){ return false; }
            else{
                pila.pop();
                agregarPila(pila, paraPila); 
            }
            if(pila.top() == "\'\'"){pila.pop();}
        }
    }

    return true;
}


#endif