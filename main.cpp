#include <iostream>
#include <string.h>
#include <string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void PrintMenu(ShoppingCart cart) {
    string choice;
    while (true) {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl;
        while (true) {
            cout << "\nChoose an option:";
            getline(cin, choice);
            if (choice == "a" || choice == "d" || choice == "c" || choice == "i" || choice == "o") { break; }
            if (choice == "q") {
                cout << "\n";
                return;
            }
        }
        if (choice == "a") {
            ItemToPurchase item;
            string itemName;
            string itemDesc;
            string itemPrice;
            string itemQuant;
            cout << "\nADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, itemName);
            cout << "Enter the item description:" << endl;
            getline(cin, itemDesc);
            cout << "Enter the item price:" << endl;
            getline(cin, itemPrice);
            cout << "Enter the item quantity:" << endl;
            getline(cin, itemQuant);
            item.SetName(itemName);
            item.SetDescription(itemDesc);
            item.SetQuantity(stoi(itemQuant));
            item.SetPrice(stoi(itemPrice));
            cart.AddItem(item);
            cout << "\n";
        }
        if (choice == "d") {
            string itemName;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, itemName);
            cart.RemoveItem(itemName);
            cout << endl;
        }
        if (choice == "c") {
            ItemToPurchase item;
            string itemName;
            string itemQuant;
            cout << "\nCHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, itemName);
            cout << "Enter the new quantity:" << endl;
            getline(cin, itemQuant);
            item.SetName(itemName);
            item.SetQuantity(stoi(itemQuant));
            cart.ModifyItem(item);
            cout << endl;
        }
        if (choice == "i") { cart.PrintDescriptions(); }
        if (choice == "o") { cart.PrintTotal(); }
    }
}

int main() {
    ShoppingCart shoppingCart1;
    cout << "Enter customer's name:" << endl;
    string name1;
    getline(cin, name1);
    cout << "Enter today's date:" << endl;
    string date1;
    getline(cin, date1);
    shoppingCart1.SetDate(date1);
    shoppingCart1.SetCustomerName(name1);
    cout << "\nCustomer name: " << shoppingCart1.GetCustomerName() << endl;
    cout << "Today's date: " << shoppingCart1.GetDate() << endl << endl;
    PrintMenu(shoppingCart1);
    return 0;
}