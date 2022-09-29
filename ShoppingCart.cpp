#include <iostream>
#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart(const string &customerName, const string &currentDate) : customerName(customerName),
                                                                                    currentDate(
                                                                                            currentDate) { vector<ItemToPurchase> cartItems; }

ShoppingCart::ShoppingCart() {
    this->customerName = "none";
    this->currentDate = "January 1, 2016";
}

const string &ShoppingCart::GetCustomerName() const { return customerName; }

void ShoppingCart::SetCustomerName(const string &customerName) { ShoppingCart::customerName = customerName; }

const string &ShoppingCart::GetDate() const { return currentDate; }

void ShoppingCart::SetDate(const string &currentDate) { ShoppingCart::currentDate = currentDate; }

const vector<ItemToPurchase> &ShoppingCart::getCartItems() const { return cartItems; }

void ShoppingCart::SetCartItems(const vector<ItemToPurchase> &cartItems) { ShoppingCart::cartItems = cartItems; }

void ShoppingCart::AddItem(ItemToPurchase item) { this->cartItems.push_back(item); }

void ShoppingCart::RemoveItem(string name) {
    for (auto i = this->cartItems.begin(); i != this->cartItems.end(); ++i) {
        if (i->GetName() == name) {
            this->cartItems.erase(i);
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    for (int i = 0; i < this->cartItems.size(); i++) {
        if (this->cartItems.at(i).GetName() == item.GetName()) {
            item.SetPrice(this->cartItems.at(i).GetPrice());
            item.SetDescription(this->cartItems.at(i).GetDescription());
            this->cartItems.at(i) = item;
            return;
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::GetNumItemsInCart() {
    int sum = 0;
    for (auto i = this->cartItems.begin(); i != this->cartItems.end(); ++i) { sum += i->GetQuantity(); }
    return sum;
}

int ShoppingCart::GetCostOfCart() {
    int sum = 0;
    for (auto i = this->cartItems.begin(); i != this->cartItems.end(); ++i) { sum += i->GetPrice() * i->GetQuantity(); }
    return sum;
}

void ShoppingCart::PrintTotal() {
    cout << "\n";
    cout << "OUTPUT SHOPPING CART" << endl;
    this->printCart();
    cout << "Number of Items: " << this->GetNumItemsInCart() << endl << endl;
    if (this->cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else { for (auto i = this->cartItems.begin(); i != this->cartItems.end(); ++i) { i->PrintItemCost(); }}
    cout << "\nTotal: $" << this->GetCostOfCart() << endl << endl;
}

void ShoppingCart::PrintDescriptions() {
    cout << endl;
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    this->printCart();
    cout << "\nItem Descriptions" << endl;
    for (auto i = this->cartItems.begin(); i != this->cartItems.end(); ++i) { i->PrintItemDescription(); }
    cout << endl;
}

void ShoppingCart::printCart() { cout << this->customerName << "'s Shopping Cart - " << this->currentDate << endl; }