// Nathan Angelo B. Cruz

#include <iostream>
#include <conio.h>
using namespace std;

class Distance {
    public:
        Distance();
        Distance(int ft, int in);

        Distance friend operator+(const Distance &d1, const Distance &d2);
        Distance friend operator+=(Distance &d1, const Distance &d2);
        bool friend operator>(const Distance &d1, const Distance &d2);
        bool friend operator<(const Distance &d1, const Distance &d2);
        bool friend operator>=(const Distance &d1, const Distance &d2);
        bool friend operator<=(const Distance &d1, const Distance &d2);
        bool friend operator==(const Distance &d1, const Distance &d2);
        bool friend operator!=(const Distance &d1, const Distance &d2);

        void friend getDistance(const Distance &d1);

    private:
        int feet_, inches_;
};

Distance::Distance() {
    feet_ = inches_ = 0;
}

Distance::Distance(int ft, int in) {
    feet_ = ft;
    inches_ = in;

    if (inches_ < 0)
        inches_ = 0;
    if (feet_ < 0)
        feet_ = 0;

    if (inches_ >= 12) {
        feet_ += (inches_ / 12);
        inches_ %= 12;
    }
}

Distance operator+(const Distance &d1, const Distance &d2) {
    return Distance(d1.feet_ + d2.feet_, d1.inches_ + d2.inches_);
}

Distance operator+=(Distance &d1, const Distance &d2) {
    d1 = d1 + d2;
}

bool operator>(const Distance &d1, const Distance &d2) {
    if (d1.feet_ > d2.feet_)
        return true;
    else if (d1.feet_ == d2.feet_) {
        if (d1.inches_ > d2.inches_)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool operator<(const Distance &d1, const Distance &d2) {
    if (d1.feet_ < d2.feet_)
        return true;
    else if (d1.feet_ == d2.feet_) {
        if (d1.inches_ < d2.inches_)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool operator>=(const Distance &d1, const Distance &d2) {   // Using logic operators as shortcut
    return !(d1 < d2);
}

bool operator<=(const Distance &d1, const Distance &d2) {
    return !(d1 > d2);
}

bool operator==(const Distance &d1, const Distance &d2) {
    return (d1 >= d2) && (d1 <= d2);
}

bool operator!=(const Distance &d1, const Distance &d2) {
    return !(d1 == d2);
}

void getDistance(const Distance &d1) {
    cout << "Feet: " << d1.feet_ << endl;
    cout << "Inches: " << d1.inches_ << endl;
    return;
}

int main() {
    int feetInput, inchesInput;

    cout << "Distance 1" << endl;
    cout << "Input feet: ";
    cin >> feetInput;
    cout << "Input inches: ";
    cin >> inchesInput;
    Distance dist1(feetInput, inchesInput);

    cout << endl << "Distance 2" << endl;
    cout << "Input feet: ";
    cin >> feetInput;
    cout << "Input inches: ";
    cin >> inchesInput;
    Distance dist2(feetInput, inchesInput);

    cout << "Distance 1 > Distance 2: " << (dist1 > dist2) << endl;
    cout << "Distance 1 < Distance 2: " << (dist1 < dist2) << endl;
    cout << "Distance 1 >= Distance 2: " << (dist1 >= dist2) << endl;
    cout << "Distance 1 <= Distance 2: " << (dist1 <= dist2) << endl;
    cout << "Distance 1 == Distance 2: " << (dist1 == dist2) << endl;
    cout << "Distance 1 != Distance 2: " << (dist1 != dist2) << endl << endl;

    cout << "Distance 3 = Distance 1 + Distance 2" << endl;
    cout << "Distance 1 += Distance 2" << endl << endl;
    Distance dist3 = dist1 + dist2;
    dist1 += dist2;

    cout << "Distance 1 > Distance 3: " << (dist1 > dist3) << endl;
    cout << "Distance 1 < Distance 3: " << (dist1 < dist3) << endl;
    cout << "Distance 1 >= Distance 3: " << (dist1 >= dist3) << endl;
    cout << "Distance 1 <= Distance 3: " << (dist1 <= dist3) << endl;
    cout << "Distance 1 == Distance 3: " << (dist1 == dist3) << endl;
    cout << "Distance 1 != Distance 3: " << (dist1 != dist3) << endl << endl;

    getDistance(dist1);

    cout << endl << "Press any key to continue." << endl;
    getch();
    return 0;
}