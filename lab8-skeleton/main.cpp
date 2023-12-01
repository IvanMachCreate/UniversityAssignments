#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include "lab8.h"
using namespace std;


int initShowList(Show showList[]) {
    int show_id; // id of the show
    char name[MAX_LEN_SHOW_NAME]; // name of the show
    int stock_cnt; // remaining number of tickets to sell
    int price; // price of a ticket
    ifstream fin("shows.txt");

    string line;
    string fields[4];
    int counter = 0;
    while (getline(fin, line)) {
        int i = 0;
        size_t pos = 0;
        while ((pos = line.find(',')) != string::npos) {
            fields[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        fields[i] = line;

        showList[counter].show_id = stoi(fields[0]);
        strcpy(showList[counter].name, fields[1].c_str());
        showList[counter].price =  stoi(fields[2]);
        showList[counter].stock_cnt = stoi(fields[3]);
        counter++;
    }
    
    return counter;
}

void printShowInfo(const Show showList [], int num_of_shows){
    cout << "================================================================================" << endl;
    cout << left << setw(10) <<"ID";
    cout << left << setw(50) << "Show Name";
    cout << left << setw(10)<< "Price";
    cout << "STOCK" << endl;
    cout << "================================================================================" << endl;
    for (int i=0; i<num_of_shows; i++) {
        cout << left << setw(10) << showList[i].show_id;
        cout << left << setw(50) << showList[i].name;
        cout << left << setw(10) << showList[i].price;
        cout << showList[i].stock_cnt << endl;
    }
    cout << "================================================================================" << endl;
}

void printSortedResults(const Order* const orderPtrArray[],int size){
    cout << "================================================================================" << endl;
    cout<<"The order_id of sorted results (Task 2): "<<endl;
    for (int i=0;i<size;++i){
        cout<<orderPtrArray[i]->order_id<<endl;
    }
    cout << "================================================================================" << endl;
}

void printFinishedOrder(const Order* const orderPtrArray[],int size){
    cout<<"The order_id of finished orders (Task 3): "<<endl;
    for (int i=0;i<size;++i){
        if (orderPtrArray[i]->finished){
            cout<<orderPtrArray[i]->order_id<<endl;
        }
    }
}

int main(){
    Show showList[MAX_SHOW_NUM];
    int num_of_shows;
    num_of_shows = initShowList(showList);

    Order orderArray[MAX_ORDER_NUM];
    Order* orderPtrArray[MAX_ORDER_NUM] = {};
    int order_id = 0;
    int opt;
    int num_of_orders = 0;

    char input_flag = 'y';
    do {
		cout << "************* WELCOME TO TICKETING SYSTEM *************" << endl;
		cout << endl << "Operation Menu:" << endl;
		cout << "1. Display informaion of shows." << endl;
		cout << "2. Ticket Booking." << endl;
		cout << "3. For sale." << endl;
		cout << "4. Exit." << endl;
		cout << endl << "Please choose your operation: ";
		cin >> opt;
        
        cout<<endl;
		switch(opt){
			case 1:
				printShowInfo(showList, num_of_shows);
				cout << "\n" << endl;
				break;

			case 2:
                do{
                    Order order_item;
                    char priority_choice;
                    order_item.order_id=order_id;
                    cout << "Please enter the id of the show you want to watch: ";
                    cin >> order_item.show_id;
                    cout<<endl;
                    cout << "How many tickets do you want to purchase? ";
                    cin >> order_item.ticket_cnt;
                    cout<<endl;
                    cout << "Do you want priority booking? [y/n]: ";
                    cin >> priority_choice;
                    cout<<endl;

                    if (priority_choice == 'y')
                        order_item.priority = true;
                    else if (priority_choice == 'n')
                        order_item.priority = false;
                    else {
                        cout << "Unrecognized symbol." << endl;
                        break;
                    }

                    order_item.finished=false;
                    orderArray[order_id++]=order_item;
                    cout << "Do you want to continue with a new order? [y/n]: ";
                    cin >> input_flag;
                    cout << endl;
                } while(input_flag == 'y');

                cout << "Orders Information (Task 1): " << endl;
                // Task 1: print order array by pointer arithmetic
                num_of_orders = order_id;
                printOrderArray(orderArray, num_of_orders);
                cout << "================================================================================" << endl;
                cout << "\n" << endl;
				break;

			case 3:
                for (int i=0; i<num_of_orders; i++){
                    orderPtrArray[i] = &orderArray[i];
                }
                
                // Task 2: sort orders by priority
                sortByPriority(orderPtrArray, num_of_orders);

                // print order_id of sorted orders
                printSortedResults(orderPtrArray,num_of_orders);
                
                // Task 3: ticketing by priority
                priorityTicketing(showList, orderPtrArray,num_of_orders);
                
                // print id of finished orders
                printFinishedOrder(orderPtrArray,num_of_orders);
                break;

            case 4:
                break;

            default:
                cout << "Unrecognized symbol, enter again." << endl;
				break;
		}

	} while (opt != 4 && opt!=3);

	cout << "*********************** END OF TICKETING SYSTEM ***********************" << endl;

    return 0;
}
