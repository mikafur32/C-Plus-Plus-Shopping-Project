#include <iostream>
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase(string name, string desc, int price, int quantity) {
    this->itemName = name;
    this->itemDesc = desc;
    this->itemPrice = price;
    this->itemQuantity = quantity;
}

ItemToPurchase::ItemToPurchase() {
    this->itemName = "none";
    this->itemDesc = "none";
    this->itemPrice = 0;
    this->itemQuantity = 0;
}

const string &ItemToPurchase::GetDescription() const { return itemDesc; }

void ItemToPurchase::SetDescription(const string &itemDesc) { ItemToPurchase::itemDesc = itemDesc; }

const string &ItemToPurchase::GetName() const { return itemName; }

void ItemToPurchase::SetName(const string &itemName) { ItemToPurchase::itemName = itemName; }

int ItemToPurchase::GetPrice() const { return itemPrice; }

void ItemToPurchase::SetPrice(int itemPrice) { ItemToPurchase::itemPrice = itemPrice; }

int ItemToPurchase::GetQuantity() const { return itemQuantity; }

void ItemToPurchase::SetQuantity(int itemQuantity) { ItemToPurchase::itemQuantity = itemQuantity; }

void ItemToPurchase::PrintItemDescription() { cout << this->itemName << ": " << this->itemDesc << endl; }

void ItemToPurchase::PrintItemCost() {
    cout << this->itemName << " " << this->itemQuantity << " @ $" << this->itemPrice << " = $"
         << this->itemPrice * this->itemQuantity << endl;
}