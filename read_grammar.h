#ifndef READ_GRAMMAR_H
#define READ_GRAMMAR_H
#include "grammar.h"
string toString(char *&ptr){
    string txt;
    while(*ptr != '>' && *ptr != '\"'){
        txt+=*ptr;
        ptr++;
    }
    ptr++;
    return txt;
}

void printProductions(vector<string> prod, string name){
    cout<<name<<" -> ";
    for(int i=0; i<prod.size(); i++){
        cout<<prod[i]<<"  ";
    }
    cout<<endl;
}


void lectura(char *ptr, Grammar &gramatica){
    int cont=0;
    vector<vector<string>> produc; 
    string aux;
    string izquierda;
    while(*ptr != '\0'){
        vector<string> unique_prod;
        if(*ptr == '<'){
            ptr++;
            izquierda = toString(ptr);
        } else if((*ptr == ':' && *(ptr+1)==':') || *(ptr-1)== '|'){
            while(*ptr != '\0'){
                if(*ptr == '<' || *ptr == '\"'){
                    ptr++;
                    aux = toString(ptr);
                    unique_prod.push_back(aux);
                    cont++;
                } else if(*ptr == '|'){
                    break;
                }
                if(*ptr=='\0'){break;}//verificación 1
                ptr++; 
            }
            produc.push_back(unique_prod);
        }
        if(*ptr=='\0'){break;}//verificación 2
        ptr++;  
    }

    for(int k=0; k<produc.size(); k++){
        Production aux_p(produc[k].size(), produc[k], izquierda);
        gramatica.addNewGrammar(aux_p);
        printProductions(aux_p.getProductions(), aux_p.getIzquierda());
    }
    cout<<endl;
}


#endif
