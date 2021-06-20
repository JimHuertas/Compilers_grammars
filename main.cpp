#include "read_grammar.h"

int main(){
    char word[50];
    char *ptr = word;
    vector<Production*> todos;

    Grammar gramatica;
    string input = "2 + 3 * 4";

    while(cin.getline(word,50,'\n')){
        lectura(ptr, gramatica);
    }

    /*vector<string> gra = gramatica.getProductions(2);
    for(int i=0; i<gra.size(); i++){
        cout<<gra[i]<<"  ";
    }cout<<endl;*/



        cout<<"Primero (E): "<<endl;
        vector<string> gra2 = gramatica.getSiguientes("F");
        for(int j=0; j<gra2.size(); j++){
            cout<<gra2[j]<<"  ";
        }cout<<endl;


    return 0;
}