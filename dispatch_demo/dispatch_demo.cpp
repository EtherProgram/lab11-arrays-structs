
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Adrian A. Mena Cruz]
 * Lab: 11 - Arrays and Structs
 * Description: Receives a shipment record and displays its summary using a struct and a function.
 * Due Date: [11/01/2026]
 */

#include <iostream> // Provides console input and output
#include <string> // Provides string and getline

using namespace std;

struct DispatchRecord {
    string destination; // Stores the shipment destination
    int boxCount = 0; // Initializes the number of boxes
};

// Step 2: Function prototype
void displayDispatch(DispatchRecord record);

int main() {
    DispatchRecord shipment = {}; // Creates one initialized record

    cout << "Enter shipment destination: ";
    getline(cin, shipment.destination); // Reads a destination that may include spaces

    cout << "Enter number of boxes: ";
    cin >> shipment.boxCount;

    while (shipment.boxCount < 1) {
        cout << "Enter a positive number of boxes: ";
        cin >> shipment.boxCount; // Validates the count before displaying the record
    }

    cout << "Destination recorded: " << shipment.destination << endl;

    // Step 2: Function call
    displayDispatch(shipment); // Sends a copy of the complete record to the function

    return 0;
}

// Step 2: Function definition
void displayDispatch(DispatchRecord record) {
    cout << "Dispatch summary" << endl;
    cout << "Destination: " << record.destination << endl;
    cout << "Boxes: " << record.boxCount << endl; // Displays a member from the local record copy
}

/*
 * Analysis:
 * 1. What is the difference between DispatchRecord and shipment?
 * DispatchRecord is a struct type that defines the members of a shipment record,
 * while shipment is a variable of that type.
 *
 * 2. Which members are copied when displayDispatch(shipment) is called?
 * Both destination and boxCount are copied into the function's local record parameter.
 *
 * 3. Why would changing record.boxCount inside the function leave shipment.boxCount unchanged?
 * Because the function receives the struct by value, meaning it works with a copy
 * instead of modifying the original shipment variable.
 */
