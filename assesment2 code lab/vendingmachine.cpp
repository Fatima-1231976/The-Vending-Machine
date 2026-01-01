#include <iostream>
#include <string>
using namespace std;

int main() {
    // Prices
    const double priceCoke = 1.50;
    const double priceWater = 1.00;
    const double priceChips = 1.20;
    const double priceChocolate = 1.80;
    const double priceMealDeal = 2.50; // Meal deal: 1 drink + 1 snack

    // Stock levels
    int stockCoke = 3;
    int stockWater = 3;
    int stockChips = 3;
    int stockChocolate = 3;
    int stockMealDeal = 2;

    double money = 0.0;
    string code;
    char buyMore = 'Y';

    cout << " VENDING MACHINE " << endl;
    cout << "Insert your money (£): ";
    cin >> money;

    // Validate money input
    if (money <= 0) {
        cout << "Invalid amount. Please restart the program." << endl;
        return 0;
    }

    // Loop for multiple purchases
    while (buyMore == 'Y' || buyMore == 'y') {
        cout << "\n MENU " << endl;
        cout << "1 - Coke        (£1.50)   Stock: " << stockCoke << endl;
        cout << "2 - Water       (£1.00)   Stock: " << stockWater << endl;
        cout << "3 - Chips       (£1.20)   Stock: " << stockChips << endl;
        cout << "4 - Chocolate   (£1.80)   Stock: " << stockChocolate << endl;
        cout << "5 - Meal Deal   (£2.50)   Stock: " << stockMealDeal << endl;

        cout << "\nEnter item code: ";
        cin >> code;

        double price = 0.0;
        int* stockPtr = nullptr;

        //Match code to item
        if (code == "1") { price = priceCoke;      stockPtr = &stockCoke; }
        else if (code == "2") { price = priceWater;     stockPtr = &stockWater; }
        else if (code == "3") { price = priceChips;     stockPtr = &stockChips; }
        else if (code == "4") { price = priceChocolate; stockPtr = &stockChocolate; }
        else if (code == "5") { price = priceMealDeal;  stockPtr = &stockMealDeal; }
        else {
            cout << "Invalid code. Please try again." << endl;
            continue;
        }

        //Check stock
        if (*stockPtr <= 0) {
            cout << "Sorry, this item is out of stock." << endl;
            continue;
        }

        //Check money
        if (money < price) {
            cout << "Not enough credit. You have £" << money << endl;
            cout << "Please choose a cheaper item." << endl;
            continue;
        }

        // Deduct price + reduce stock
        money -= price;
        (*stockPtr)--;

        cout << "Item dispensed successfully!" << endl;
        cout << "Remaining credit: £" << money << endl;

        cout << "Do you want to buy another item? (Y/N): ";
        cin >> buyMore;
    }

    //Return change
    cout << "\nTransaction complete." << endl;
    cout << "Your change: £" << money << endl;
    cout << "Thank you for using the vending machine!" << endl;

    return 0;
}