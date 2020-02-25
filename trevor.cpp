#include <iostream>
#include <vector>

using namespace std;

/// <summary>Class for a standard Hotel Room.  Contains private bedroom & bathroom variables and a function which calculates the prive</summary>
class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms(bedrooms), bathrooms(bathrooms) {}

    /// <summary>Calculates the cost of the room as a function of bedrroms & bathrooms</summary>
    /// <returns>Cost of the room</returns>
    virtual int getprice() {
        return 50*bedrooms + 100bathrooms;
    }
private:
    int bedrooms;
    int bathrooms_;
};

/// <summary>Class for a hotel apartment which inherits the standard hotel room class</summary>
class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

    /// <summary>Calculates the cost of the apartment using standard hotel room price function</summary>
    /// <returns>Cost of the room</returns>
    virtual int get_price() {
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
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