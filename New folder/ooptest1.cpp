#include <iostream>
using namespace std;

class Box {
    public: // Make variables private. Make functions public. We access the class through the member functions.
        double length;
        double width;
        double height;
        double getVolume() {
            return length * width * height;
        }
};

int main() {
    Box box1;
    box1.length = 5;
    box1.width = 6;
    box1.height = 7;
    cout << box1.getVolume();

    return 0;
}
