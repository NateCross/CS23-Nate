// Nathan Angelo B. Cruz

/*
Create a class called Time that has separate int member variables for hours, minutes, and
seconds. Provide the following member functions for this class:
a. A no-argument constructor to initialize hour, minutes, and seconds to 0.
b. A 3-argument constructor to initialize the members to values sent from the calling
function at the time of creation of an object. Make sure that valid values are provided for
all the data members. In case of an invalid value, set the variable to 0.
c. A member function show() to display time in 11:59:59 format.
d. An overloaded operator+ for addition of two Time objects. Each time unit of one object
must add into the corresponding time unit of the other object. Keep in view the fact that
minutes and seconds of resultant should not exceed the maximum limit (60). If any of
them do exceed, subtract 60 from the corresponding unit and add a 1 to the next higher
unit.
e. Overloaded operators for pre- and post-increment. These increment operators should
add a 1 to the seconds unit of time. Keep track that seconds should not exceed 60.
f. Overloaded operators for pre- and post-decrement. These decrement operators should
subtract a 1 from seconds unit of time. If number of seconds goes below 0, take
appropriate actions to make this value valid.
A main() program should create two initialized Time objects and one that isn’t initialized. Then it
should add the two initialized values together, leaving the result in the third Time variable.
Finally it should display the value of this third variable. Check the functionalities of ++ and --
operators of this program for both pre- and post-incrementation.
*/

#include <iostream>
#include <conio.h>

using namespace std;

class Time {
    private:
        int hours, minutes, seconds;

    public:
        Time();
        Time(int, int, int);
        void show();

        Time operator+(const Time &t);

        Time operator++(); //prefix
        Time operator++(int); //postfix

        Time operator--();
        Time operator--(int);
};

Time::Time() {
    hours = minutes = seconds = 0;
}

Time::Time(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;

    if (seconds >= 60 || seconds < 0)
        seconds = 0;
    if (minutes >= 60 || minutes < 0)
        minutes = 0;
    if (hours >= 24 || hours < 0)
        hours = 0;
}

void Time::show() {
    if (hours < 10)
        cout << "0";
    cout << hours << ":";
    if (minutes < 10)
        cout << "0";
    cout << minutes << ":";
    if (seconds < 10)
        cout << "0";
    cout << seconds << endl;
}

Time Time::operator+(const Time &t) {
    hours += t.hours;
    minutes += t.minutes;
    seconds += t.seconds;

    if (seconds >= 60) {
        minutes += (seconds / 60);
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += (minutes / 60);
        minutes %= 60;
    }
    if (hours >= 24)
        hours %= 24;

    return *this;
}

Time Time::operator++() {
    seconds++;

    if (seconds >= 60) {
        minutes += (seconds / 60);
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += (minutes / 60);
        minutes %= 60;
    }
    if (hours >= 24)
        hours %= 24;

    return *this;
}

Time Time::operator++(int) {
    return ++*this;
}

Time Time::operator--() {
    seconds--;

    if (seconds < 0) {
        minutes--;
        seconds += 60;
    }
    if (minutes < 0) {
        hours--;
        minutes += 60;
    }
    if (hours < 0)
        hours += 24;

    return *this;
}

Time Time::operator--(int) {
    return --*this;
}


int main() {
    Time test1(1,2,3), test2(4,5,6), test3;
    cout << "test1: ";
    test1.show();
    cout << "test2: ";
    test2.show();
    cout << "test1 + test2 = ";
    test3 = test1 + test2;
    test3.show();
    cout << "Incrementing test3 twice..." << endl;
    test3++;
    test3.show();
    ++test3;
    test3.show();
    cout << "Decrementing test3 twice..." << endl;
    test3--;
    test3.show();
    --test3;
    test3.show();

    cout << "Press any key to end." << endl;
    getch();

}
