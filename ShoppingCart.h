#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <vector>
#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart {
public :
    ShoppingCart(const string &customerName, const string &currentDate);

    ShoppingCart();

    const string &GetCustomerName() const;

    void SetCustomerName(const string &customerName);

    const string &GetDate() const;

    void SetDate(const string &currentDate);

    const vector<ItemToPurchase> &getCartItems() const;

    void SetCartItems(const vector<ItemToPurchase> &cartItems);

    void AddItem(ItemToPurchase item);

    void RemoveItem(string name);

    void ModifyItem(ItemToPurchase item);

    int GetNumItemsInCart();

    int GetCostOfCart();

    void PrintTotal();

    void PrintDescriptions();

    void printCart();

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};

#endif