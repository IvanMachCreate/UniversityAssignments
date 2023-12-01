// === Region: Project Overview ===
//
//  COMP2011 Spring 2023
//  PA3: Simplified Retail Management System
//
//  Your name: Mach Ka Wing Ivan
//  Your ITSC email: kwimach@connect.ust.hk
//
//  Project TA: CHUNG, Peter (cspeter@cse.ust.hk)
//
//  For code-level questions, please send a direct email to the above TA.
//  Asking questions with code  in a public discussion forum (e.g., Piazza) may cause plagiarism issues
//  Usually, you will get the quickest response via a direct email.
//
// =====================================

// === Region: Header files ===
// Necessary header files are included,
// DO NOT include extra header files
// ============================
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int MAX_NUM_SHOPPING_CARTS = 10; // at most 10 shopping carts
const int MAX_ID = 10;     // at most 10 characters (including the NULL character)
const int MAX_TITLE = 100; // at most 100 characters (including the NULL character)

// A sorted linked list of StockItem, sorted by its id
struct StockItem
{
    char id[MAX_ID];           // id is a unique identifier of the StockItem (e.g., item001)
    char title[MAX_TITLE];     // title is a description of the StockItem (e.g., Milk)
    unsigned int priceInCents; // Price in cents. double/float is not used to avoid precision problems
    StockItem *next;           // The pointer pointing to the next StockItem
};

// A sorted linked list represents a shopping cart, sorted by item->id
struct ShoppingCartItem
{
    unsigned int quantity;  // A number of items
    const StockItem *item;  // A pointer pointing to the StockItem
    ShoppingCartItem *next; // The pointer pointing to the next ShoppingCartItem
};

// The following are helper functions
/*Create a stockItem*/
StockItem *create_Stock(const char Nid[MAX_ID], const char Ntitle[MAX_TITLE], const unsigned int NpriceInCents)
{
    StockItem *new_Stock = new StockItem;
    strncpy(new_Stock->id, Nid, 10);
    strncpy(new_Stock->title,Ntitle,10);
    new_Stock->priceInCents = NpriceInCents;
    new_Stock->next = nullptr;
    return new_Stock;
}
/* You create a shopping cart */
ShoppingCartItem *create_ShoppingCartItem(const unsigned int Nquantity, const StockItem *Nitem)
{
    ShoppingCartItem *NCart = new ShoppingCartItem;
    NCart->quantity = Nquantity;
    NCart->item = Nitem;
    NCart->next = nullptr;
    return NCart;
}

/*determine if you find the Item id */
bool found_Stock_Item(StockItem *&targets, const char Fid[MAX_ID])
{
    for (; targets != nullptr; targets = targets->next)
    {
        if (strcmp(Fid, targets->id) == 0)
        {
            return true;
        }
    }
    return false;
}
/* determine if you find the cart */
bool found_Cart(ShoppingCartItem *&targets, const char Fid[])
{
    for (; targets != nullptr; targets = targets->next)
    {
        if (strcmp(Fid, targets->item->id) == 0)
        {
            return true;
        }
    }
    return false;
}
/**
 * function dynamic_init_shopping_cart_array creates and initializes the shopping cart array by the given number of shopping cart
 * @param numOfShoppingCart: The number of shopping cart. You can assume the value is valid
 * 
 * @return a dynamic array of pointers. By default, each array entry is pointing to nullptr
*/
ShoppingCartItem **dynamic_init_shopping_cart_array(const unsigned int numOfShoppingCart)
{
    ShoppingCartItem **cartArray = new ShoppingCartItem *[numOfShoppingCart];
    for (int i = 0; i < numOfShoppingCart; i++)
    {
        cartArray[i] = nullptr;
    }
    return cartArray;
}

