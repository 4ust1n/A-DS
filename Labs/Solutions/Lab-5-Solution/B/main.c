#include "lab5.h"
#include <stdarg.h>

// print format to stderr, prefiexed with "ERROR: " and with ending newline
int verrf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    fputs("ERROR: ", stderr);
    int i = vfprintf(stderr, format, args);
    fputs("\n", stderr);

    va_end(args);
    return i;
}

void printStockItem(StockItem item) {
    printf("StockItem(%d, %d, %d, %f)\n",
        item.ID,
        item.stock,
        item.maxStock,
        item.price
    );
}

// return 0 if they are equal, else 1
int compareStockItems(StockItem a, StockItem b) {
    return a.ID != b.ID ||
            a.stock != b.stock ||
            a.maxStock != b.maxStock ||
            a.price != b.price;
}

int main() {
    int size = 10;
    StockItem items[] = {
        {12, 10, 10, 5.3},
        {7, 5, 10, 2.5},
        {224, 0, 1, 500},
        {1, 6, 10, 1.5}
    };

    puts("----------------RUNNING TESTS----------------");
    VendingMachine *vm = newMachine(size);

    if(!vm) {
        verrf("newMachine unexpectedly returned NULL");
        return EXIT_FAILURE;
    }

    for(int i = 0; i < 4; ++i) {
        if(addStockItem(vm, items[i]) != 1) {
            verrf("addStockItem unexpectedly returned error for insertion: %d", i);
        }
    }

    int count;

    count = countExpensive(vm);
    if(count != 2) {
        verrf("countExpensive returned %d, expected %d", count, 2);
    }

    StockItem removed;
    int result;

    result = removeStockItem(vm, 111, &removed);
    if(result) {
        verrf("removeStockItem unexpectedly returned non-zero");
    }

    result = removeStockItem(vm, 224, &removed);

    count = countExpensive(vm);
    if(count != 1) {
        verrf("countExpensive returned %d, expected %d", count, 1);
    }

    if(result != 1) {
        verrf("removeStockItem unexpectedly returned non-success");
    }

    if(compareStockItems(removed, items[2])) {
        verrf("removeStockItem returned unexpected result");
        printf("Expected: ");
        printStockItem(items[2]);
        printf("Got     : ");
        printStockItem(removed);
    }

    VendingMachine *vm2 = newMachine(3);
    for(int i = 0; i < 3; ++i) {
        if(addStockItem(vm2, items[i]) != 1) {
            verrf("addStockItem unexpectedly returned error for insertion: %d", i);
        }
    }

    result = addStockItem(vm2, items[3]);
    if(result != 0) {
        verrf("addStockItem unexpectedly returned non-zero for above-max insertion");
    }

    puts("----------------FREEING ARRAY----------------");
    freeVendingMachine(vm);
    freeVendingMachine(vm2);
}

