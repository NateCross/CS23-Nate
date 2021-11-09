#include <iostream>
#include <conio.h>
using namespace std;

// Base class
class Shape {
    public:
        void setWidth(int w);
        void setLength(int l);
        int getWidth();
        int getLength();

    // Because we are using inheritance, we use protected.
    // If private, only the owner of the member variables can access.
    // But with protected, children can access it
    protected:
        int length, width;
};


class PaintCost {
    public:
        int getPaintCost();
        void setPaintCost(int p);

    protected:
        int cost;
};

// Child function of shape
// No need to redefine variables;
// whatever is in shape can be used in rectangle
class Rectangle: public Shape, public PaintCost {
    public:
        int getArea(); 
};

void Shape::setLength(int l) {
    length = l;
}

void Shape::setWidth(int w) {
    width = w;
}

int Rectangle::getArea() {
    return length * width;
}

int PaintCost::getPaintCost() {
    return cost * 500;
}

void PaintCost::setPaintCost(int p) {
    cost = p;
}

int main() {
    Rectangle test1;
    test1.setLength(5);
    test1.setWidth(5);
    test1.setPaintCost(3);

    cout << test1.getArea() << endl;
    cout << test1.getPaintCost() << endl;

    _getch();
    return 0;
}

// Notes
// - You cannot inherit constructors
// - You cannot inherit overloaded operators
// - You cannot inherit friend functions
// - Derived classes inherit public and protected members and keep those attributes
// - But private cannot be accessed unless through pub/protected member variables
