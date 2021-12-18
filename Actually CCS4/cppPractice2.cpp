#include <iostream>
using namespace std;

int main() {
    int bigInt = 2147483647;
    cout << bigInt << endl;
    int test = 5;
    int test3 = 7;
    int &test2 = test;
    cout << "test2: " << test2 << "\n";
    test2 = test3; // actually changes the value of test
    cout << test2 << endl << test;

    cout << "\nPointers version\n";
    int nice = 3;
    int lmao = 4;
    int *ayy = &nice;
    cout << *ayy << endl;
    ayy = &lmao;
    cout << *ayy << endl;

    return 0;
}