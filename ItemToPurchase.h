#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H
using namespace std;

class ItemToPurchase {
private :
    string itemName;
    string itemDesc;
    int itemPrice;
    int itemQuantity;
public :
    ItemToPurchase(string itemName, string itemDesc, int itemPrice, int itemQuantity);

    ItemToPurchase();

    const string &GetDescription() const;

    void SetDescription(const string &itemDesc);

    const string &GetName() const;

    void SetName(const string &itemName);

    int GetPrice() const;

    void SetPrice(int itemPrice);

    int GetQuantity() const;

    void SetQuantity(int itemQuantity);

    void PrintItemCost();

    void PrintItemDescription();
};

#endif
