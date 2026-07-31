#include "inventory_report.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string> //apparently getline is a string function?

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
    if (isValidPrice(item.price) && isValidQuantity(item.quantity)) {
        double quantity = item.quantity;
        double price = item.price;
        return quantity*price;
    }
    return 0.0;
}

int readInventoryFile(string filename, InventoryItem items[], int maxItems) {
    // TODO:
    // Open the input file.
    // Read records in this format: sku name quantity price
    // Store valid records in the items array.
    // Stop when the file ends or maxItems is reached.
    // Return the number of records stored.
//     fstream invFile(filename);
//     int storeCount = 0;
//     if (!invFile) {
        
//         char outChar[maxItems];
        
//         string line;
//         //first, open the file and read the line.
//         //Separate into variables depending on whitespace
//         //check validity. If everything is good, create an item and put it into items
//         // increment array index until max items.

//         // while not max items and not end of file
//         // line read loop that breaks when valid item
//         // move to next spot in items

//         while ((storeCount < maxItems) && (getLine(filename,line))) { //keeps going until full or end
//             for (string line = ""; getLine(filename, line); ) { //loops every line
//                 char readChar[4];
//                 getLine(readChar,4,' ');
//                 char sku = readChar[1];
//                 char name = readChar[2];
//                 double quantity = readChar[3];
//                 double price = readChar[4];
//                 if ((isValidPrice(price) && isValidQuantity(quantity)) {
//                     InventoryItem item = new InventoryItem;
//                     item.sku = sku;
//                     item.name = name;
//                     item.quantity = quantity;
//                     item.price = price;
//                     items[storeCount] = item;
//                     storeCount ++;
//                 }
//             }
//         }
//     }
//     //oh, okay, we can use << and invFile >> string if string is []
//     invFile.close();
//     return storeCount;
        
        if (items == nullptr || maxItems <= 0) {
            return 0; //early quit if invalid
        }
        ifstream in(filename);
        if (!in.is_open()){
            return 0; //break if failed opening
        }
        
        int count = 0;
        InventoryItem item;
        while (count < maxItems && in >> item.sku >> item.name >> item.quantity >> item.price) { //reads by whitespace and breaks into vars on a new item
            if (isValidQuantity(item.quantity) && isValidPrice(item.price)) { //check validity
                items[count] = item; // set array with previously made item
                count ++;
            }
        }
        in.close(); //close file
        return count; //return


}


bool writeInventoryReport(string filename, const InventoryItem items[], int count) {
    // TODO:
    // Open the output file.
    // Write each item and its total value.
    // Write the total inventory value.
    // Return true if the report was written successfully.
    ofstream out(filename); // open the file for writing

    if (!out.is_open()) { //break if it fails
        return false;
    }
    if (items == nullptr || count < 0) { //stop if either is invalid; definitely should make a function for this
        return false;
    }
    
    out << "Inventory Report" << endl;
    out << "SKU Name Quantity Price Value" << endl;

    for (int i = 0; i < count; i++) {
        out << items[i].sku << " "
            << items[i].name << " "
            <<items[i].quantity << " "
            << items[i].price << " "
            << calculateItemValue(items[i])
            << endl;
    }
    out << "Total inventory value"
        << calculateTotalInventoryValue(items, count)
        << endl;
    out.close();

    return true;
}

double calculateTotalInventoryValue(const InventoryItem items[], int count) {
    // TODO:
    // Return the sum of all item values.
    // Return 0.0 for null arrays or invalid counts.
    if (items == nullptr || count <= 0) {
        return 0.0;
    }
    double total = 0.0;
    for (int i = 0; i < count; i ++) {
        total += calculateItemValue(items[i]);
    }
    return total;
}

int findItemBySku(const InventoryItem items[], int count, string sku) {
    // TODO:
    // Search for a matching SKU.
    // Return the index if found.
    // Return -1 if not found.
    if (items == nullptr || count <= 0) {
        return -1;
    }
    for (int i = 0; i < count; i ++) {
        if (items[i].sku == sku) {
            return i;
        }
    }

    return -1;
}

int findHighestValueItemIndex(const InventoryItem items[], int count) {
    // TODO:
    // Return the index of the item with the highest item value.
    // Return -1 for null arrays or invalid counts.
    if (items == nullptr || count <= 0) {
        return -1;
    }
    int highestIndex = -1;
    int highestVal = -1;
    for (int i = 0; i < count; i ++) {
        if (calculateItemValue(items[i]) > highestVal) {
            highestIndex = i;
            highestVal = calculateItemValue(items[i]);
        }
    }
    return highestIndex;
}
