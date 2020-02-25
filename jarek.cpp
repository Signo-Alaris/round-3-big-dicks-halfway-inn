#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    
    virtual int get_price() {
        const int total_room_price = calculate_base_room_price();
        return total_room_price;
    }
protected:
    virtual int calculate_base_room_price() {
        const int base_price = (bedrooms_ * BEDROOM_PRICE) + (bathrooms_ * BATHROOM_PRICE);
        return base_price;
    }
    
    const int BEDROOM_PRICE = 50;
    const int BATHROOM_PRICE = 100;
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

    int get_price() override {
        const int total_apt_price = calculate_base_room_price() + ADDITIONAL_APT_CHARGE;
        return total_apt_price;
    }
private:
    const int ADDITIONAL_APT_CHARGE = 100;
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