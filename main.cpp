#include "read_grammar.h"

int main(){
    char word[50];
    char *ptr = word;
    vector<Production*> todos;

    string input = "2 + 3 * 4";

    while(cin.getline(word,50,'\n')){
        lectura(ptr, todos);
    }


    return 0;
}