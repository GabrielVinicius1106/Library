#include <stdlib.h>
#include <time.h>

#include "utils.h"

int randomID(){

    srand(time(NULL));

    return (rand() % 100);
}