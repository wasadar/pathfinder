#include "pathfinder.h"

bool check_data(char* data){
    int i = 0;
    int count = 1;
    bool check = false;
    while(*(data + i) != '\0'){
        if (*(data + i) == '\n'){
            count++;
            check = true;
        }
        else {
            check = false;
        }
        i++;
    }
    if (!check){
        printerr("error: line ");
		printerr(mx_itoa(count));
		printerr(" is not valid\n");
        return false;
    }
    return true;
}
