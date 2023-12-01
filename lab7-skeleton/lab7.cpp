#include <iostream>
#include <fstream>
#include <string>
#include "DataStructure.h"
using namespace std;
const char *bidder_list[] = { "Amy", "Sebrina", "Kevin", "Alan", "Sebastian" };


int main() {
	// Load all the artworks
	ifstream file("ArtworkCollection.csv");
    string line;
    Artwork* artworkList[ARTWORK_TOTAL_NUM];

    string fields[4];
    int counter = 0;
    while (getline(file, line)) {
        int i = 0;
        size_t pos = 0;
        while ((pos = line.find(',')) != string::npos) {
            fields[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        fields[i] = line;

		Artwork* artworkNode = newArtwork(counter+1, fields[0].c_str(), fields[1].c_str(), stoi(fields[2]), stoi(fields[3]));
		insertArtwork(artworkList, artworkNode, counter);
        counter++;
    }

	// Initialize all the bidders
	Bidder* bidderList[BIDDER_TOTAL_NUM];
	int bidder_artwork_number;
	int bidder_artwork_price;

	for (int c=0; c<BIDDER_TOTAL_NUM; c++) {
		Bidder* bidderNode = newBidder(bidder_list[c], 0, 0);
		insertBidder(bidderList, bidderNode, c);
	}

	// Now start the simulation of auction process
	cout << "******************** WELCOME TO THE GALLERY AUCTION SYSTEM ********************" << endl;
	int round_counter = 0;
	int opt = 1;

	// while(true) 
    do
    {
		cout << endl << "Welcome to auction round " << ++round_counter << endl;
		cout << endl << "The following table shows the artworks for bidding in the current round: " << endl;
		cout << "----------------------- Artwork Collection Information ----------------------" << endl;
		listArtworkInfo(artworkList);
		cout << "-----------------------------------------------------------------------------\n" << endl;
		
		cout << "Welcome all the bidders: Amy, Sebrina, Kevin, Alan and Sebastian. " << endl;
		cout << "Now you can bid on your favourite artworks!" << endl;
		for (int c=0; c<BIDDER_TOTAL_NUM; c++) {
			cout << "Hi, " << bidder_list[c] << "!" << endl;
			cout << ">>> Please enter the number of the artwork you want to buy: ";
			cin >> bidder_artwork_number;
			cout << ">>> Please enter your offering price [an integer n (thousand HKD)]: ";
			cin >> bidder_artwork_price;
			updateBiddingInfo(bidderList[c], bidder_artwork_number, bidder_artwork_price);
		}

		simulateAuction(artworkList, bidderList);
		cout << endl << "The following table shows the the auction results of this round: " << endl;
		cout << "------------------------------- Auction Results -----------------------------" << endl;
		showAuctionResults(artworkList);
		cout << "-----------------------------------------------------------------------------\n" << endl;
		removeSoldArtworks(artworkList);

		if (isInventoryEmpty(artworkList)) {
			break;
		}

		cout << "Please enter 0 to quit, or 1 to continue: ";
		cin >> opt;
	} while (opt != 0);

	releaseAllMemory(artworkList, bidderList);

	cout << "******************************* END OF THE AUCTION *****************************" << endl;

	return 0;
}