/**
 * function ll_print_all prints all the linked lists in the system
 * This function is given. You don't need to make further changes, but you need to make sure that the functions you implemented will not break this function
 * For example, this function may crash if you do not implement the linked lists correctly in the remaining functions
 * 
 * @param stockItemHead points to the head of the StockItem linked list
 * @param shoppingCartItemArray points to the array of ShoppingCartItem pointer
 * @param numOfShoppingCart the number of shopping cart
*/
void ll_print_all(const StockItem *stockItemHead, ShoppingCartItem **shoppingCartItemArray, const unsigned int numOfShoppingCart)
{
    const StockItem *p;
    const ShoppingCartItem *c;
    int count, i;
    cout << "=== StockItem List (id[price]) ===" << endl;
    count = 0;
    for (p = stockItemHead; p != nullptr; p = p->next)
    {
        cout << p->id << "[$" << p->priceInCents / 100;
        cout << "." << setfill('0') << setw(2) << p->priceInCents % 100 << "]";
        if (p->next != nullptr)
            cout << " -> ";
        count++;
    }
    if (count == 0)
    {
        cout << "No items in the StockItem list";
    }
    cout << endl;

    cout << "=== StockItem titles ===" << endl;
    count = 0;
    for (p = stockItemHead; p != nullptr; p = p->next)
    {
        cout << p->id << ": " << p->title << endl;
        count++;
    }
    if (count == 0)
    {
        cout << "No StockItem titles" << endl;
    }

    cout << "=== Shopping carts ===" << endl;
    if (shoppingCartItemArray != nullptr)
    {
        for (i = 0; i < numOfShoppingCart; i++)
        {
            count = 0;
            cout << "Cart " << i << ": ";
            for (c = shoppingCartItemArray[i]; c != nullptr; c = c->next)
            {
                if (c->item != nullptr)
                {
                    cout << c->item->id << ": " << c->quantity;
                    if (c->next != nullptr)
                        cout << ", "; // except the last item, print a comma
                    count++;
                }
            }
            if (count == 0)
            {
                cout << "No items in the shopping cart" << endl;
            }
            else
            {
                cout << endl;
            }
        }
    }
}

/**
 * function ll_insert_stock_item inserts a new stock item to the stock item list
 * The linked list needs to be sorted by id.
 * For each insertion, you need to find the correct position to insert
 * 
 * @param stockItemHead points to the head of the StockItem linked list
 * @param id is the id of the new stock item
 * @param title is the title of the new stock item
 * @param priceInCents is the price (in cents) of the new stock item
 * 
 * @return true if an item is successfully inserted. Otherwise, return false
*/
bool ll_insert_stock_item(StockItem *&stockItemHead, const char id[MAX_ID], const char title[MAX_TITLE], const unsigned int priceInCents)
{
    StockItem *p = stockItemHead; // p for position
    if (found_Stock_Item(p, id))
    {
        p = stockItemHead;
        return false;
    }
    else
    {
        p = stockItemHead;
    }
    StockItem *new_stock = create_Stock(id, title, priceInCents);
    if (stockItemHead == nullptr || strcmp(id, stockItemHead->id) < 0)
    {
        new_stock->next = stockItemHead;
        stockItemHead = new_stock;
        return true;
    }
    while (p->next != nullptr)
    {
        if (strcmp(id, p->next->id) < 0)
        {
            break;
        }
        p = p->next;
    }

    new_stock->next = p->next;
    p->next = new_stock;
    return true;
}

/**
 * function ll_update_stock_item_price searches the StockItem linked list based on the id, and then updates its price
 * 
 * @param stockItemHead points to the head of the StockItem linked list
 * @param id is the id of the stock item
 * @param newPriceInCents is the new price to be updated
 * 
 * @return true if the price is successfully updated. Otherwise, return false
*/
bool ll_update_stock_item_price(StockItem *stockItemHead, const char id[MAX_ID], const unsigned int newPriceInCents)
{
    if (found_Stock_Item(stockItemHead, id))
    {
        stockItemHead->priceInCents = newPriceInCents;
        return true;
    }
    return false;
}

