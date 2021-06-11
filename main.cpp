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


    return 0;
}