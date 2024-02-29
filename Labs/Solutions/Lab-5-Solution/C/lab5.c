#include "lab5.h"

struct VendingMachine_t {
    int size;
    StockItem *items;
};

/* newMachine
    This function takes a size, and allocates
    a vending machine struct with enough space
    to hold the requested number of StockItems.
    It returns a pointer to the new machine on
    success, or NULL on failure

    int numSlots;   The number of item slots to create
*/
VendingMachine * newMachine(int numSlots) {
    VendingMachine *vm = malloc(sizeof(VendingMachine));

    if(!vm) {
        return NULL;
    }

    vm->items = malloc(sizeof(StockItem) * numSlots);
    if(!vm->items) {
        free(vm);
        return NULL;
    }

    vm->size = numSlots;
    for(int i = 0; i < numSlots; ++i) {
        // Alternative way to initialize a struct instance
        vm->items[i] = (StockItem){0, 0, 0, 0.0};
    }

    return vm;
}

/* addStockItem
    This function takes a vending machine, as well
    as a new stock item to insert into the machine.
    It inserts the item into the first empty slot
    in the machine, and returns 1 on success, or 0
    on failure.

    VendingMachine *vm; The machine to insert into
    StockItem item;     The item to insert
*/
int addStockItem(VendingMachine *vm, StockItem item) {
    for(int i = 0; i < vm->size; ++i) {
        if(vm->items[i].ID == 0) {
            vm->items[i] = item;
            return 1;
        }
    }

    return 0;
}

/* countCheap
    This function takes a vending machine, and
    returns the number of non-empty slots in
    the machine with a price of <= 3.

    VendingMachine *vm; The machine to count from
*/
int countCheap(VendingMachine *vm) {
    int count = 0;
    for(int i = 0; i < vm->size; ++i) {
        if(vm->items[i].ID != 0) {
            if(vm->items[i].price <= 3) {
                ++count;
            }
        }
    }

    return count;
}

/* removeStockItem
    This function takes a vending machine, and removes
    the item corresponding to the given ID, if it
    exists in the machine. It updates the result
    pointer with the value of the removed item, and
    reutrns 1 on success, or 0 on failure.

    VendingMachine *vm; The machine to remove from
    int ID;             The ID of the item to remove
    StockItem *result;  The location to return the removed item with
*/
int removeStockItem(VendingMachine *vm, int ID, StockItem *result) {
    for(int i = 0; i < vm->size; ++i) {
        if(vm->items[i].ID == ID) {
            *result = vm->items[i];
            // reset slot to "empty"
            vm->items[i] = (StockItem){0, 0, 0, 0.0};
            return 1;
        }
    }

    return 0;
}

/* freeVendingMachine
    This function takes a vending machine,
    and frees all memory allocated to it.

    VendingMachine *vm; The machine to free
*/
void freeVendingMachine(VendingMachine *vm) {
    free(vm->items);
    free(vm);
}
