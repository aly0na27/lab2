#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "s2.h"

int s2(char* a) {
    if (a[0] == '-') {
        for (int i = 1; i < strlen(a); i++) {
            if (a[i] != '0' && a[i] != '1') {
                return 0;
            }
         }
         return -1;
    }
    else {
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] != '0' && a[i] != '1') {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
int s2_10(char* a) {
    int res = 0;
    if (a[0] != '-') {
        for (int i = 0; i < strlen(a); i++) {
            res += ((int)a[i] - 48) * pow(2, strlen(a)-i-1);
        }
    }
    else {
        for (int i = 1; i < strlen(a); i++) {
            res += ((int)a[i] - 48) * pow(2, strlen(a)-i-1);
        }
        res *= (-1);
    }
    return res;
}
char* s10_2(int a) {
    char* a2_copy = calloc(sizeof(char), 1);
    int abs_a = abs(a);
    while (abs_a > 0) {
        int p = abs_a % 2;
        if (p == 1) {
            a2_copy[strlen(a2_copy)] = '1';
        }
        else {
            a2_copy[strlen(a2_copy)] = '0';
        }
        a2_copy = realloc(a2_copy, sizeof(a2_copy)+sizeof(char));
        abs_a = abs_a / 2;
    }
    if (a < 0) {
        a2_copy[strlen(a2_copy)] = '-';
   
        for (int i = 0; i < strlen(a2_copy)/2; i++) {
            char p = a2_copy[i];
            a2_copy[i] = a2_copy[strlen(a2_copy)-i-1];
            a2_copy[strlen(a2_copy)-i-1] = p;
        }
    }
    else { 
        for (int i = 0; i < strlen(a2_copy)/2; i++) {
            char p = a2_copy[i];
            a2_copy[i] = a2_copy[strlen(a2_copy)-i-1];
            a2_copy[strlen(a2_copy)-i-1] = p;
        }
    }           
    return a2_copy;
}

