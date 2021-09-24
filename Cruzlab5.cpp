// Nate Cruz 2021

/*
Create a class called Date that includes three pieces of information as instance variables - a
month (type int), a day (type int), and a year (type int). Your class should have a constructor that
initializes the three instance variables and assumes that the values provided are correct.
Provide a set and get function for each instance variable. Provide a function displayDate that
displays the month, day, and year separated by forward slashes (/). Write a main function that
tests your class.
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class Date {
    private:
        int month, day, year;

    public:
        Date(int monthInput, int dayInput, int yearInput);

        void setMonth(int input);
        void setDay(int input);
        void setYear(int input);

        int getMonth();
        int getDay();
        int getYear();

        void displayDate();
};

Date::Date(int monthInput, int dayInput, int yearInput) {
    setMonth(monthInput);
    setDay(dayInput);
    setYear(yearInput);
}

void Date::setMonth(int input = 1) {
    month = input;
}

void Date::setDay(int input = 1) {
    day = input;
}

void Date::setYear(int input = 1970) {
    year = input;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

int Date::getYear() {
    return year;
}

void Date::displayDate() {
    cout << getMonth() << "/" << getDay() << "/" << getYear();
}

int main() {
    char choice;
    int userMonth, userDay, userYear;

    cout << "Input month: ";
    cin >> userMonth;
    cin.clear();
    fflush(stdin);

    cout << "Input day: ";
    cin >> userDay;
    cin.clear();
    fflush(stdin);

    cout << "Input year: ";
    cin >> userYear;
    cin.clear();
    fflush(stdin);

    Date userInput(userMonth, userDay, userYear);

    while (choice != '0') {
        system("cls");

        userMonth = 0;
        userDay = 0;
        userYear = 0;

        cout << "Date: ";
        userInput.displayDate();
        cout << endl;

        cout << "1. Set month" << endl;
        cout << "2. Set day" << endl;
        cout << "3. Set year" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.clear();
        fflush(stdin);
        cout << endl;

        switch (choice) {
            case '1':
                cout << "Input month: ";
                cin >> userMonth;
                cin.clear();
                fflush(stdin);
                userInput.setMonth(userMonth);
                cout << "Month set." << endl << "Press Enter to continue." << endl;
                getch();
                break;
            case '2':
                cout << "Input day: ";
                cin >> userDay;
                cin.clear();
                fflush(stdin);
                userInput.setDay(userDay);
                cout << "Day set." << endl << "Press Enter to continue." << endl;
                getch();
                break;
            case '3':
                cout << "Input year: ";
                cin >> userYear;
                cin.clear();
                fflush(stdin);
                userInput.setYear(userYear);
                cout << "Year set." << endl << "Press Enter to continue." << endl;
                getch();
                break;
            case '0':
                break;
            default:
                cout << "Error: Invalid choice." << endl << "Press Enter to continue." << endl;
                getch();
                break;
        }
    }

    cout << "Exiting program..." << endl << "Press Enter to continue."<< endl;
    getch();
}
