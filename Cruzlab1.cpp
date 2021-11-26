#include <cmath>
#include <iostream>
#include <conio.h>
using namespace std;

// Nate Cruz 2021

double power(double n, int p = 2) {
    double result = n;

    // I was about to submit this until I remembered that there were edge cases on exponents, so here they are
    // Positive exponent
    if (p > 0) {
        for (int i = 1; i < p; i++)
            result *= n;
    }
    // If exponent is 0
    else if (p == 0) {
        result = 1;
    }
    // Negative exponent
    else {
        for (int i = 0; i >= p; i--)
            result /= n;
    }
    
    return result;
}

int main() {
    double number, result;
    int exponent;
    char choice;

    cout << "Enter the number: ";
    cin >> number;
    while (true) {
        cout << "Do you want to power (y/n)? ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Enter power to be raised: ";
            cin >> exponent;
            result = power(number, exponent);
            break;
        }
        else if (choice == 'n' || choice == 'N') {
            result = power(number);
            exponent = 2; // Added this or else there wouldn't be any number for exponent. It's not clean though...
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }

    }

    cout << number << " ^ " << exponent << " ";
    cout << "(" << number << " raised to the power " << exponent << ") = " << result << endl;

    _getch();
    return 0;
}