/**
 * function ll_insert_or_add_stock_item_quantity inserts/adds a number of stock items to a shopping cart
 * For each insertion, you need to find the correct position to insert
 * If the shopping cart item does not exist, you need to create and insert a new shopping cart item with the correct quantity
 * If the shopping cart itxem exists, you need to increase its quantity
 * 
 * @param shoppingCartHead points to the head of the ShoppingCartItem linked list
 * @param stockItemHead points to the head of the StockItem linked list
 * @param id is the id of the stock item
 * @param quantity is the quantity of the item
 * 
 * @return true if the operation is successful. Otherwise, return false
*/
bool ll_insert_or_add_stock_item_quantity(ShoppingCartItem *&shoppingCartHead, StockItem *stockItemHead, const char id[MAX_ID], const unsigned int quantity)
{
    ShoppingCartItem *p = shoppingCartHead; // p for position
    StockItem *item = stockItemHead;
    if (found_Stock_Item(item, id))
    {
    }
    else
    {
        return false;
    }
    if (shoppingCartHead == nullptr || strcmp(id, shoppingCartHead->item->id) < 0)
    {
        p = create_ShoppingCartItem(quantity, item);
        p->next = shoppingCartHead;
        shoppingCartHead = p;
        return true;
    }
    for (; p != nullptr; p = p->next)
    {
        if (strcmp(p->item->id, id) == 0)
        {
            p->quantity += quantity;
            return true;
        }
    }
    p = shoppingCartHead;
    ShoppingCartItem *new_Cart = create_ShoppingCartItem(quantity, item);
    while (p->next != nullptr)
    {
        if (strcmp(id, p->next->item->id) < 0)
        {
            break;
        }
        p = p->next;
    }
    new_Cart->next = p->next;
    p->next = new_Cart;
    return true;
}

