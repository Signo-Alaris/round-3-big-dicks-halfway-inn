#include <iostream>
#include <vector>

using namespace std;

// The following #if statement is a preprocessor definition, allows you to pre-process code, for this example we can test two implementations in our code but with one actually being compiled. Depends if the #if statement is true or false.
// The first will be an obvious approach using the "protected" access modifier,
// the second using "virtual" and "override" keywords, very useful in object orientated code. 

#if 0 // Most obvious approach
class HotelRoom 
{
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : m_price((50*bedrooms) + (100*bathrooms)) {}

    int get_price()
    {
        return m_price;
    }
protected: // Protected means only accessable by itself and child inheritence classes
    int m_price;
};

class HotelApartment : public HotelRoom 
{
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) 
    {
        m_price += 100;
    }  
};

#else // Using virtual and override
class HotelRoom 
{
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : m_bedrooms(bedrooms), m_bathrooms(bathrooms) {}
    
    virtual int get_price() 
    {
        return 50*m_bedrooms + 100*m_bathrooms;
    }
private:
    int m_bedrooms;
    int m_bathrooms;
};

class HotelApartment : public HotelRoom 
{
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

    int get_price() override
    {
        return this->HotelRoom::get_price() + 100;
    }
};
#endif

int main() 
{
    int n;
    cin >> n;
    vector<HotelRoom*> rooms; // Note we are only keeping HotelRoom* objects
    for (int i = 0; i < n; ++i) 
    {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") 
        {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } 
        else 
        {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) 
    {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) 
    {
        delete room;
    }
    rooms.clear();

    return 0;
}