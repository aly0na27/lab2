#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s16.h"
#include "s8.h"
#include "s2.h"
#include "clac.h"
int operation(char c, int a, int b) {
    int result = 0;
    switch (c) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '%':
            result = a % b;
            break;
        default:
            printf("Ошибка: неправильная операция\n");
            break;
    }
    return result;
}
int bin_operation(char c, int a, int b) {
    int result = 0;
    switch (c) {
        case '&':
            result = a & b;
            break;
        case '|':
            result = a | b;
            break;
        case '^':
            result = a ^ b;
            break;
        default:
            printf("Ошибка: неправильная операция\n");
            break;
    }
    return result;
}
void s_calculator(char* str) {
    char* num1 = calloc(sizeof(char), 1);
    char* num2 = calloc(sizeof(char), 1);
    char c;
    int f1 = 0, f2 = 0;
    for (int i = 0; i < strlen(str)-1; i++) {
        if (str[i] == ' ') {
            continue;
        }
        if ((str[i] == '+' || str[i] == '*' || str[i] == '%' || str[i] == '&' || str[i] == '|' ||  str[i] == '^') || (str[i] == '-' && str[i+1] == ' ')) {
            f1 = 1;
            c = str[i];
            continue;
        }
        if (str[i] == '~') {
            c = '~';
            f2 = 1;
            continue;
        }
        if (f2 == 1) {
            num1[strlen(num1)] = str[i];
            num1 = realloc(num1, sizeof(num1)+sizeof(char));
        }
        if (f1 == 0 && f2 != 1) {
            num1[strlen(num1)] = str[i];
            num1 = realloc(num1, sizeof(num1)+sizeof(char));
        }
        else if (f1 == 1 && f2 != 1) {
            num2[strlen(num2)] = str[i];
            num2 = realloc(num2, sizeof(num2)+sizeof(char));
        }
    }
    if (f1 == 1 && (c == '+' || c == '-' || c == '*' || c == '%')) {
        if (s2(num1) != 0 && s2(num2) != 0) {
            int int_num1 = s2_10(num1);
            int int_num2 = s2_10(num2);
            int res = operation(c, int_num1, int_num2);
            char* s = s10_2(res);
            printf("%s (%d)\n", s, res);
            free(s);
        }
        else if (s8(num1) != 0 && s8(num2) != 0) {
            int int_num1 = s8_10(num1);
            int int_num2 = s8_10(num2);
            int res = operation(c, int_num1, int_num2);
            char* s = s10_8(res);
            printf("%s (%d)\n", s, res);
            free(s);
        }
        else if (s16(num1) != 0 && s16(num2) != 0) {
            int int_num1 = s16_10(num1);
            int int_num2 = s16_10(num2);
            int res = operation(c, int_num1, int_num2);
            char* s = s10_16(res);
            printf("%s (%d)\n", s, res);
            free(s);
        }
        else {
            printf("Ошибка: проверьте системы счисления операндов\n");
        }
    }
    else if (f1 == 1 && (c == '&' || c == '|' || c == '^')) {
        if (s2(num1) == 1 && s2(num2) == 1) {
            int int_num1 = s2_10(num1);
            int int_num2 = s2_10(num2);
            int res = bin_operation(c, int_num1, int_num2);
            char* s = s10_2(res);
            printf("%s (%d)\n", s, res);
            free(s);
        }
        else if (s8(num1) == 1 && s8(num2) == 1) {
            int int_num1 = s8_10(num1);
            int int_num2 = s8_10(num2);
            int res = bin_operation(c, int_num1, int_num2);
            char* s = s10_8(res);
            printf("%s (%d)\n", s, res);
            free(s);
        }
        else if (s16(num1) == 1 && s16(num2) == 1) {
            int int_num1 = s16_10(num1);
            int int_num2 = s16_10(num2);
            int res = bin_operation(c, int_num1, int_num2);
            char* s = s10_16(res);
            printf("%s (%d)\n", s, res);
            free(s);
        }
        else {
            printf("Ошибка: проверьте системы счисления операндов и их знак\n");
        }
    }
    else if (f2 == 1 && c ==  '~') {
        if (s2(num1) != 0) {
            int int_num1 = s2_10(num1);
            int res = ~int_num1;
            char* s = s10_2(res);
            printf("%s (%d)\n", s, res);
            free(s);
        }
        else if (s8(num1) != 0) {
            int int_num1 = s8_10(num1);
            int res = ~int_num1;
            char* s = s10_8(res);
            printf("%s (%d)\n", s, res);
            free(s);
        }
        else if (s16(num1) != 0) {
            int int_num1 = s16_10(num1);
            int res = ~int_num1;
            char* s = s10_16(res);
            printf("%s (%d)\n", s, res);
            free(s);
        }
        else {
            printf("Ошибка: проверьте систему счисления операнда\n");
        }
    }
    else {
        printf("Ошибка: неправильная операция\n");
    }
    free(num1);
    free(num2);
}
