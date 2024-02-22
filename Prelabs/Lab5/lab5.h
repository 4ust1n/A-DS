#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * items[];
} GroceryItems;

typedef struct {
    int maxLength;
    int size;
    GroceryItems *items;
} GroceryList;

GroceryList GroceryListInit(int maxLength, int *errorCode);

GroceryList GroceryListAppend(GroceryList glist, char * itemName, int * errorCode);

char * GroceryListGetItem(GroceryList glist, int k, int *errorCode);

int GroceryCount(GroceryList glist);

void GroceryListPrint(GroceryList glist);

void GroceryListDelete(GroceryList glist);