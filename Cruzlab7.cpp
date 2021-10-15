// Nathan Angelo B. Cruz

/*
Create a class called Distance containing two members feet and inches. This class represents
distance measured in feets and inches. For this class, provide the following functions:

a) A no-argument constructor that initializes the data members to some fixed values.
b) A 2-argument constructor to initialize the values of feet and inches to the values sent
from the calling function at the time of creation of an object of type Distance.
c) AddDistance function to add two distances: Feet and inches of both objects should add
in their corresponding members. 12 inches constitute one foot. Make sure that the
result of addition doesn't violate this rule.
d) isGreater: should return a variable of type bool to indicate whether 1st distance is greater than 2nd or not.
e) isSmaller: should return a variable of type bool to indicate whether 1st distance is smaller than 2nd or not.
f) isGreaterEqual: should return a variable of type bool to indicate whether 1st distance is greater than or equal to 2nd or not.
g) isSmallerEqual: should return a variable of type bool to indicate whether 1st distance is smaller than or equal to 2nd or not.
h) isEqual: should return a variable of type bool to indicate whether 1st distance is equal to the 2nd distance or not.
i) isNotEqual: should return a true value if both the distances are not equal and return a false if both are equal.
NOTE: Define all the member functions outside the class.
*/

#include <iostream>
#include <conio.h>
using namespace std;

class Distance {
    private:
        int feet, inches;

    public:
        Distance();
        Distance(int f, int in);
        void AddDistance(Distance dist1, Distance dist2);
        bool isGreater(Distance dist);
        bool isSmaller(Distance dist);
        bool isGreaterEqual(Distance dist);
        bool isSmallerEqual(Distance dist);
        bool isEqual(Distance dist);
        bool isNotEqual(Distance dist);
};

Distance::Distance() {
    feet = inches = 0;
}

Distance::Distance(int f, int in) {
    feet = f;
    inches = in;
}

void Distance::AddDistance(Distance dist1, Distance dist2) {
    inches = dist1.inches + dist2.inches;
    feet = dist1.feet + dist2.feet;

    if (inches >= 12) {
        feet += (inches / 12);
        inches %= 12;
    }
}

bool Distance::isGreater(Distance dist) {
    if (feet > dist.feet)
        return true;
    else if (feet == dist.feet && inches > dist.inches)
        return true;
    else
        return false;
}

bool Distance::isSmaller(Distance dist) {
    if (feet < dist.feet)
        return true;
    else if (feet == dist.feet && inches < dist.inches)
        return true;
    else
        return false;
}

bool Distance::isGreaterEqual(Distance dist) {
    return !this->isSmaller(dist);
}

bool Distance::isSmallerEqual(Distance dist) {
    return !this->isGreater(dist);
}

bool Distance::isEqual(Distance dist) {
    return this->isGreaterEqual(dist) && this->isSmallerEqual(dist);
}

bool Distance::isNotEqual(Distance dist) {
    return !this->isEqual(dist);
}

int main() {
    cout << "Declaring Distance:" << endl << "test1 = 13'1\"" << endl << "test2 = 17'11\"" << endl << "test3 = 0'0\"" << endl;
    Distance test1(13, 1), test2(17, 11), test3;

    test3.AddDistance(test1, test2);
    cout << "Added test1 and test2 to test3" << endl;

    cout << "test1 > test2 = " << test1.isGreater(test2) << endl;
    cout << "test1 < test2 = " << test1.isSmaller(test2) << endl;
    cout << "test1 >= test2 = " << test1.isGreaterEqual(test2) << endl;
    cout << "test1 <= test2 = " << test1.isSmallerEqual(test2) << endl;
    cout << "test1 = test2 = " << test1.isEqual(test2) << endl;
    cout << "test1 =/= test2 = " << test1.isNotEqual(test2) << endl;

    cout << "Press any key to end." << endl;
    getch();
}
