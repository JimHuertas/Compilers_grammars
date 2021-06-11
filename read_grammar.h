#ifndef LECTURA_GRAMMAR_H
#define LECTURA_GRAMMAR_H
#include "production.h"

string toString(char *&ptr){
    string txt;
    while(*ptr != '>' && *ptr != '\"'){
        txt+=*ptr;
        ptr++;
    }
    ptr++;
    return txt;
}

void printProductions(vector<string> prod){
    for(int i=0; i<prod.size(); i++){
        cout<<prod[i]<<endl;
    }
}


void lectura(char *ptr, vector<Production*> &total_prod){
    int cont=0;
    vector<vector<string>> produc;
    string aux;
    while(*ptr != '\0'){
        cout<<"ENTRO AL WHILE: "<<*ptr<<endl;
        vector<string> unique_prod;
        if(*ptr == '<'){
            ptr++;
            aux = toString(ptr);
            cout<<aux<<" - Tambien el ptr esta en: \""<<*(ptr+1)<<"\""<<endl;
        } else if((*ptr == ':' && *(ptr+1)==':') || *(ptr-1)== '|'){
            cout<<"Cumplio ::"<<endl;
            while(*ptr != '\0'){
                cout<<"entro al 2do while   -  "<<*ptr<<endl;
                if(*ptr == '<' || *ptr == '\"'){
                    ptr++;
                    aux = toString(ptr);
                    unique_prod.push_back(aux);
                    cont++;
                    cout<<"Production: "<<aux<<endl;
                }
                else if(*ptr == '|'){
                    cout<<"encontro un | mira -> "<<*ptr<<endl;
                    produc.push_back(unique_prod);
                    break;
                }
                if(*ptr=='\0'){break;}//verificación 1
                ptr++; 
            }
        }
        if(*ptr=='\0'){break;}//verificación 2
        ptr++;
    }

    for(int k=0; k<produc.size(); k++){
        cout<<"Entro al for :o"<<endl;
        Production aux(produc[k].size(), produc[k]);
        Production *ptr = &aux;
        total_prod.push_back(ptr);
        printProductions(produc[k]);
    }

    cout<<endl<<endl<<endl;
}


#endif
