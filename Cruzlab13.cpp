// Nathan Angelo B. Cruz

#define _USE_MATH_DEFINES   // Used for the pi constant
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

class Point {
    public:
        Point();
        Point(float, float);

        float getX() const;
        float getY() const;
        void setX(float);
        void setY(float);
        void display() const;

    protected:
        float x_, y_;    // Represents center point in class Circle
};

class Circle: public Point {
    public:
        Circle();
        Circle(float, Point);
        Circle(float, float, float);

        float getRadius() const;
        void setRadius(float);
        float calcArea() const;
        float calcCircumference() const;

    protected:
        float radius_;
};

class Cylinder: public Circle {
    public:
        Cylinder();
        Cylinder(float, Circle);
        Cylinder(float, float, Point);
        Cylinder(float, float, float, float);

        float getHeight() const;
        void setHeight(float);
        float calcSurfaceArea() const;
        float calcVolume() const;

    protected:
        float height_;
};

Point::Point() {
    x_ = y_ = 0;
}

Point::Point(float x, float y) {
    setX(x);
    setY(y);
}

float Point::getX() const {
    return x_;
}

float Point::getY() const {
    return y_;
}

void Point::setX(float xInput) {
    x_ = xInput;
    return;
}

void Point::setY(float yInput) {
    y_ = yInput;
    return;
}

void Point::display() const {
    cout << "(" << getX() << ", " << getY() << ")";
    return;
}

Circle::Circle() {
    x_ = y_ = radius_ = 0;
}

Circle::Circle(float r, Point p) {
    setRadius(r);
    setX(p.getX());
    setY(p.getY());
}

Circle::Circle(float r, float x, float y) {
    setRadius(r);
    setX(x);
    setY(y);
}

float Circle::getRadius() const {
    return radius_;
}

void Circle::setRadius(float r) {
    radius_ = r;
    return;
}

float Circle::calcArea() const {
    return M_PI * radius_ * radius_;
}

float Circle::calcCircumference() const {
    return 2 * M_PI * radius_;
}

Cylinder::Cylinder() {
    x_ = y_ = radius_ = height_ = 0;
}

Cylinder::Cylinder(float h, Circle c) {
    setHeight(h);
    setRadius(c.getRadius());
    setX(c.getX());
    setY(c.getY());
}

Cylinder::Cylinder(float r, float h, Point p) {
   setRadius(r);
   setHeight(h);
   setX(p.getX());
   setY(p.getY());
}

Cylinder::Cylinder(float r, float h, float x, float y) {
    setRadius(r);
    setHeight(h);
    setX(x);
    setY(y);
}

float Cylinder::getHeight() const {
    return height_;
}

void Cylinder::setHeight(float h) {
    height_ = h;
    return;
}

float Cylinder::calcSurfaceArea() const {
    return calcCircumference() * (getHeight() + getRadius());
}

float Cylinder::calcVolume() const {
    return calcArea() * getHeight();
}

int main() {
    char choice;
    float inputX, inputY, inputR, inputH;
    Point p;
    Circle c;
    Cylinder cy;

    do {
        system("cls");

        cout << "Point: "; 
        p.display();
        cout << endl;

        cout << "Circle:" << endl;
        cout << "\tCenter = ";
        c.display(); 
        cout << endl << "\tRadius = " << c.getRadius() << endl;
        cout << "\tArea = " << c.calcArea() << endl;
        cout << "\tCircumference = " << c.calcCircumference() << endl;

        cout << "Cylinder:" << endl;
        cout << "\tCenter = ";
        cy.display();
        cout << endl << "\tRadius = " << cy.getRadius() << endl;
        cout << "\tHeight = " << cy.getHeight() << endl;
        cout << "\tArea = " << cy.calcArea() << endl;
        cout << "\tCircumference = " << cy.calcCircumference() << endl;
        cout << "\tSurface Area = " << cy.calcSurfaceArea() << endl;
        cout << "\tVolume = " << cy.calcVolume() << endl << endl;

        cout << "1. Set Point" << endl;
        cout << "2. Set Circle using Point as center" << endl;
        cout << "3. Set Circle manually" << endl;
        cout << "4. Set Cylinder using Circle" << endl;
        cout << "5. Set Cylinder using Point as center" << endl;
        cout << "6. Set Cylinder manually" << endl;
        cout << "0. Exit" << endl << endl;
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
                p = Point(inputX, inputY);
                break;
            case '2':
                cout << endl << "Enter radius: ";
                cin >> inputR;
                c = Circle(inputR, p);
                break;
            case '3':
                cout << endl << "Enter x coordinate: ";
                cin >> inputX;
                cout << "Enter y coordinate: ";
                cin >> inputY;
                cout << "Enter radius: ";
                cin >> inputR;
                c = Circle(inputR, inputX, inputY);
                break;
            case '4':
                cout << endl << "Enter height: ";
                cin >> inputH;
                cy = Cylinder(inputH, c);
                break;
            case '5':
                cout << endl << "Enter radius: ";
                cin >> inputR;
                cout << "Enter height: ";
                cin >> inputH;
                cy = Cylinder(inputR, inputH, p);
                break;
            case '6':
                cout << endl << "Enter x coordinate: ";
                cin >> inputX;
                cout << "Enter y coordinate: ";
                cin >> inputY;
                cout << "Enter radius: ";
                cin >> inputR;
                cout << "Enter height: ";
                cin >> inputH;
                cy = Cylinder(inputR, inputH, inputX, inputY);
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
