#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

// Nate Cruz 2021

class Rectangle {
    private:
        double length = 1.0, width = 1.0;

    public: // For the methods
        double getLength() {
            return length;
        }
        double getWidth() {
            return width;
        }
        void setLength(double l) {
            if (l >= 0.0 && l < 20.0) {
                length = l;
                cout << "Length set." << endl;
            }
            else
                cout << "Value must be between \"0.0\" to \"20.0\". Please try again." << endl;
                getch();
            return;
        }
        void setWidth(double w) {
            if (w >= 0.0 && w < 20.0) {
                width = w;
                cout << "Width set." << endl;
            }
            else
                cout << "Value must be between \"0.0\" to \"20.0\". Please try again." << endl;
                getch();
            return;
        }
        double calcPerimeter() {
            return 2 * (length + width);
        }
        double calcArea() {
            return length * width;
        }
};

int main() {
    char choice;
    double data;
    Rectangle box;
    while (choice != '0') {
        system("cls");
        data = 0.0;
        cout << "Your rectangle's length: " << box.getLength() << endl;
        cout << "Your rectangle's width: " << box.getWidth() << endl;
        cout << "Perimeter: " << box.calcPerimeter() << endl;
        cout << "Area: " << box.calcArea() << endl << endl;

        cout << "1. Set Length" << endl;
        cout << "2. Set Width" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.clear(); // Because I made choice a char to account for users typing letters, if I were to write "12" it would do choice 1 then input 2 for the next cin.
        fflush(stdin); // This and the above line fixes this bug. I hope this doesn't have any more unintended side effects...

        switch (choice) {
            case '1':
                cout << "Length: ";
                cin >> data;

                //The following block is for error handling, in case the user inputs a character
                if (!cin.fail())
                    box.setLength(data);
                else {
                    cin.clear(); // Without clear and ignore, the console seems to bug, so here it shall stay to flush cin
                    cin.ignore();
                    cout << "Incorrect input. Please try again." << endl;
                    getch();
                }

                break;
            case '2':
                cout << "Width: ";
                cin >> data;

                if (!cin.fail())
                    box.setWidth(data);
                else {
                    cin.clear();
                    cin.ignore();
                    cout << "Incorrect input. Please try again." << endl;
                    getch();
                }

                break;
            case '0': // For exiting
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                getch();
                break;
        }
    }
    cout << "Exiting..." << endl;
    getch();
}
