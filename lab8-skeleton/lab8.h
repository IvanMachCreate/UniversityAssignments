
const int MAX_ORDER_NUM = 100; // max number of orders buffer
const int MAX_LEN_SHOW_NAME = 50; // max length of show name
const int MAX_SHOW_NUM = 100; // max number of shows buffer

struct Order
{
    int order_id; // id of the order
    int show_id; // id of the show the customer wants to watch
    int ticket_cnt; // number of tickets to buy
    bool priority; // priority of booking (true if the customer buys priority booking service)
    bool finished; // true if the customer has purchased the tickets
};

struct Show
{
    int show_id; // id of the show
    char name[MAX_LEN_SHOW_NAME]; // name of the show
    int price; // price of a ticket
    int stock_cnt; // remaining number of tickets to sell
};

// helper functions
// initialize show information by reading a txt file
int initShowList(Show []);
// print information of shows
void printShowInfo(const Show [], int);
// print order_id of sorted orders
void printSortedResults(const Order* const [],int);
// print id of finished orders
void printFinishedOrder(const Order* const [],int);


// Lab 8 tasks in lab8.cpp
void printOrderArray(const Order*, int);
void sortByPriority(Order* [], int);
void priorityTicketing(Show [],Order* [], int);
