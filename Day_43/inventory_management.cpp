#include <iostream>
using namespace std;

class Supplier
{
private:
    string name;
    string phoneNumber;

public:
    Supplier()
    {
        name = "";
        phoneNumber = "";
    }

    ~Supplier() {}

    void setSupplierName(string n)
    {
        name = n;
    }

    void setSupplierPhone(string phone)
    {
        phoneNumber = phone;
    }

    string getName() const
    {
        return name;
    }

    string getPhone() const
    {
        return phoneNumber;
    }
};

class Item
{
private:
    string itemName;
    string itemCategory;
    double itemPrice;
    Supplier supplierInfo;
    int itemQuantity;

    static int totalItemsCounter;

public:
    Item()
    {
        itemName = "";
        itemCategory = "";
        itemPrice = 0;
        itemQuantity = 0;
    }

    ~Item() {}

    void setData(string name, string ctg, double price, int quantity, Supplier info)
    {
        itemName = name;
        itemCategory = ctg;
        itemQuantity = quantity;
        supplierInfo = info;
        itemPrice = price;
    }

    static int getTotalItems()
    {
        return totalItemsCounter;
    }

    static void incrementCounter()
    {
        totalItemsCounter++;
    }

    string getName() const
    {
        return itemName;
    }

    string getCategory() const
    {
        return itemCategory;
    }

    double getPrice() const
    {
        return itemPrice;
    }

    Supplier getSupplier() const
    {
        return supplierInfo;
    }

    int getQuantity() const
    {
        return itemQuantity;
    }

    void sortItem(Item *inventoryArray, int size)
    {
        for (int i = 1; i < size; i++)
        {
            int temp = i;
            while (temp > 0 && inventoryArray[temp].getPrice() > inventoryArray[temp - 1].getPrice())
            {
                Item tempItem = inventoryArray[temp];
                inventoryArray[temp] = inventoryArray[temp - 1];
                inventoryArray[temp - 1] = tempItem;
                temp--;
            }
        }
    }

    Item *filterItem(Item *inventoryArray, int size, int &filteredCount)
    {
        char control;
        string category, supplierName;

        Item *filteredItems = new Item[size];
        filteredCount = 0;

        do
        {
            cout << "Enter C to filter by category and S to filter by supplier: ";
            cin >> control;
            control = toupper(control);

            if (control != 'C' && control != 'S')
                cout << "Invalid Input! Try again." << endl;

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
                    filteredItems[filteredCount++] = inventoryArray[i];
                }
            }

            if (filteredCount == 0)
                cout << ">>> No item exists with this category!!!" << endl;
        }
        break;

        case 'S':
        {
            cin.ignore();
            cout << "Enter Supplier Name: ";
            getline(cin, supplierName);

            for (int i = 0; i < size; i++)
            {
                if (inventoryArray[i].getSupplier().getName() == supplierName)
                {
                    filteredItems[filteredCount++] = inventoryArray[i];
                }
            }

            if (filteredCount == 0)
                cout << ">>> No item exists with this supplier name!!!" << endl;
        }
        break;
        }

        return filteredItems;
    }

    double getDiscountedPrice() const
    {
        if (itemCategory == "Electronics")
        {
            return itemPrice * 0.9;
        }
        return itemPrice;
    }
};

int Item::totalItemsCounter = 0;

class Inventory
{
private:
    Item *inventoryArray;
    int size;
    static double totalInventoryValue;

    const Item *higherStockItem;
    const Item *mostExpensive;

public:
    Inventory()
    {
        inventoryArray = nullptr;
        size = 0;
        higherStockItem = nullptr;
        mostExpensive = nullptr;
    }

    ~Inventory()
    {
        delete[] inventoryArray;
    }

    static double getInventoryTotalValue()
    {
        return totalInventoryValue;
    }

