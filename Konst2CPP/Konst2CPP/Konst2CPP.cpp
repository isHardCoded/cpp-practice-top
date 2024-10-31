#include <iostream>
using namespace std;

class House {
private:
    int rooms;
    double s;
    string year;
    string address;

public:
    
    House(int valueRooms, double valueS, string valueYear, string valueAddress) {
        rooms = valueRooms;
        s = valueS;
        year = valueYear;
        address = valueAddress;
    }

    void DisplayInfo() {
        cout << rooms << endl << s << endl << year << endl << address;
    }

    static House InputInfo() {
        int rooms;
        double s;
        string year;
        string address;

        cout << "Введите кол-во комнат: " << endl;
        cin >> rooms;

        cin >> s;
        cin >> year;
        cin >> address;

        return House(rooms, s, year, address);
    }

    ~House() {
        cout << "Object was removed" << endl;
    }
};


int main()
{
    
    House house1 = House::InputInfo();
    house1.DisplayInfo();

}
