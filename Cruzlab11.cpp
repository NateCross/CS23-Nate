// Nathan Angelo B. Cruz

#include <iostream>
#include <conio.h>
using namespace std;

class Storage {
    public:
        Storage();
        Storage(int by, int bi);

        friend Storage operator+(const Storage&, const Storage&);
        friend Storage operator+=(Storage&, const Storage&);
        friend Storage operator++(Storage&);
        friend Storage operator++(Storage&, int);
        friend bool operator>(const Storage&, const Storage&);

    private:
        int bytes_, bits_;
}; 

Storage::Storage() {
    bits_ = bytes_ = 0;
}

Storage::Storage(int by, int bi) {
    bits_ = bi;
    bytes_ = by;
    
    if (bits_ >= 8) {
        bytes_ += (bits_ / 8);
        bits_ %= 8;
    }
}

Storage operator+(const Storage& s1, const Storage& s2) {
    return Storage(s1.bytes_ + s2.bytes_, s1.bits_ + s2.bits_);
}

Storage operator+=(Storage& s1, const Storage& s2) {
    s1 = s1 + s2;
    return s1;
}

Storage operator++(Storage& s1) {
    s1 = Storage(s1.bytes_, s1.bits_ + 1);
    return s1;
}

Storage operator++(Storage& s1, int) {
    return ++s1;
}

bool operator>(const Storage& s1, const Storage& s2) {
    if (s1.bytes_ > s2.bytes_)
        return true;
    else if (s1.bytes_ == s2.bytes_ && s1.bits_ > s2.bits_)
        return true;
    else
        return false;
}

int main() {
    Storage file1(1,1), file2(1,7), file3;
    file3 = file1 + file2;
    file1 += file2;

    cout << "File1: 1 byte, 1 bit" << endl;
    cout << "File2: 1 byte, 7 bits" << endl;
    cout << "File3 = File1 + File2" << endl;
    cout << "File1 += File2" << endl;
    cout << "File1 > File3: " << (file1 > file3) << endl;
    file1++;
    cout << "File1++" << endl;
    cout << "File1 > File3: " << (file1 > file3) << endl;
    cout << "Press any key to end." << endl;

    _getch();
    return 0;
}

