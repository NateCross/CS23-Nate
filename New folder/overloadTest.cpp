#include <iostream>
using namespace std;

class Box {
    public:
        Box();
        Box(double l, double w, double h);
        double getVolume();
        void setLength(double l);
        void setWidth(double w);
        void setHeight(double h);
        friend Box operator+(const Box &b1, const Box &b2);
        void operator+=(const Box &b1);
    private:
        double length, width, height;
};

void Box::setLength(double l) {
    length = l;
    return;
}

void Box::setWidth(double w) {
    width = w;
    return;
}

void Box::setHeight(double h) {
    height = h;
    return;
}

Box::Box() {
    this->setHeight(0);
    this->setLength(0);
    this->setWidth(0);
}

Box::Box(double l, double w, double h) {
    this->setHeight(l);
    this->setLength(w);
    this->setWidth(h);
}

double Box::getVolume() {
    return length * width * height;
}

Box operator+(const Box &b1, const Box &b2) {
    return Box(b2.length + b1.length, b2.width + b1.width, b2.height + b1.height);
}

void Box::operator+=(const Box &b1) {
    *this = *this + b1;
}


int main() {
    Box test(1,2,3), test2(4,5,6);
    Box test3 = test + test2;
    test += test2;
    double vol = test3.getVolume();
    cout << vol << endl;
    cout << test.getVolume() << endl;
    return 0;
}