/**
 * function ll_deduct_stock_item_quantity_from_shopping_cart deducts the quantity of the item from the shopping cart
 * 
 * If the new quantity is negative, the operation is invalid and you should not update the quantity
 * If the new quantity is positive, the operation is successful
 * If the new quantity is 0, the operation is successful and the corresponding linked list item needs to be removed from the shopping cart
 * 
 * @param shoppingCartHead points to the head of the ShoppingCartItem linked list
 * @param stockItemHead points to the head of the StockItem linked list
 * @param deductQuantity the quantity to be deducted
 * 
 * @return true if the operation is successful. Otherwise, return false
*/
bool ll_deduct_stock_item_quantity_from_shopping_cart(ShoppingCartItem *&shoppingCartHead, const char id[MAX_ID], const unsigned int deductQuantity)
{
    ShoppingCartItem *pos = shoppingCartHead;
    if (shoppingCartHead == nullptr || found_Cart(pos, id) == false)
    {
        return false;
    }
    else
    {
        int num = pos->quantity - deductQuantity;
        if (num)
        {
            if (num < 0)
            {
                return false;
            }
            else
            {
                pos->quantity = num;
                return true;
            }
        }
        else
        {
            if (pos->next == shoppingCartHead->next)
            {
                shoppingCartHead = shoppingCartHead->next;
                delete pos;
                pos = nullptr;
                return true;
            }
            else
            {
                for (ShoppingCartItem *pos_Prev = shoppingCartHead; pos_Prev->next == pos; pos_Prev = pos_Prev = pos_Prev->next)
                {
                    pos_Prev->next = pos->next;
                    delete pos;
                    pos = nullptr;
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * function ll_remove_stock_item_from_shopping_cart removes an item from the shopping cart
 * 
 * @param shoppingCartHead points to the head of the ShoppingCartItem linked list
 * @param id is the id of the stock item
 * 
 * @return true if the operation is successful. Otherwise, return false 
*/
bool ll_remove_stock_item_from_shopping_cart(ShoppingCartItem *&shoppingCartHead, const char id[MAX_ID])
{
    ShoppingCartItem *prev = nullptr;
    ShoppingCartItem *current = shoppingCartHead;
    while (current != nullptr && strcmp(id, current->item->id) != 0)
    {
        prev = current;
        current = current->next;
    }
    if (current != nullptr)
    {
        if (current == shoppingCartHead)
        {
            shoppingCartHead = shoppingCartHead->next;
        }
        else
        {
            prev->next = current->next;
        }
        delete current;
        return true;
    }
    return false; // TODO: delete this line to start your work
}

/**
 * function ll_remove_stock_item removes an item from the StockItem linked list
 * This function is a little bit tricky because you need to remove the corresponding item in all shopping carts first
 * Once you handle the removal of the shopping carts, you can remove the item from the StockItem linked list
 * 
 * @param stockItemHead points to the head of the StockItem linked list
 * @param shoppingCartItemArray points to the array of ShoppingCartItem pointer. The whole array is passed because each shopping cart may be changed.
 * @param numOfShoppingCart the number of shopping cart
 * @param id is the id of the stock item
 * 
 * @return true if the operation is successful. Otherwise, return false
*/
bool ll_remove_stock_item(StockItem *&stockItemHead, ShoppingCartItem **shoppingCartItemArray, const unsigned int numOfShoppingCart, const char id[MAX_ID])
{
    for (int i = 0; i < numOfShoppingCart; i++)
    {
        ll_remove_stock_item_from_shopping_cart(shoppingCartItemArray[i], id);
    }
    StockItem *prev = nullptr;
    StockItem *current = stockItemHead;
    while (current != nullptr && strcmp(current->id, id) != 0)
    {
        prev = current;
        current = current->next;
    }
    if (current != nullptr)
    {
        if (current == stockItemHead)
        {
            stockItemHead = stockItemHead->next;
        }
        else
        {
            prev->next = current->next;
        }
        delete current;
        return true;
    }
    return false;
}

/**
 * function calculate_total_amount_in_shopping_cart calculates the total amount in the shopping cart. 
 * 
 * @param shoppingCartHead points to the head of the ShoppingCartItem linked list
 * 
 * @return the total amount in cents
*/
unsigned int calculate_total_amount_in_shopping_cart(const ShoppingCartItem *shoppingCartHead)
{
    unsigned int sum = 0;
    for (const ShoppingCartItem *item = shoppingCartHead; item; item = item->next)
    {
        sum += item->quantity * item->item->priceInCents;
    }

    return sum; // TODO: delete this line to start your work
}
/**
 * function ll_clear_shopping_cart clears the shopping cart. This function will be invoked after calculating the total amount.
 * 
 * @param shoppingCartHead points to the head of the ShoppingCartItem linked list
 * 
*/
void ll_clear_shopping_cart(ShoppingCartItem *&shoppingCartHead)
{
    while (shoppingCartHead != nullptr)
    {
        ShoppingCartItem *temp = shoppingCartHead;
        shoppingCartHead = shoppingCartHead->next;
        delete temp;
        temp = nullptr;
    }
}

/**
 * function ll_cleanup cleans up the linked lists and dynamically allocated memory used in this system
 * No memory leak should be found after the clean up
 * 
 * @param stockItemHead points to the head of the StockItem linked list
 * @param shoppingCartItemArray points to the array of ShoppingCartItem pointer.
 * @param numOfShoppingCart the number of shopping cart
*/
void ll_cleanup(StockItem *&stockItemHead, ShoppingCartItem **&shoppingCartItemArray, const unsigned int numOfShoppingCart)
{
    for (int i = 0; i < numOfShoppingCart; i++)
    {
        ll_clear_shopping_cart(shoppingCartItemArray[i]);
    }
    while (stockItemHead != nullptr)
    {
        StockItem *temp = stockItemHead;
        stockItemHead = stockItemHead->next;
        delete temp;
        temp = nullptr;
    }
    delete[] shoppingCartItemArray;
    shoppingCartItemArray = nullptr;
}

// === Region: The main function ===
// The main function implementation is given
// DO NOT make any changes to the main function
// ============================
int main()
{
    enum MenuOption
    {
        OPTION_DISPLAY_CURRENT_LIST = 0,
        OPTION_INSERT_STOCK_ITEM,
        OPTION_UPDATE_STOCK_ITEM_PRICE,
        OPTION_INSERT_OR_ADD_STOCK_ITEM_TO_SHOPPING_CART,
        OPTION_REMOVE_STOCK_ITEM_FROM_SHOPPING_CART,
        OPTION_DEDUCT_STOCK_ITEM_FROM_SHOPPING_CART,
        OPTION_REMOVE_STOCK_ITEM_FROM_STOCK_ITEM_LIST,
        OPTION_CHECKOUT_AND_CLEAR_SHOPPING_CART,
        OPTION_EXIT_SYSTEM,
        MAX_MENU_OPTIONS
    };
    const int MAX_MENU_OPTIONS_LENGTH = 80;
    char menuOptions[MAX_MENU_OPTIONS][MAX_MENU_OPTIONS_LENGTH] = {
        "Display the current lists",
        "Insert a new stock item to the stock item list",
        "Update the price of the stock item",
        "Insert/Add a number of stock items to a shopping cart",
        "Remove an item from the shopping cart",
        "Deduct a number of stock items from a shopping cart",
        "Remove an item from the stock item list",
        "Checkout and clear a shopping cart",
        "Exit the system"};

    StockItem *stockItemHead = nullptr;
    ShoppingCartItem **shoppingCartItemArray = nullptr;
    unsigned int numOfShoppingCart = 0;
    int i, option;
    unsigned int priceInCents = 0;
    unsigned int quantity = 0;
    unsigned int deductQuantity = 0;
    unsigned int whichCart = 0;
    unsigned int totalAmount = 0;
    char id[MAX_ID] = "";
    char title[MAX_TITLE] = "";
    bool ret = false;

    cout << "=== Initialize the shopping carts ===" << endl;
    while (true)
    {
        cout << "Enter the number of shopping cart (1.." << MAX_NUM_SHOPPING_CARTS << "): ";
        cin >> numOfShoppingCart;
        if (numOfShoppingCart == 0 || numOfShoppingCart > MAX_NUM_SHOPPING_CARTS)
        {
            cout << "Invalid number of shopping cart" << endl;
            continue;
        }
        shoppingCartItemArray = dynamic_init_shopping_cart_array(numOfShoppingCart);
        break;
    }

    cout << "=== Simplified Retail System ===" << endl;
    while (true)
    {
        cout << "=== Menu ===" << endl;
        for (i = 0; i < MAX_MENU_OPTIONS; i++)
            cout << i + 1 << ": " << menuOptions[i] << endl; // shift by +1 when display

        cout << "Enter your option: ";
        cin >> option;
        option = option - 1; // shift by -1 after entering the option

        // The invalid menu option handling
        if (option < 0 || option >= MAX_MENU_OPTIONS)
        {
            cout << "Invalid option" << endl;
            continue;
        }

        // Exit operations handling
        if (option == OPTION_EXIT_SYSTEM)
        {
            ll_cleanup(stockItemHead, shoppingCartItemArray, numOfShoppingCart);
            break; // break the while loop
        }

        switch (option)
        {
        case OPTION_DISPLAY_CURRENT_LIST:
            ll_print_all(stockItemHead, shoppingCartItemArray, numOfShoppingCart);
            break;
        case OPTION_INSERT_STOCK_ITEM:
            cout << "Enter a ID: ";
            cin >> id;
            cout << "Enter a title: ";
            cin >> title;

            priceInCents = 0;
            while (priceInCents == 0)
            {
                cout << "Enter a price in cents: ";
                cin >> priceInCents;
                if (priceInCents == 0)
                {
                    cout << "Enter a positive price in cents" << endl;
                }
            }

            ret = ll_insert_stock_item(stockItemHead, id, title, priceInCents);
            if (ret == false)
            {
                cout << "Failed to insert " << id << endl;
            }
            else
            {
                cout << id << " is successfully inserted" << endl;
            }
            break;
        case OPTION_UPDATE_STOCK_ITEM_PRICE:

            cout << "Enter a ID: ";
            cin >> id;

            priceInCents = 0;
            while (priceInCents == 0)
            {
                cout << "Enter a price in cents: ";
                cin >> priceInCents;
                if (priceInCents == 0)
                {
                    cout << "Enter a positive price in cents" << endl;
                }
            }

            ret = ll_update_stock_item_price(stockItemHead, id, priceInCents);
            if (ret == false)
            {
                cout << "Failed to update the price of " << id << endl;
            }
            else
            {
                cout << id << " price is updated" << endl;
            }
            break;
        case OPTION_INSERT_OR_ADD_STOCK_ITEM_TO_SHOPPING_CART:

            while (true)
            {
                cout << "Enter a shopping cart ID (valid: 0 to " << numOfShoppingCart - 1 << "): ";
                cin >> whichCart;
                if (whichCart >= 0 && whichCart < numOfShoppingCart)
                    break;
                else
                    cout << "Please enter a valid shopping cart ID" << endl;
            }
            cout << "Enter a ID: ";
            cin >> id;
            quantity = 0;
            while (quantity == 0)
            {
                cout << "Add a quantity: ";
                cin >> quantity;
                if (quantity == 0)
                {
                    cout << "Please enter a positive quantity" << endl;
                }
            }
            ret = ll_insert_or_add_stock_item_quantity(shoppingCartItemArray[whichCart], stockItemHead, id, quantity);
            if (ret == false)
            {
                cout << "Failed to insert/update " << id << endl;
            }
            else
            {
                cout << id << " is successfully inserted/updated" << endl;
            }
            break;
        case OPTION_DEDUCT_STOCK_ITEM_FROM_SHOPPING_CART:

            while (true)
            {
                cout << "Enter a shopping cart ID (valid: 0 to " << numOfShoppingCart - 1 << "): ";
                cin >> whichCart;
                if (whichCart >= 0 && whichCart < numOfShoppingCart)
                    break;
                else
                    cout << "Please enter a valid shopping cart ID" << endl;
            }
            cout << "Enter a ID: ";
            cin >> id;
            deductQuantity = 0;
            while (deductQuantity == 0)
            {
                cout << "Deduct a quantity: ";
                cin >> deductQuantity;
                if (deductQuantity == 0)
                {
                    cout << "Please enter a positive quantity" << endl;
                }
            }
            ret = ll_deduct_stock_item_quantity_from_shopping_cart(shoppingCartItemArray[whichCart], id, deductQuantity);
            if (ret == false)
            {
                cout << "Failed to deduct quantity " << id << endl;
            }
            else
            {
                cout << "Quantity of " << id << " is successfully deducted" << endl;
            }
            break;
        case OPTION_REMOVE_STOCK_ITEM_FROM_SHOPPING_CART:
            while (true)
            {
                cout << "Enter a shopping cart ID (valid: 0 to " << numOfShoppingCart - 1 << "): ";
                cin >> whichCart;
                if (whichCart >= 0 && whichCart < numOfShoppingCart)
                    break;
                else
                    cout << "Please enter a valid shopping cart ID" << endl;
            }
            cout << "Enter a ID: ";
            cin >> id;
            ret = ll_remove_stock_item_from_shopping_cart(shoppingCartItemArray[whichCart], id);
            if (ret == false)
            {
                cout << "Failed to remove goods " << id << endl;
            }
            else
            {
                cout << id << " is successfully removed" << endl;
            }
            break;
        case OPTION_REMOVE_STOCK_ITEM_FROM_STOCK_ITEM_LIST:
            cout << "Enter a ID: ";
            cin >> id;
            ret = ll_remove_stock_item(stockItemHead, shoppingCartItemArray, numOfShoppingCart, id);
            if (ret == false)
            {
                cout << "Failed to remove " << id << " from the goods list" << endl;
            }
            else
            {
                cout << id << " is removed from the goods list" << endl;
            }
            break;
        case OPTION_CHECKOUT_AND_CLEAR_SHOPPING_CART:
            while (true)
            {
                cout << "Enter a shopping cart ID (valid: 0 to " << numOfShoppingCart - 1 << "): ";
                cin >> whichCart;
                if (whichCart >= 0 && whichCart < numOfShoppingCart)
                    break;
                else
                    cout << "Please enter a valid shopping cart ID" << endl;
            }
            totalAmount = calculate_total_amount_in_shopping_cart(shoppingCartItemArray[whichCart]);
            if (totalAmount > 0)
            {

                cout << "Please pay for $" << totalAmount / 100;
                cout << "." << setfill('0') << setw(2) << totalAmount % 100 << endl;
            }
            else
            {
                cout << "You don't need to pay!" << endl;
            }
            ll_clear_shopping_cart(shoppingCartItemArray[whichCart]);
            cout << "The shopping cart " << whichCart << " is cleared" << endl;
            break;
        default:
            break;

        } // end of switch (option)
    }

    return 0;
}
