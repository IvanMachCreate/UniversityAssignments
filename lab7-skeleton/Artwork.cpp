#include <iostream>
#include <string.h>
#include <iomanip>
#include "DataStructure.h"
using namespace std;


Artwork* newArtwork(const int a_num, const char a_title[ARTWORK_NAME_MAX_LENGTH+1], const char a_author[ARTWORK_NAME_MAX_LENGTH+1], const int a_year, const int a_l_price) {
    // TODO 1:
	// create a node for an artwork 
	// set its number, title, author, year, lowest price and initiate the winning bidder pointer accordingly
	// input validation is not needed
	// return the pointer of the new node
	Artwork* some = new Artwork;
	some->num = a_num;
	strcpy(some->title , a_title);
	strcpy(some->author, a_author);
	some->year = a_year;
	some->l_price = a_l_price;
	some->winning_bidder = nullptr;
	return some;
}

void insertArtwork(Artwork* a_array[], Artwork* a, const int pos) {
	// TODO 2: 
	// insert the artwork into the array of artwork collection list
	a_array[pos] = a;
}

void listArtworkInfo(const Artwork* const a_array[]) {
	cout << left << setw(8) << "Number";
	cout << left << setw(35) << "Title";
	cout << left << setw(20) << "Author";
	cout << left << setw(6) << "year";
	cout << "Starting Price" << endl;
    // TODO 3: 
	// display all artworks in the current inventory
	// the information include the artwork number, title, author, year and starting price
	// "left << setw(N)" is used to fix the output length
	// you can refer to the output example in the lab page to get more details about the output format
	// note that you need to skip the artworks sold in the previous rounds
	for (int i = 0; i<20; i++) {
		if (a_array[i] == nullptr) {
			continue;
		}
		cout << left << setw(8) << a_array[i]->num;
		cout << left << setw(35) << a_array[i]->title;
		cout << left << setw(20) << a_array[i]->author;
		cout << left << setw(6) << a_array[i]->year;
		cout << a_array[i]->l_price << endl;
	}

}

void showAuctionResults(const Artwork* const a_array[]) {
	cout << left << setw(8) << "Number";
	cout << left << setw(35) << "Title";
	cout << left << setw(17) << "Winning Bidder";
	cout << "Deal Price" << endl;
	// TODO 4:
	// display the artworks that were successfully sold in the current round
	// the information include the artwork number, title, winning bidder and the deal price
	// note that you need to skip the artworks that have been sold in previous auction rounds and those that have not been successfully sold
	// "left << setw(N)" is used to fix the output length
	// you can refer to the output example in the lab page to get more details about the output format
	for (int i = 0; i< 20; i++) {
		if(a_array[i]== nullptr) {
			continue;
		}
		if (a_array[i]->winning_bidder != nullptr) {
			cout << left << setw(8) << a_array[i]->num;
			cout << left << setw(35) << a_array[i]->title;
			cout << left << setw(17) << a_array[i]->winning_bidder->name;
			cout << a_array[i]->winning_bidder->price << endl;
		}
		
	}
}

void removeSoldArtworks(Artwork* a_array[]) {
	// TODO 5:
	// remove the artworks that were sold in the current round
	// i.e., delete the allocated memory and set the pointer to null
	for (int i = 0; i< 20; i++) {
		if(a_array[i]!= nullptr){
			if (a_array[i]->winning_bidder != nullptr) {
			delete a_array[i];
			a_array[i] = nullptr;
			}
		}
		
	}
}

bool isInventoryEmpty(const Artwork* const a_array[]) {
	// TODO 6:
	// check whether the current artwork inventory is empty, i.e., all the elements of the artwork array list are null pointers
	// return true if is empty, or return false if is not empty
	for (int i = 0; i< 20; i++) {
		if (a_array[i] != nullptr) {
			return false;
		}
		
	}
	return true;
}
