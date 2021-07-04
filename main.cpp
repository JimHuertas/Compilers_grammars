#include "read_grammar.h"
#include "analisIs_cadena.h"
#include <queue>
#include <stack>

int main(){
    char word[50];
    char *ptr = word;
    vector<Production*> todos;

    Grammar gramatica;
    string input = "id + id";

    while(cin.getline(word,50,'\n')){
        lectura(ptr, gramatica);
    }

    if(analiza(input, gramatica)){
        cout<<"Si pertenece a la gramatica"<<endl;
    } else{
        cout<<"No Pertenece a la gramatica"<<endl;
    }



    /*string izq[]={"E", "T", "E'", "T'", "F"};

    for(int i=0; i<5; i++){
        cout<<"Primero ("<<izq[i]<<"): "<<endl;
        vector<string> gra2 = gramatica.getSiguientes(izq[i]);
        for(int j=0; j<gra2.size(); j++){
            cout<<gra2[j]<<"  ";
        }cout<<endl;
    }*/
    


    return 0;
}