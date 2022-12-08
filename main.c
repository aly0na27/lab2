#include <stdio.h>
#include <stdlib.h>
#include "s16.h"
#include "s8.h"
#include "s2.h"
#include "clac.h"
 
int main() {
    char* str = NULL;
    size_t len = 0;
    getline(&str, &len, stdin);
    s_calculator(str);
    free(str);   
    return 0;
}

