#include "lab5.h"

GroceryList GroceryListInit(int maxLength, int *errorCode) {

    GroceryList list;

    list.maxLength = maxLength;
    list.size = 0;
    list.items = (GroceryItems *)malloc(sizeof(GroceryItems));
    list.items = malloc(maxLength * sizeof(char));

    *errorCode = 0;
}

GroceryList GroceryListAppend(GroceryList glist, char * itemName, int * errorCode) {

}

char * GroceryListGetItem(GroceryList glist, int k, int *errorCode) {

}

int GroceryCount(GroceryList glist) {

}

void GroceryListPrint(GroceryList glist) {

}

void GroceryListDelete(GroceryList glist) {

}