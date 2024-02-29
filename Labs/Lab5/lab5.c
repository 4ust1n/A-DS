#include "lab5.h"

struct VendingMachine_t {
    int numberOfSlots;
    StockItem *slots;
};


/*
Creates a new vending machine.

Params:
int numSlots - Number of Stock items to be inside vending machine.

Returns:
Pointer to a vending machine, otherwise NULL if memory allocated failed.
*/
VendingMachine * newMachine(int numSlots) {

    // Dynamically allocate memory.
    StockItem *slots = (StockItem *) malloc(sizeof(StockItem) * numSlots);

    if (!slots) {
        return NULL;
    }

    VendingMachine *machine = (VendingMachine *) malloc(sizeof(VendingMachine) + sizeof(slots));

    if (!machine) {
        return NULL;
    }

    // Assign values.
    machine->numberOfSlots = numSlots;
    machine->slots = slots;

    for (int i = 0; i < numSlots; i++) {
        machine->slots[i].ID = 0;
        machine->slots[i].price = 0.0;
        machine->slots[i].maxStock = 0;
        machine->slots[i].stock = 0;
    }

    return machine;
}

/*
Adds a stock item to the vending machine.

Params:
VendingMachine *vm - pointer to vending machine.
StockItem item - item struct containing stock metadata.

Returns:
1 if successful, otherwise 0.*/
int addStockItem(VendingMachine *vm, StockItem item) {
    for (int i = 0; i < vm->numberOfSlots; i++) {
        // Empty slot found.
        if (vm->slots[i].ID == 0) {
            vm->slots[i] = item;
            return 1;
        }
    }

    // No empty slot found.
        return 0;
}

/*
Count the amount of items that are priced at greater than or equal to $3.

Params:
VendingMachine *vm - pointer to vending machine.

Returns:
The amount of items that are priced at $3 or greater.*/
int countExpensive(VendingMachine *vm) {
    int amount = 0;

    for (int i = 0; i < vm->numberOfSlots; i++) {
        if (vm->slots[i].price >= 3) {
            amount += 1;
        }
    }

    return amount;
}


/*
Remove stock item from vending machine.

Params:
VendingMachine *vm - Pointer to vending machine.
int ID - Specific id of a slot inside vending machine.
StockItem *result - Pointer to a stock item that is to be removed.

Returns:
1 if ID was found inside vending machine, otherwise 0.*/
int removeStockItem(VendingMachine *vm, int ID, StockItem *result) {

    for (int i = 0; i < vm->numberOfSlots; i++) {

        // StockItem was found inside vending machine.
        if (vm->slots[i].ID == ID) {
            *result = vm->slots[i];
            vm->slots[i].ID = 0;

            return 1;
        }
    }

    // StockItem was not found.
    return 0;
}

/*
Vending Machine is freed from memory.

Params:
VendingMachine *vm - Pointer to vending machine.
*/
void freeVendingMachine(VendingMachine *vm) {
    free(vm->slots);
    free(vm);
}


