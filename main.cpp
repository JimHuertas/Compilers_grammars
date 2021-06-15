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

    vector<string> gra2 = gramatica.getPrimeros("S");
    for(int i=0; i<gra2.size(); i++){
        cout<<gra2[i]<<"  ";
    }cout<<endl;

    return 0;
}