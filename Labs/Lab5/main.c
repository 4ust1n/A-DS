#include "lab5.h"

int main() {

    VendingMachine *machine = newMachine(8);

    for (int i = 1; i < 15; i++) {
        StockItem item;
        item.ID = i;
        item.maxStock = i;
        item.price = i + 0.5;
        item.stock = i;

        int r = addStockItem(machine, item);
        printf("Added: %d\n", r);
    }

    int c = countExpensive(machine);
    printf("Count Exps: %d\n", c);

    for (int i = 1; i < 15; i++) {

        StockItem *stonks;
        stonks = malloc(sizeof(StockItem));

        int t = removeStockItem(machine, i, stonks);
        printf("Removed: %d\n", t);
        //  printf("BBB: %f", stonks->price);
        // printf("Valuessss: %d\n", stonks->ID);
    }

    if (machine) {
        printf("It worked.\n");
    }
    if (!machine) {
        printf("Didnt work.\n");
    }

    freeVendingMachine(machine);

    if (machine) {
        printf("Memory is still allocated.\n");
    }
    if (!machine) {
        printf("Memory was deallocated.\n");
    }

    return 0;
}