// Nathan Angelo B. Cruz

#define _USE_MATH_DEFINES   // Used for the pi constant
#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

// Abstract base class
class shape {
    public:
        shape();
        shape(const float&, const float&);

        // Defining as pure virtual functions
        virtual void calculateArea()   = 0;
        virtual void calculateVolume() = 0;
        virtual void display() const   = 0;

    protected:
        float _area;
        float _volume;
};

class point : public shape {
    public:
        point();
        point(const float&, const float&);
        void calculateArea();
        void calculateVolume();
        void display() const;

    protected:
        float _xPos;
        float _yPos;
};

class Circle : public point {
    public:
        Circle();
        Circle(const float&, const float&, const float&);
        void calculateArea();
        void display() const;

    protected:
        float _radius;
};

class Cylinder : public Circle {
    public:
        Cylinder();
        Cylinder(const float&, const float&, const float&, const float&);
        void calculateArea();
        void calculateVolume();
        void display() const;

    protected:
        float _height;
};

shape::shape() {
    _area = _volume = 0;
}

shape::shape(const float& a, const float& v) {
    _area   = a;
    _volume = v;
}

// Reusing Shape's constructor to expedite
point::point() : shape() {
    _xPos = _yPos = 0;
}

point::point(const float& x, const float& y) : shape() {
    _xPos = x;
    _yPos = y;
}

// calculateArea and calculateVolume are left not defined here
// because points cannot have either an area nor a volume 
// But in order to preserve the functionality of the abstract base class 
// these classes have to be defined anyways as such to make it compile
void point::calculateArea() {}
void point::calculateVolume() {}

void point::display() const {
    cout << "Coordinates: (" << _xPos << ", " << _yPos << ")" << endl;
    return;
}

Circle::Circle() : point() {
    _radius = 0;
}

Circle::Circle(const float& x, const float& y, const float& r)
    : point(x, y) {
        _radius = r;
        calculateArea();
    }

void Circle::calculateArea() {
    _area = M_PI * _radius * _radius;
    return;
}

void Circle::display() const {
    point::display();
    cout << "Radius: " << _radius << endl
         << "Area: "   << _area   << endl;
    return;
}

Cylinder::Cylinder() : Circle() {
    _height = 0;
}

Cylinder::Cylinder(const float& x, const float& y, 
                   const float& r, const float& h) : Circle(x, y, r) {
    _height = h;
    calculateArea();
    calculateVolume();
}

void Cylinder::calculateArea() {
    Circle::calculateArea();
    _area = (_area * 2) + (2 * M_PI * _radius * _height);
    return;
}

void Cylinder::calculateVolume() {
    _volume = M_PI * _radius * _radius * _height;
    return;
}

void Cylinder::display() const {
    Circle::display();
    cout << "Height: " << _height << endl
         << "Volume: " << _volume << endl;
    return;
}

int main() {

    point    pnt;
    Circle   circ;
    Cylinder cyl;
    shape    *shapePoint = &pnt;
    shape    *shapeCircle = &circ;
    shape    *shapeCylinder = &cyl;

    char  choice;
    float inputX;
    float inputY;
    float inputR;
    float inputH;

    do {
        system("cls");

        cout << "Point" << endl;
        shapePoint->display();
        cout << endl;

        cout << "Circle" << endl;
        shapeCircle->display();
        cout << endl;

        cout << "Cylinder" << endl;
        shapeCylinder->display();
        cout << endl;

        cout << "1. Set Point"    << endl;
        cout << "2. Set Circle"   << endl;
        cout << "3. Set Cylinder" << endl;
        cout << "0. Exit"         << endl;

        cout << "Enter choice: ";
        cin >> choice;
        cin.clear();    // For cleaning inputs
        cin.ignore(INT_MAX, '\n');

        switch (choice) {
            case '1':
                cout << endl << "Enter x coordinate: ";
                cin >> inputX;
                cout << "Enter y coordinate: ";
                cin >> inputY;
                pnt = point(inputX, inputY);
                break; 
            case '2':
                cout << endl << "Enter x coordinate: ";
                cin >> inputX;
                cout << "Enter y coordinate: ";
                cin >> inputY;
                cout << "Enter radius: ";
                cin >> inputR;
                circ = Circle(inputX, inputY, inputR);
                break;
            case '3':
                cout << endl << "Enter x coordinate: ";
                cin >> inputX;
                cout << "Enter y coordinate: ";
                cin >> inputY;
                cout << "Enter radius: ";
                cin >> inputR;
                cout << "Enter height: ";
                cin >> inputH;
                cyl = Cylinder(inputX, inputY, inputR, inputH);
                break;
            case '0':
                break;
            default:
                cout << endl << "Incorrect input." << endl;
                cout << "Press any key to try again." << endl;
                _getch();
                break;
        }
    } while (choice != '0');

    cout << "Press any key to end." << endl;
    _getch();
    return 0;
}


