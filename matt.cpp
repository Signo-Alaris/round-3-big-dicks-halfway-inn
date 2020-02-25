#include <iostream>
#include <vector>
#include <assert.h> 

using namespace std;

class HotelRoom {
public:
	HotelRoom(int bedrooms, int bathrooms)
	{
		//Exception check block to check arguments:
		try {
			if (bedrooms >= 0) {
				bedrooms_ = bedrooms;
			}
			else throw "\n# bedrooms can't be negative!\n";
			if (bathrooms >= 0) {
				bathrooms_ = bathrooms;
			}
			else throw "\n# bathrooms can't be negative!\n";
		}
		catch (const char* msg) {
			cerr << msg << endl;	//Spit the error message to console.
			assert(bedrooms >= 0);	//Assertion will terminate execution,
			assert(bathrooms >= 0);	//and also return line number in console.
		}
		//Output to console:
		cout << "\n# Bedrooms: " << bedrooms_;
		cout << "\n# Bathrooms: " << bathrooms_;
	}

	virtual int get_price() {
		cout << "\nHotelroom" << 50 * bedrooms_ + 100 * bathrooms_ <<"\n";
		return 50 * bedrooms_ + 100 * bathrooms_;
	}

private:
	int bedrooms_;
	int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
	using HotelRoom::HotelRoom;	//C++11 let's us inherit the parent's constructors like so.

	int get_price() {
		cout << "\nHotel Apartment" << HotelRoom::get_price() + 100 <<"\n";

		return HotelRoom::get_price() + 100;
	}
};

int main() {
	int n;
	cin >> n;
	vector<HotelRoom*> rooms;
	for (int i = 0; i < n; ++i) {
		string room_type;
		int bedrooms;
		int bathrooms;
		cin >> room_type >> bedrooms >> bathrooms;
		
		if (room_type == "standard") {
			rooms.push_back(new HotelRoom(bedrooms, bathrooms));
		}
		else {
			rooms.push_back(new HotelApartment(bedrooms, bathrooms));
		}
	}

	int total_profit = 0;

	for (auto room : rooms) {
		total_profit += room->get_price();
	}

	cout << total_profit << endl;

	for (auto room : rooms) {
		delete room;
	}
	rooms.clear();

	return 0;
}