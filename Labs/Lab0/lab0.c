#include "lab0.h"

/*
/   courtOccurrences() should be self explainitory by using proper naming conventions,
/   which in this case it is. 
/   
/   size: refers to the size of the array.
/   array: refers to the array to check query against to.
/   query: the value we want to find, if any, inside the array.
/
/   returns: the amout of occurences of specified query.
*/
int countOccurrences(int size, int array[], int query) {

    int occurrences = 0;

    for (int i = 0; i < size; i++) {
        if (query == array[i]) {
            occurrences++;
        }
    }

    return occurrences;

}

