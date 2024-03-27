#include <iostream>
#include <iomanip>
#include "lab8.h"
using namespace std;


void printOrderArray(const Order* orderArray, int size){
    cout << "================================================================================" << endl;
    cout << left << setw(12) << "Order id"
	     << left << setw(12) << "Show id"
	     << left << setw(12) << "Number"
	     << "Priority" << endl;
    cout << "================================================================================" << endl;
    // TODO
    /* Task 1: print order array by pointer arithmetic
    orderArray: first element of orderArray
    size: the size of orderArray
    */
   const Order* x = orderArray;
   for(int i = 0; i < size ; i++) {
       
       cout << left << setw(12) << (x+i)->order_id 
	     << left << setw(12) << (x+i)->show_id
	     << left << setw(12) << (x+i)->ticket_cnt
	     << (x+i)->priority << endl;
   }
}


void sortByPriority(Order* orderPtrArray[], int size){
    // TODO
    /* Task 2:  sort orders by priority via an array of pointer to orderArray
    orderPtrArray: an array of pointers to items of orderArray
    size: the size of orderPtrArray
    */
    Order* neworderPtrArray[MAX_ORDER_NUM] = {};
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(orderPtrArray[i]->priority){
           neworderPtrArray[count++] = orderPtrArray[i];
           orderPtrArray[i] = nullptr;
        }
    }
    for(int i = 0; i < size; i++){
        if(orderPtrArray[i] != nullptr){
            neworderPtrArray[count++] = orderPtrArray[i];
            orderPtrArray[i] = nullptr; 
        }
    }
    for(int i = 0; i < size; i++){
        orderPtrArray[i] = neworderPtrArray[i];
    }
}


void priorityTicketing(Show showList[], Order* orderPtrArray[], int size){
    // TODO
    /* Task 3: sell tickets based on priority
    showList: array of Show object
    orderPtrArray: sorted order pointer array of pointers to orderArray
    size: the size of orderPtrArray
    */
    Show* fig = showList;
    
    for(int i = 0; i< size; i++){
        if( showList[orderPtrArray[i]->show_id].stock_cnt >= orderPtrArray[i]->ticket_cnt ) {
            orderPtrArray[i]->finished = true;
            showList[orderPtrArray[i]->show_id].stock_cnt -= orderPtrArray[i]->ticket_cnt;
        }
    }
}