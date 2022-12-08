#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "s8.h"

int s8(char* a) {
    if (a[0] == '-') {
        if (a[1] == '0') {
            for (int i = 2; i < strlen(a); i++) {
                if ((int)a[i]<48 || (int)a[i]>55) {
                    return 0;
                }
            }
            return -1;
        }
        return 0;
    }
    else {
        if (a[0] == '0') {
            for (int i = 1; i < strlen(a); i++) {
                if ((int)a[i]<48 || (int)a[i]>55) {
                    return 0;
                }
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
int s8_10(char* a) {
    int res = 0;
    if (a[0] == '-') {
        for (int i = 2; i < strlen(a); i++) {
            res += ((int)a[i]-48) * pow(8, strlen(a)-i-1);
        }
        res *= (-1);
    }
    else {
        for (int i = 1; i < strlen(a); i++) {
            res += ((int)a[i]-48) * pow(8, strlen(a)-i-1);
        }
    }
    return res;
}
char* s10_8(int a) {
    char* a8_copy = calloc(sizeof(char), 1);
    int abs_a = abs(a);
    while (abs_a > 0) {
        a8_copy[strlen(a8_copy)] = (abs_a % 8) + '0';
        a8_copy = realloc(a8_copy, sizeof(a8_copy)+sizeof(char));
        abs_a = abs_a / 8;
    }
    if (a < 0) {
        a8_copy[strlen(a8_copy)] = '0';
        a8_copy = realloc(a8_copy, sizeof(a8_copy)+sizeof(char));
        a8_copy[strlen(a8_copy)] = '-';
        char* a8_rev = calloc(sizeof(char), strlen(a8_copy)); 
        for (int i = 0; i < strlen(a8_copy); i++) {
            a8_rev[i] = a8_copy[strlen(a8_copy)-i-1];
        }
        free(a8_copy);
        return a8_rev;
    }
    else {
        a8_copy[strlen(a8_copy)] = '0';
        char* a8_rev = calloc(sizeof(char), strlen(a8_copy)); 
        a8_rev[0] = '0';
        for (int i = 0; i < strlen(a8_copy); i++) {
            a8_rev[i] = a8_copy[strlen(a8_copy)-i-1];
        }
        free(a8_copy);
        return a8_rev;
    }
}

