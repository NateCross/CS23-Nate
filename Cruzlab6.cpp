// Nate Cruz 2021

/*
Create a class called Time that has three int class variables :hours, minutes, and seconds.
Provide the following member functions for this class:
a. A no-argument constructor to initialize hours, minutes, and seconds to 0.
b. A 3-argument constructor to initialize the members to values sent from the calling function
at the time of creation of an object. Make sure that valid values are provided for all the data
members. In case of an invalid value, set the variable to 0.
c. A member function show() to display time in 11:59:59 format.
d. A function AddTime for addition of two Time objects. Each time unit of one object must add
into the corresponding time unit of the other object. Keep in view the fact that minutes and
seconds of resultant should not exceed the maximum limit (60). If any of them do exceed,
subtract 60 from the corresponding unit and add a 1 to the next higher unit.
NOTE: Define all the member functions outside the class.
A main() program should create two initialized Time objects and one that isn’t initialized.
Then it should add the two initialized values together, leaving the result in the third Time
variable. Finally it should display the value of this third variable.
*/

#include <iostream>
using namespace std;

class Time {
    private:
        int hours, minutes, seconds;

    public:
        Time();
        Time(int h, int m, int s);
        void show();
        void AddTime(Time t1, Time t2);
        //Time operator+(const Time& t);

};

Time::Time() {
    hours = minutes = seconds = 0;
}

Time::Time(int h, int m, int s) {
    if (h >= 0 && h <= 12)
        hours = h;
    else
        hours = 0;

    if (m >= 0 && m <= 60)
        minutes = m;
    else
        minutes = 0;

    if (s >= 0 && s <= 60)
        seconds = s;
    else
        seconds = 0;
}

void Time::show() {
    cout << hours << ":";

    if (minutes < 10)
        cout << "0";
    cout << minutes << ":";

    if (seconds < 10)
        cout << "0";
    cout << seconds << endl;
}

void Time::AddTime(Time t1, Time t2) {
    hours = t1.hours + t2.hours;
    minutes = t1.minutes + t2.minutes;
    seconds = t1.seconds + t2.seconds;

    if (seconds >= 60) {
        seconds -= 60;
        minutes++;
    }
    if (minutes >= 60) {
        minutes -= 60;
        hours++;
    }
    if (hours >= 12)
        hours -= 12;

    return;
}



int main() {
    Time test1, test2(0, 19, 41), test3(12, 40, 19), test4;
    cout << "Time 1: ";
    test1.show();
    cout << "Time 2: ";
    test2.show();
    cout << "Time 3: ";
    test3.show();

    test4.AddTime(test2, test3);
    cout << "Time 2 + Time 3: ";
    test4.show();
    return 0;
}
