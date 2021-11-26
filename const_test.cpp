#include <iostream>
#include <conio.h>
using namespace std;

// Why use const?
// https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration
// Essentially, you can use const for getters but not setters
class Test {
    public:
        Test(int t = 0) { test = t; }
        int getValue() const;
        void setValue(int);

    protected:
        int test;
};

class Test2: public Test {
    public:
        Test2(int t = 0) { test = t; }
        int getValue();
};

int Test::getValue() const {
    return test;
}

int Test2::getValue() {
    return test + 1;
}

void Test::setValue(int t) {
    test = t;
    return;
}

int main() {
    Test nice(0);
    Test2 noice(2);
    cout << noice.getValue();

    cout << nice.getValue() << noice.getValue() << endl;
    return 0;
}