    void inputData()
    {
        cout << "Enter number of items: ";
        cin >> size;
        cin.ignore();

        delete[] inventoryArray;
        inventoryArray = new Item[size];

        totalInventoryValue = 0;

        string name, category, phone, suplierName;
        double price;
        int quantity;
        Supplier info;

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

            cin.ignore();
            cout << "Supplier Name: ";
            getline(cin, suplierName);
            info.setSupplierName(suplierName);

            cout << "Supplier Phone: ";
            cin >> phone;
            info.setSupplierPhone(phone);

            cin.ignore();

            inventoryArray[i].setData(name, category, price, quantity, info);
            Item::incrementCounter();
            totalInventoryValue += (inventoryArray[i].getPrice() * quantity);
        }
    }

    void outputData()
    {
        cout << "__________Inventory Details__________" << endl;

        for (int i = 0; i < size; i++)
        {
            cout << "///__Item_=>: " << (i + 1) << endl;
            cout << "Item name: " << inventoryArray[i].getName() << endl;
            cout << "Category: " << inventoryArray[i].getCategory() << endl;
            cout << "Price: " << inventoryArray[i].getPrice() << endl;
            cout << "Quantity: " << inventoryArray[i].getQuantity() << endl;
            cout << "Supplier Name: " << inventoryArray[i].getSupplier().getName() << endl;
            cout << "Supplier Phone: " << inventoryArray[i].getSupplier().getPhone() << endl;
        }
    }

    void filterItems()
    {
        Item temp;
        int filteredCount;

        Item *filtered = temp.filterItem(inventoryArray, size, filteredCount);

        if (filteredCount > 0)
        {
            cout << "Filtered Items:" << endl;
            for (int i = 0; i < filteredCount; i++)
            {
                cout << "Name: " << filtered[i].getName() << ", Category: " << filtered[i].getCategory() << ", Price: " << filtered[i].getPrice() << ", Quantity: " << filtered[i].getQuantity() << ", Supplier: " << filtered[i].getSupplier().getName() << endl;
            }
        }

        delete[] filtered;
    }

    void sortItems()
    {
        Item temp;
        temp.sortItem(inventoryArray, size);
        cout << "Items sorted by price (descending)." << endl;
    }

    void findMostExpensive_higherStock()
    {
        if (size == 0)
            return;

        mostExpensive = &inventoryArray[0];
        higherStockItem = &inventoryArray[0];

        for (int i = 0; i < size; i++)
        {
            if (inventoryArray[i].getPrice() > mostExpensive->getPrice())
            {
                mostExpensive = &inventoryArray[i];
            }

            if (inventoryArray[i].getQuantity() > higherStockItem->getQuantity())
            {
                higherStockItem = &inventoryArray[i];
            }
        }
    }

    void displayMostExpensive()
    {
        findMostExpensive_higherStock();
        cout << "Most Expensive item is: " << mostExpensive->getName() << endl;
        cout << "Item price is: " << mostExpensive->getPrice() << endl;
    }

    void displayHighestStock()
    {
        findMostExpensive_higherStock();
        cout << "High quantity item is: " << higherStockItem->getName() << endl;
        cout << "Quantity item is: " << higherStockItem->getQuantity() << endl;
    }

    void displayTotalValue()
    {
        cout << ">>>Total value of inventory is: " << totalInventoryValue << endl;
    }

    void displayDiscount()
    {
        int select;
        cout << "_____Available Items_____:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << (i + 1) << ". " << inventoryArray[i].getName() << endl;
        }
        cout << "Select item: ";
        cin >> select;
        if (select < 1 || select > size)
        {
            cout << "Invalid selection!" << endl;
            return;
        }
        Item selectedItem = inventoryArray[select - 1];

        cout << "Item original Price : " << selectedItem.getPrice() << endl;
        cout << "Item Price after Discount : " << selectedItem.getDiscountedPrice() << endl;
    }

    void displayTotalItems()
    {
        cout << "Total items in inventory are: " << Item::getTotalItems() << endl;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

double Inventory::totalInventoryValue = 0;

int showMenu()
{
    int choice;
    cout << "\n---<<<Welcome to Inventory Management System>>>---" << endl;
    cout << "1.Input Items\n2.Output Data\n3.Filter Item\n4.Sort Items by Price\n5.Display most expensive item\n6.Display highest Quantity item\n7.Display total inventory value\n8.Dispalay total items in inventory\n9.Apply Discount on Electronics\n10.Exit" << endl;
    cin >> choice;
    cout << endl;
    return choice;
}

int main()
{
    Inventory inventory;
    int choice;

    do
    {
        choice = showMenu();

        if (inventory.isEmpty() && choice != 1)
        {
            cout << "Please add items first before performing this action!" << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            inventory.inputData();
            break;
        case 2:
            inventory.outputData();
            break;
        case 3:
            inventory.filterItems();
            break;
        case 4:
            inventory.sortItems();
            break;
        case 5:
            inventory.displayMostExpensive();
            break;
        case 6:
            inventory.displayHighestStock();
            break;
        case 7:
            inventory.displayTotalValue();
            break;
        case 8:
            inventory.displayTotalItems();
            break;
        case 9:
            inventory.displayDiscount();
            break;
        case 10:
            cout << ">>>_Exiting program. Goodbye__!!!" << endl;
            break;
        default:
            cout << "Invalid choice!!!" << endl;
            break;
        }

    } while (choice != 10);

    return 0;
}