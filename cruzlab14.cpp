// Nathan Angelo B. Cruz

#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std;

// Using const over #define to fit C++ standards
const int NAME_SIZE = 50;

class Employee {
    public:
        Employee();
        Employee(const char *, const int &, const float &);
        void displayEmployee() const;
        void setEmployee(const char *, const int &, const float &);

    protected:
        char  _name[NAME_SIZE];
        float _salary;
        int   _id;
};

Employee::Employee() {
    strcpy_s(_name, "");
    _id = 0;
    _salary = 0;
}

Employee::Employee(const char *n, const int &id, const float &s) {
    setEmployee(n, id, s);
}

void Employee::displayEmployee() const {
    cout << "ID: " << _id << endl;
    cout << "Name: " << _name << endl;
    cout << "Salary: " << _salary << endl;
    return;
}

void Employee::setEmployee(const char *n, const int &id, const float &s) {
    strcpy_s(_name, n);
    _id = id;
    _salary = s;
    return;
}

class Manager: public Employee {
    public:
        Manager();
        Manager(const char *, const int &, const float &, const int &);
        void displayEmployee() const;
        void setEmployee(const char *, const int &, const float &, const int &);

    private:
        int _subordinates;
};

Manager::Manager() : Employee() {
    _subordinates = 0;
}

// Reuses Employee constructor function
// Manager::Manager(char *n, int id, float s, int sub)
    // : Employee(n, id, s) {
        // subordinates_ = sub;
    // }

Manager::Manager(const char *n, const int &id, const float &s, const int &sub) {
    setEmployee(n, id, s, sub);
}

void Manager::setEmployee(const char *n, const int &id, const float &s, const int &sub) {
    Employee::setEmployee(n, id, s);
    _subordinates = sub;
    return;
}

void Manager::displayEmployee() const {
    Employee::displayEmployee();
    cout << "Subordinates: " << _subordinates << endl;
    return;
}

class Scientist : public Employee {
    public:
        Scientist();
        Scientist(const char *, const int &, const float &, const int &);
        void displayEmployee() const;
        void setEmployee(const char *, const int &, const float &, const int &);

    private:
        int _publications;
};

Scientist::Scientist() : Employee() {
    _publications = 0;
}

Scientist::Scientist(const char *n, const int &id, const float &s, const int &p) {
    setEmployee(n, id, s, p);
}

void Scientist::displayEmployee() const {
    Employee::displayEmployee();
    cout << "Publications: " << _publications << endl;
    return;
}

void Scientist::setEmployee(const char *n, const int &id, const float &s, const int &p) {
    Employee::setEmployee(n, id, s);
    _publications = p;
    return;
}

int main() {
    Manager test, test2;
    test = Manager("yes", 1, 2, 1);
    test.displayEmployee();
    test2.displayEmployee();
    
    _getch();
    return 0;
}

// TODO: Change variable parameters to int& not int &
