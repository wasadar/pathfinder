#include "libmx.h"

int mx_bubble_sort(char** arr, int size) {
    int count = 0;
    char* temp;
    bool check;
    do {
        check = false;
        for (int i = 1; i < size; i++) {
            if (mx_strcmp(*(arr + i - 1), *(arr + i)) > 0) {
                temp = *(arr + i);
                *(arr + i) = *(arr + i - 1);
                *(arr + i - 1) = temp;
                count++;
                check = true;
            }
        }
    } while (check);
    return count;
}
