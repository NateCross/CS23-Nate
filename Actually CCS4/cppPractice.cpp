#include <iostream>
using namespace std;

class Test {
    public:
        void display() const {
            cout << "Hello" << endl;
        }

        Test() {
            cout << "Constructor" << endl;
        }

        ~Test() {
            cout << "Destructor" << endl;
        }
};

int main() {
    // Test nice;
    Test *lmao = new Test();
    delete lmao;
    return 0;

}