#include "inventory_report.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

bool isValidQuantity(int quantity) {
    // TODO: Return true when quantity is 0 or greater.
    return (quantity >= 0);
}

bool isValidPrice(double price) {
    // TODO: Return true when price is 0 or greater.
    return (price >= 0);
}

double calculateItemValue(const InventoryItem& item) {
    // TODO: Return quantity multiplied by price.
    // If quantity or price is invalid, return 0.0.
    double quantity = item.quantity;
    double price = item.price;
    return quantity/price;
}

int readInventoryFile(string filename, InventoryItem items[], int maxItems) {
    // TODO:
    // Open the input file.
    // Read records in this format: sku name quantity price
    // Store valid records in the items array.
    // Stop when the file ends or maxItems is reached.
    // Return the number of records stored.
    fstream invFile(filename);
    char outChar[maxItems];
    int storeCount = 0;
    string line;
    //first, open the file and read the line.
    //Separate into variables depending on whitespace
    //check validity. If everything is good, create an item and put it into items
    // increment array index until max items.

    // while not max items and not end of file
    // line read loop that breaks when valid item
    // move to next spot in items

    while ((storeCount < maxItems) && (getLine(filename,line))) { //keeps going until full or end
        for (string line = ""; getLine(filename, line); ) { //loops every line
            char readChar[4];
            getLine(readChar,4,' ');
            string sku = readChar[1];
            string name = readChar[2];
            double quantity = readChar[3];
            double price = readChar[4];
            if ((isValidPrice(price) && isValidQuantity(quantity)) {
                InventoryItem item = new InventoryItem;
                item.sku = sku;
                item.name = name;
                item.quantity = quantity;
                item.price = price;
            }
        }
    }

    invFile.close();
    return storeCount;
}

bool writeInventoryReport(string filename, const InventoryItem items[], int count) {
    // TODO:
    // Open the output file.
    // Write each item and its total value.
    // Write the total inventory value.
    // Return true if the report was written successfully.
    return false;
}

double calculateTotalInventoryValue(const InventoryItem items[], int count) {
    // TODO:
    // Return the sum of all item values.
    // Return 0.0 for null arrays or invalid counts.
    return 0.0;
}

int findItemBySku(const InventoryItem items[], int count, string sku) {
    // TODO:
    // Search for a matching SKU.
    // Return the index if found.
    // Return -1 if not found.
    return -1;
}

int findHighestValueItemIndex(const InventoryItem items[], int count) {
    // TODO:
    // Return the index of the item with the highest item value.
    // Return -1 for null arrays or invalid counts.
    return -1;
}
