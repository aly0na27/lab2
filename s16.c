#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "s16.h"

int s16(char* a) {
    if (a[0] == '-' && a[1] == '0' && a[2] == 'x') {
        for (int i = 3; i < strlen(a); i++) {
            if (((int)a[i] < 48) || ((int)a[i] > 57 && (int)a[i] < 97) || ((int)a[i] > 102)) {
                return 0;
            }
        }
        return -1;
    }
    else if (a[0] == '0' && a[1] == 'x') {
        for (int i = 2; i < strlen(a); i++) {
            if (((int)a[i] < 48) || ((int)a[i] > 57 && (int)a[i] < 97) || ((int)a[i] > 102)) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
int s16_10(char* a) {
    int res = 0;
    if (a[0] == '-') {
        for (int i = 3; i < strlen(a); i++) {
            if ((int)a[i] >= 48 && (int)a[i] <= 57) {
                res <<= 4;
                res += (int)a[i] - 48;
            }
            else if (a[i] == 'a') {
                res <<= 4;
                res += 10;
            }
            else if (a[i] == 'b') {
                res <<= 4;
                res += 11;
            }
            else if (a[i] == 'c') {
                res <<= 4;
                res += 12;
            }
            else if (a[i] == 'd') {
                res <<= 4;
                res += 13;
            }
            else if (a[i] == 'e') {
                res <<= 4;
                res += 14;
            }
            else if (a[i] == 'f') {
                res <<= 4;
                res += 15;
            }
        }
        res *= (-1);
    }
    else {
        for (int i = 2; i < strlen(a); i++) {
            if ((int)a[i] >= 48 && (int)a[i] <= 57) {
                res <<= 4;
                res += (int)a[i] - 48;
            }
            else if (a[i] == 'a') {
                res <<= 4;
                res += 10;
            }
            else if (a[i] == 'b') {
                res <<= 4;
                res += 11;
            }
            else if (a[i] == 'c') {
                res <<= 4;
                res += 12;
            }
            else if (a[i] == 'd') {
                res <<= 4;
                res += 13;
            }
            else if (a[i] == 'e') {
                res <<= 4;
                res += 14;
            }
            else if (a[i] == 'f') {
                res <<= 4;
                res += 15;
            }
        }
    }
    return res;
}
char* s10_16(int a) {
    char* a16_copy = calloc(sizeof(char), 1);
    int a_abs = abs(a);
    while (a_abs > 0) {
        char ost;
        if (a_abs % 16 == 10) {
            ost = 'a';
        }
        else if (a_abs % 16 == 11) {
            ost = 'b';
        }
        else if (a_abs % 16 == 12) {
            ost = 'c';
        }
        else if (a_abs % 16 == 13) {
            ost = 'd';
        }
        else if (a_abs % 16 == 14) {
            ost = 'e';
        }
        else if (a_abs % 16 == 15) {
            ost = 'f';
        }
        else {
            ost = (a_abs % 16) + '0';
        }
        a16_copy[strlen(a16_copy)] = ost;
        a16_copy = realloc(a16_copy, sizeof(a16_copy)+sizeof(char));
        a_abs = a_abs / 16;
    }
    if (a < 0) {
        a16_copy[strlen(a16_copy)] = 'x';
        a16_copy = realloc(a16_copy, sizeof(a16_copy)+2*sizeof(char));
        a16_copy[strlen(a16_copy)] = '0';
        a16_copy[strlen(a16_copy)] = '-';
        char* a16_rev = calloc(sizeof(char), strlen(a16_copy));
        for (int i = 0; i < strlen(a16_copy); i++) {
            a16_rev[i] = a16_copy[strlen(a16_copy)-i-1];
        }
        free(a16_copy);
        return a16_rev;
    }
    else if (a == 0) {
        a16_copy[strlen(a16_copy)] = '0';
        a16_copy = realloc(a16_copy, sizeof(a16_copy)+2*sizeof(char));
        a16_copy[strlen(a16_copy)] = 'x';
        a16_copy[strlen(a16_copy)] = '0';
        return a16_copy;
    }
    else {
        a16_copy[strlen(a16_copy)] = 'x';
        a16_copy = realloc(a16_copy, sizeof(a16_copy)+sizeof(char));
        a16_copy[strlen(a16_copy)] = '0';
        char* a16_rev = calloc(sizeof(char), strlen(a16_copy));
        for (int i = 0; i < strlen(a16_copy); i++) {
            a16_rev[i] = a16_copy[strlen(a16_copy)-i-1];
        }
        free(a16_copy);
        return a16_rev;
    }
}

