// Nathan Angelo B. Cruz

#include <iostream>
#include <conio.h>

using namespace std;

class Storage {
    public:
        Storage();
        Storage(int bi, int by);

        friend Storage operator+(const Storage &file1, const Storage &file2);
        friend Storage operator+=(Storage &file1, const Storage &file2);

        friend Storage operator++(Storage&);
        friend Storage operator++(Storage&, int);

        friend bool operator>(const Storage &file1, const Storage &file2);

    private:
        int bits_, bytes_;
};

Storage::Storage() {
    bits_ = bytes_ = 0;
}

Storage::Storage(int by, int bi) {
    bytes_ = by;
    bits_ = bi;
}

Storage operator+(const Storage &file1, const Storage &file2) {
    Storage temp;
    temp.bits_ = file1.bits_ + file2.bits_;
    temp.bytes_ = file1.bytes_ + file2.bytes_;

    if (temp.bits_ >= 8) {
        temp.bytes_ += (temp.bits_ / 8);
        temp.bits_ %= 8;
    }

    return temp;
}

Storage operator+=(Storage &file1, const Storage &file2) {
    file1 = file1 + file2;
}

Storage operator++(Storage &file) {
    file.bits_++;

    if (file.bits_ >= 8) {
        file.bytes_ += (file.bits_ / 8);
        file.bits_ %= 8;
    }
}

Storage operator++(Storage &file, int) {
    return ++file;
}

bool operator>(const Storage &file1, const Storage &file2) {
    if (file1.bytes_ > file2.bytes_)
        return true;
    else if (file1.bytes_ == file2.bytes_) {
        if (file1.bits_ > file2.bits_)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main() {
    Storage storage1(2,2), storage2(2,3), merge1, merge2;
    cout << "Storage 1: 2 bytes, 2 bits" << endl;
    cout << "Storage 2: 2 bytes, 3 bits" << endl;
    cout << "Merge 1: 0 bytes, 0 bits" << endl;
    cout << "Merge 2: 0 bytes, 0 bits" << endl << endl;
    bool storage1_is_greater = storage1 > storage2;
    cout << "Storage 1 > Storage 2 = " << storage1_is_greater << endl;
    cout << "Incrementing Storage 1 twice..." << endl;
    ++storage1;
    storage1++;
    storage1_is_greater = storage1 > storage2;
    cout << "Storage 1 > Storage 2 = " << storage1_is_greater << endl << endl;

    cout << "Merge 1 = storage1 + storage2" << endl;
    cout << "Merge 2 += storage1" << endl;
    merge1 = storage1 + storage2;
    merge2 += storage1;
    bool merge1_is_greater = merge1 > merge2;
    cout << "Merge 1 > Merge 2 = " << merge1_is_greater << endl;



}

