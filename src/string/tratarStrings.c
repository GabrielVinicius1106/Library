#include <stdlib.h>

void removerQuebraDeLinha(char *string, int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(string[i] == '\n'){
            string[i] = '\0';
        }
    }
}