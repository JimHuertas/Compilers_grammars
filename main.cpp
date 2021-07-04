#include "read_grammar.h"
#include "analisIs_cadena.h"
#include <queue>
#include <stack>

int main(){
    char word[50];
    char *ptr = word;
    vector<Production*> todos;

    Grammar gramatica;
    string input_1 = "id + id";
    string input_2 = "( id + id )";
    string input_3 = "( id + id ) + id";
    string input_4 = "id + id +";
    string input_5 = "( id + id";

    //lectura del input.txt
    while(cin.getline(word,50,'\n')){
        lectura(ptr, gramatica);
    }

    /**
     * PRIMEROS
    */
    string izq[]={"E", "T", "E'", "T'", "F"};

    for(int i=0; i<5; i++){
        cout<<"Primero ("<<izq[i]<<"): "<<endl;
        vector<string> gra2 = gramatica.getPrimeros(izq[i]);
        for(int j=0; j<gra2.size(); j++){
            cout<<gra2[j]<<"  ";
        }cout<<endl;
    }
    
    /**
     * SIGUIENTES
    */

    for(int i=0; i<5; i++){
        cout<<"Siguiente ("<<izq[i]<<"): "<<endl;
        vector<string> gra2 = gramatica.getSiguientes(izq[i]);
        for(int j=0; j<gra2.size(); j++){
            cout<<gra2[j]<<"  ";
        }cout<<endl;
    }

    
    //para "id + id"
    if(analiza(input_1, gramatica)){
        cout<<"Si pertenece a la gramatica\n"<<endl;
    } else{
        cout<<"No Pertenece a la gramatica\n"<<endl;
    }

    //para "id + id +"
    if(analiza(input_2, gramatica)){
        cout<<"Si pertenece a la gramatica\n"<<endl;
    } else{
        cout<<"No Pertenece a la gramatica\n"<<endl;
    }

    //para "( id + id"
    if(analiza(input_3, gramatica)){
        cout<<"Si pertenece a la gramatica\n"<<endl;
    } else{
        cout<<"No Pertenece a la gramatica\n"<<endl;
    }

    //para "( id + id )"
    if(analiza(input_4, gramatica)){
        cout<<"Si pertenece a la gramatica\n"<<endl;
    } else{
        cout<<"No Pertenece a la gramatica\n"<<endl;
    }

    //para "( id + id )"
    if(analiza(input_5, gramatica)){
        cout<<"Si pertenece a la gramatica\n"<<endl;
    } else{
        cout<<"No Pertenece a la gramatica\n"<<endl;
    }




    return 0;
}