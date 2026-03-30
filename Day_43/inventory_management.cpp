#include <iostream>
using namespace std;

struct Suplier
{
    string name;
    string phoneNumber;
};

class Item
{
private:
    string itemName;
    string itemCategory;
    double itemPrice;
    Suplier suplierInfo;
    int itemQuantity;

    static double totalInventoryValue;
    Item *mostExpensive;
    Item *higherStockItem;
    static int totalItemsCounter;

public:
    Item()
    {
        this->itemName = "";
        this->itemCategory = "";
        this->itemPrice = 0;
        this->itemQuantity = 0;
        this->suplierInfo.name = "";
        this->suplierInfo.phoneNumber = "";
        this->totalItemsCounter++;
    };

    void setData(string name, string ctg, double price, int quantity, Suplier info)
    {
        itemName = name;
        itemCategory = ctg;
        itemPrice = price;
        itemQuantity = quantity;
        suplierInfo = info;
    };

    string getName()
    {
        return itemName;
    }
    string getCategory()
    {
        return itemCategory;
    }
    double getPrice()
    {
        return itemPrice;
    }
    Suplier getSupplier()
    {
        return suplierInfo;
    }

    int getQuantity()
    {
        return itemQuantity;
    }

    Item getMostExpensive()
    {
        return *mostExpensive;
    };

    Item getHigerStockItem()
    {
        return *higherStockItem;
    }

    static void addToTotal(double price)
    {
        totalInventoryValue += price;
    }

    void findMostExpensive_higherStock(Item *inventoryArray, int size)
    {
        Item *mostExp = &inventoryArray[0];
        Item *highestStock = &inventoryArray[0];

        for (int i = 0; i < size; i++)
        {
            if (mostExp->getPrice() < inventoryArray[i].getPrice())
            {
                mostExp = &inventoryArray[i];
            }
            if (highestStock->getQuantity() < inventoryArray[i].getQuantity())
            {
                highestStock = &inventoryArray[i];
            }
        }
        mostExpensive = mostExp;
        higherStockItem = highestStock;
    }

    void sortItem(Item *inventoryArray, int size)
    {

        for (int i = 1; i < size; i++)
        {
            int temp = i;
            while (temp > 0 && inventoryArray[temp].getPrice() < inventoryArray[temp - 1].getPrice())
            {
                Item tempItem = inventoryArray[temp];
                inventoryArray[temp] = inventoryArray[temp - 1];
                inventoryArray[temp - 1] = tempItem;
                temp--;
            }
        }
    }

    Item filterItem(Item *inventoryArray, int size)
    {
        char control;
        string category;
        string suplierName;
        do
        {
            cout << "Enter C to fileter by category and S to filter by suplier: ";
            cin >> control;

            if (control != 'C' && control != 'S')
            {
                cout << "Invalid Input ! Please try again." << endl;
                continue;
            }

        } while (control != 'C' && control != 'S');

        switch (control)
        {
        case 'C':
        {
            cin.ignore();
            cout << "Enter category: ";
            getline(cin, category);
            for (int i = 0; i < size; i++)
            {
                if (inventoryArray[i].getCategory() == category)
                {
                    return inventoryArray[i];
                }
            }
            cout << ">>> No item exists with this category!!!" << endl;
        }
        break;
        case 'S':
        {
            cin.ignore();
            cout << "Enter Suplier Name: ";
            getline(cin, suplierName);
            for (int i = 0; i < size; i++)
            {
                if (inventoryArray[i].getSupplier().name == suplierName)
                {
                    return inventoryArray[i];
                }
            }
            cout << ">>> No item exists with this suplier name!!!" << endl;
        }
        break;
        default:
            cout << "Unexpected error occured! try again." << endl;
            break;
        }
    };
};

int Item::totalItemsCounter = 0;
double Item::totalInventoryValue = 0;

void inputData(Item *inventoryArray, int size)
{
    string name;
    string category;
    double price;
    int quantity;
    Suplier info;

    cout << "__________Enter details of Items__________" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "<Item>__: " << (i + 1) << endl;
        cout << "Enter name of item: ";
        getline(cin, name);
        cout << "Category: ";
        cin >> category;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;
        cout << "Suplier Name: ";
        cin >> info.name;
        cout << "Suplier Phone: ";
        cin >> info.phoneNumber;
        cin.ignore();
        inventoryArray[i].setData(name, category, price, quantity, info);
        Item::addToTotal(price);
    }
};

void outputData(Item *inventoryArray, int size)
{
    cout << "__________Inventory Details__________" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "///__Item_=>: " << (i + 1) << endl;
        cout << "Item name: " << inventoryArray[i].getName() << endl;
        cout << "Category: " << inventoryArray[i].getCategory() << endl;
        cout << "Price: " << inventoryArray[i].getPrice() << endl;
        cout << "Quantity: " << inventoryArray[i].getQuantity() << endl;
        cout << "Suplier Name: " << inventoryArray[i].getSupplier().name << endl;
        cout << "Suplier Phone Number: " << inventoryArray[i].getSupplier().phoneNumber << endl;
    }
};

int showMenu()
{
    int choice;
    cout << "---<<<Welcome to Inventoy Management System>>>---" << endl;
    cout << "1.Input Items\n2.Output Data\n3.Filter Item\n4.Sort Items by Price\n5.Display most expensive item\n6.Display highest Quantity item" << endl;
    cin >> choice;
    return choice;
};

int main()
{
    int itemsNumber;
    Item *inventoryArray = new Item[itemsNumber];
    switch (showMenu())
    {
    case 1:
        inputData(inventoryArray, itemsNumber);
        break;
    case 2:
        outputData(inventoryArray, itemsNumber);
        break;
    default:
        break;
    }

    cout << endl;

    delete[] inventoryArray;
    return 0;
}