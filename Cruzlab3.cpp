#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

/*
Instructions:
Create a class, Heater that contains an integer data member called temperature. Define a
constructor that takes no parameters. The temperature data member should be set to 15 in the
constructor. Define two member functions, warmer and cooler, whose effect is to increase or
decrease the value of temperature by 5 respectively, these are called mutators. Define a getter
function (accessor), called getTemp() that will return the value of temperature.
*/

// Nate Cruz 2021

class Heater {
    private:
        int temperature;

    public:
        Heater(); // Constructor to set temperature to 15
        void warmer(); // Increase temperature by 5
        void cooler(); // Decrease temperature by 5
        int getTemp(); // Return temperature
};

// Heater Methods
Heater::Heater() {
    temperature = 15;
}

void Heater::warmer() {
    temperature += 5;
}

void Heater::cooler() {
    temperature -= 5;
}

int Heater::getTemp() {
    return temperature;
}

int main() {
    Heater heat;
    char choice;
    while (choice != '0') {
        system("cls");
        cout << "Heater Temperature: " << heat.getTemp() << endl;
        cout << "1. Set warmer" << endl;
        cout << "2. Set cooler" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.clear(); // Cleaning of unnecessary extra inputs
        fflush(stdin);

        switch (choice) {
            case '1':
                heat.warmer();
                break;
            case '2':
                heat.cooler();
                break;
            case '0':
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                getch();
                break;
        }
    }
    cout << "Exiting program..." << endl;
    getch();

    return 0;
}
