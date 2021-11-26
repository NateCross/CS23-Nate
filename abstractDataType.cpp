#include <iostream>

class Box {
    double length;
    double width;
    double height;

    public:
        virtual double getVolume() = 0;
        
};

// Concrete class
