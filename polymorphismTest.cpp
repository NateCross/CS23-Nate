// occurs when there are a hierarchy of classes

#include <iostream>
#include <conio.h>
// no using namespace this time cause we're cool
//

class Shape {
    protected:
        int width, height;
    public:
        Shape(int a = 0, int b = 0) {
            width = a;
            height = b;
        }
        // a virtual function; if there's another version of this function of this 
        // in the derived class, it signals that I don't want static linkage
        // this is dynamic linkage or late binding
        // virtual int getArea() {
            // std::cout << "Parent class getArea: " << std::endl;
            // return 0;
        // }
        //
        // This is a pure virtual function; telling the compiler it has no body
        virtual int getArea() = 0;
        void setWidth(int w) {
            width = w;
        }
        void setHeight(int h) {
            height = h;
        }
};

class Rectangle: public Shape {
    public:
        Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

        int getArea() {
            std::cout << "Rectangle class area: " << std::endl;
            return width * height;
        }
};

class Triangle: public Shape {
    public:
        Triangle(int a = 0, int b = 0) : Shape(a, b) {}

        int getArea() {
            std::cout << "Triangle class area: " << std::endl;
            return width * height / 2;
        }
};

int main() {
    Shape *shape;
    // Rectangle rec(10, 7);
    // Triangle tri(10, 5);
    Rectangle rec;
    Triangle tri;

    rec.setWidth(5);
    rec.setHeight(7);

    // Store the address of the rectangle
    shape = &rec;

    // Call rectangle getArea
    shape->getArea();

    shape = &tri;

    shape->getArea();

    _getch();
    return 0;
}
