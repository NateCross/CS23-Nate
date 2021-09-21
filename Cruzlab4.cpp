#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

/*
Instructions:
Modify your Heater class to define three new integer data members: min, max, and increment.
The values of min and max should be set by parameters passed to the constructor. The value of
increment should be set to 5 in the constructor. Modify the definitions of warmer and cooler so
that they use the value of increment rather than an explicit value of 5. Before proceeding further,
check that everything works as before. Now modify warmer so that it will not allow the value of
temperature to exceed the value of max. Similarly modify cooler so that it will not allow the
value of temperature to be set below the value of min. Check that the class works properly.
Now add a member function, setIncrement that takes an integer parameter and uses it to set
the value of increment. Once again, test that the class works as you would expect it to, by
creating some Heater objects. Add a check to the setIncrement function to prevent a negative
value from being assigned to increment.
*/

// Nate Cruz 2021

class Heater {
    private:
        int temperature, minTemp, maxTemp, increment;

    public:
        Heater(int minInput, int maxInput); // Constructor to set temperature to 15 and init parameters
        void warmer(); // Increase temperature by increment
        void cooler(); // Decrease temperature by increment
        int getTemp(); // Return temperature
        void setIncrement(int input);
};

// Heater Methods
Heater::Heater(int minInput, int maxInput) {
    temperature = 15;
    increment = 5;

    minTemp = minInput;
    maxTemp = maxInput;
}

void Heater::warmer() {
    if (temperature + increment <= maxTemp)
        temperature += increment;
    else {
        cout << "ERROR: You have exceeded the maximum." << endl << "Press Enter to continue." << endl;
        getch();
    }
    return;
}

void Heater::cooler() {
    if (temperature - increment >= minTemp)
        temperature -= increment;
    else {
        cout << "ERROR: You have exceeded the minimum." << endl << "Press Enter to continue." << endl;
        getch();
    }
    return;
}

int Heater::getTemp() {
    return temperature;
}

void Heater::setIncrement(int input) {
    if (input >= 0)
        increment = input;
    else {
        cout << "ERROR: Negative input. Please input a non-negative integer." << endl;
        cout << "Press Enter to continue." << endl;
        getch();
    }
    return;
}

int main() {
    Heater heat(0, 100);
    char choice;
    int dataInput;
    while (choice != '0') {
        system("cls");
        dataInput = 0; // For cleaning dataInput after a loop
        cout << "Heater Temperature: " << heat.getTemp() << endl;
        cout << "1. Set warmer" << endl;
        cout << "2. Set cooler" << endl;
        cout << "3. Set increment" << endl;
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
            case '3':
                cout << "Enter value of increment: ";

                cin >> dataInput;
                cin.clear(); // Cleaning of unnecessary extra inputs
                fflush(stdin);

                heat.setIncrement(dataInput);
                break;
            case '0':
                break;
            default:
                cout << "ERROR: Invalid choice." << endl << "Press Enter to continue." << endl;
                getch();
                break;
        }
    }
    cout << "Exiting program..." << endl;
    getch();

    return 0;
}
