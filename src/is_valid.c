#include "pathfinder.h"

bool is_valid(char* line) {
	int i = 0;
	bool fst = true;
	bool sec = true;
	while (*(line + i) != '\0') {
		if (fst && !sec) {
			return false;
		}
		else if (!fst && (*(line + i) == '-')) {
			return false;
		}
		else if (fst && (*(line + i) == '-')) {
			fst = false;
		}
		else if (!sec && (*(line + i) == ',')) {
			return false;
		}
		else if (sec && (*(line + i) == ',')) {
			sec = false;
		}
		else if (sec && !my_isalpha(*(line + i))){
			return false;
		}
		i++;
	}
	if (!fst && !sec){
		return true;
	}
	else {
		return false;
	}
}
