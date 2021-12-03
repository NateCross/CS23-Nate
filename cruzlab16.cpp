// Nathan Angelo B. Cruz

#include <iostream>
#include <conio.h>
using namespace std;

class Shape {
    public:
        // pure virtual functions to make this an abstract class 
        virtual void display() const   = 0;
        virtual void calculateArea()   = 0;
        virtual void calculateVolume() = 0;

    protected:
        float _area;
        float _volume;
};

class TwoDimensional : public Shape {
    public:
        virtual void display() const;
        virtual void calculateArea() = 0;
        virtual void calculateVolume() { }
};

class ThreeDimensional : public Shape {
    public:
        virtual void display() const;
        virtual void calculateArea() = 0;
        virtual void calculateVolume() = 0;
};

void TwoDimensional::display() const {
    cout << "Shape is 2D" << endl;
}

void ThreeDimensional::display() const {
    cout << "Shape is 3D" << endl;
}

class Square : public TwoDimensional {
    public:
        Square();
        Square(const float&);
        void display() const;
        void calculateArea();

    protected:
        float _length;
        float _width;
};

Square::Square() {
    _length = _width = _area = _volume = 0;
}

Square::Square(const float& l) {
    _length = l;
    _width  = l;
    calculateArea();
    _volume = 0;
}

void Square::display() const {
    TwoDimensional::display();
    cout << "Length: " << _length << endl
         << "Width: "  << _width  << endl
         << "Area: "   << _area   << endl;
}

void Square::calculateArea() {
    _area = _length * _length;
}

class Cube : public ThreeDimensional {
    public:
        Cube();
        Cube(const float&);
        void display() const;
        void calculateArea();
        void calculateVolume();

    protected:
        float _length;
        float _width;
        float _height;
};

Cube::Cube() {
    _length = _width = _height = _area = _volume = 0;
}

Cube::Cube(const float& l) {
    _length = _width = _height = l;
    calculateArea();
    calculateVolume();
}

void Cube::display() const {
    ThreeDimensional::display();
    cout << "Length: "       << _length << endl
         << "Width: "        << _width  << endl
         << "Height: "       << _height << endl
         << "Surface Area: " << _area   << endl
         << "Volume: "       << _volume << endl;
}

void Cube::calculateArea() {
    _area = 6 * _length * _length;
}

void Cube::calculateVolume() {
    _volume = _length * _length * _length;
}

int main() {
    // Shape *shp;

    // Square squ(1.1);
    // shp = &squ;
    // shp->display();

    // cout << endl;

    // Cube cb(2.2);
    // shp = &cb;
    // shp->display();
    Shape *shape;
    Square square;
    Cube cube;
    shape = &square;

    char choice;
    float inputL;

    do {
        system("cls");

        shape->display();
        cout << endl << endl;

        cout << "1. Set Square" << endl;
        cout << "2. Set Cube" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;
        cin.clear();    // For cleaning inputs
        cin.ignore(INT_MAX, '\n');

        switch(choice) {
            case '1':
                cout << endl << "Enter length: ";
                cin >> inputL;
                square = Square(inputL);
                shape = &square;
                break;
            case '2':
                cout << endl << "Enter length: ";
                cin >> inputL;
                cube = Cube(inputL);
                shape = &cube;
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
