#include <stdio.h>
#include "input.h"

int input(){
    char buffer[8];
    int valor;
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            
            // Tenta converter string para inteiro
            if (sscanf(buffer, "%d", &valor) == 1) {
                return valor;
            } else {
                return 0;
            }
        }
    }
}

