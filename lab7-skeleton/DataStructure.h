#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_


const int BIDDER_NAME_MAX_LENGTH = 10;
const int ARTWORK_NAME_MAX_LENGTH = 100;
const int BIDDER_TOTAL_NUM = 5;
const int ARTWORK_TOTAL_NUM = 20;

struct Bidder {
    char name[BIDDER_NAME_MAX_LENGTH];  // name of the bidder
    int artwork_num;  // number of the artwork that the bidder wants to buy
    int price;  // offering price of the bidder
};

struct Artwork {
	int num;  // number of the artwork
	char title[ARTWORK_NAME_MAX_LENGTH];  // title of the artwork
	char author[ARTWORK_NAME_MAX_LENGTH];  // author of the artwork
	int year;  // year of the artwork
	int l_price;  // lowest price of the artwork
	Bidder* winning_bidder;  // winning bidder of the artwork
};

Artwork* newArtwork(const int a_num, const char a_title[ARTWORK_NAME_MAX_LENGTH+1], const char a_author[ARTWORK_NAME_MAX_LENGTH+1], const int a_year, const int a_l_price);
void insertArtwork(Artwork* a_array[], Artwork* a, int pos);
void listArtworkInfo(const Artwork* const a_array[]);
Bidder* newBidder(const char b_name[BIDDER_NAME_MAX_LENGTH+1], const int b_artwork_num, const int b_price);
void insertBidder(Bidder* b_array[], Bidder* b, const int pos);
void updateBiddingInfo(Bidder* bidder, const int b_artwork_num, const int b_price);
void simulateAuction(Artwork* a_array[], Bidder* b_array[]);
void showAuctionResults(const Artwork* const a_array[]);
void removeSoldArtworks(Artwork* a_array[]);
bool isInventoryEmpty(const Artwork* const a_array[]);
void releaseAllMemory(Artwork* a_array[], Bidder* b_array[]);

#endif /* DATASTRUCTURE_H_ */
