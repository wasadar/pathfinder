#include "libmx.h"

void mx_printint(int n){
    if (n < 0){
        mx_printchar(45);
        if (n <= -1000000000) {
            mx_printchar((n / (-1000000000)) + 48);
            n %= 1000000000;
        }
        n *= (-1);
    }
    else if (n == 0){
        mx_printchar(48 + 0);
    }
    if (n >= 1000000000) {
        mx_printchar((n / 1000000000) + 48);
        n %= 1000000000;
    }
    int temp = 1;
    while (temp <= n){
        temp *= 10;
    }
    temp /= 10;
    while (temp > 0){
        mx_printchar(48 + ((n / temp) % 10));
        temp /= 10;
    }
}
