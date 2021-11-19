// Nathan Angelo B. Cruz

#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std;

// Using const over #define to better fit C++ standards
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

class Manager : protected Employee {
    public:
        Manager();
        Manager(const char *, const int &, const float &, const int &);
        void displayEmployee() const;
        void setEmployee(const char *, const int &, const float &, const int &);

    protected:
        int _subordinates;
};

class Scientist : protected Employee {
    public:
        Scientist();
        Scientist(const char *, const int &, const float &, const int &);
        void displayEmployee() const;
        void setEmployee(const char *, const int &, const float &, const int &);

    protected:
        int _publications;
};

class Laborer : public Employee {
    public:
        Laborer();
        Laborer(const char *, const int&, const float&);
};

class foreman : protected Laborer {
    public:
        foreman();
        foreman(const char *, const int&, const float&, const float&);
        void displayEmployee() const;
        void setEmployee(const char *, const int&, const float&, const float&);

    protected:
        float _percentQuotasMet;
};

Employee::Employee() {
    strcpy_s(_name, "N/A");
    _id = 0;
    _salary = 0;
}

Employee::Employee(const char *n, const int &id, const float &s) {
    setEmployee(n, id, s);
}

void Employee::displayEmployee() const {
    cout << "ID: " << _id << endl;
    cout << "Name: " << _name << endl;
    cout << "Salary: $" << _salary << endl;
    return;
}

void Employee::setEmployee(const char *n, const int &id, const float &s) {
    strcpy_s(_name, n);
    _id = id;
    _salary = s;
    return;
}

Manager::Manager() : Employee() {
    _subordinates = 0;
}

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

Scientist::Scientist() : Employee() {
    _publications = 0;
}

Scientist::Scientist(const char *n, const int &id, const float &s, const int &p) {
    setEmployee(n, id, s, p);
}

void Scientist::displayEmployee() const {
    Employee::displayEmployee();
    cout << "Number of Publications: " << _publications << endl;
    return;
}

void Scientist::setEmployee(const char *n, const int &id, const float &s, const int &p) {
    Employee::setEmployee(n, id, s);
    _publications = p;
    return;
}

Laborer::Laborer() : Employee() {}

Laborer::Laborer(const char *n, const int& id, const float& s) 
    : Employee(n, id, s) {}

foreman::foreman() : Laborer() {
    _percentQuotasMet = 0;
}

foreman::foreman(const char *n, const int& id, const float& s, const float& p) {
    setEmployee(n, id, s, p);
}

void foreman::displayEmployee() const {
    Employee::displayEmployee();
    cout << "Percentage of Quotas Met: " << _percentQuotasMet << "%" << endl;
    return;
}

void foreman::setEmployee(const char *n, const int& id, const float& s, const float& p) {
    Employee::setEmployee(n, id, s);
    _percentQuotasMet = p;
    return;
}

int main() {
    Employee  emp;
    Manager   man;
    Scientist sci;
    Laborer   lab;
    foreman   fore;
    
    char  choice;
    char  inputName[NAME_SIZE];
    int   inputID;
    float inputSalary;
    int   inputSubordinates;
    int   inputPublications;
    float inputPercentQuota;

    do {
        system("cls");

        cout << "Employee" << endl;
        emp.displayEmployee();
        cout << endl;
        
        cout << "Manager" << endl;
        man.displayEmployee();
        cout << endl;

        cout << "Scientist" << endl;
        sci.displayEmployee();
        cout << endl;

        cout << "Laborer" << endl;
        lab.displayEmployee();
        cout << endl;

        cout << "Foreman" << endl;
        fore.displayEmployee();
        cout << endl;

        cout << "1. Set Employee" << endl;
        cout << "2. Set Manager" << endl;
        cout << "3. Set Scientist" << endl;
        cout << "4. Set Laborer" << endl;
        cout << "5. Set Foreman" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;
        cin.clear();    // For cleaning inputs
        cin.ignore(INT_MAX, '\n');

        switch (choice) {
            case '1':
                cout << endl << "Enter ID: ";
                cin >> inputID;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Enter name: ";
                cin.get(inputName, NAME_SIZE);
                cout << "Enter salary: ";
                cin >> inputSalary;
                emp = Employee(inputName, inputID, inputSalary);
                break;
            case '2':
                cout << endl << "Enter ID: ";
                cin >> inputID;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Enter name: ";
                cin.get(inputName, NAME_SIZE);
                cout << "Enter salary: ";
                cin >> inputSalary;
                cout << "Enter number of subordinates: ";
                cin >> inputSubordinates;
                man = Manager(inputName, inputID, inputSalary, inputSubordinates);
                break;
            case '3':
                cout << endl << "Enter ID: ";
                cin >> inputID;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Enter name: ";
                cin.get(inputName, NAME_SIZE);
                cout << "Enter salary: ";
                cin >> inputSalary;
                cout << "Enter number of publications: ";
                cin >> inputPublications;
                sci = Scientist(inputName, inputID, inputSalary, inputPublications);
                break;
            case '4': 
                cout << endl << "Enter ID: ";
                cin >> inputID;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Enter name: ";
                cin.get(inputName, NAME_SIZE);
                cout << "Enter salary: ";
                cin >> inputSalary;
                lab = Laborer(inputName, inputID, inputSalary);
                break;
            case '5':
                cout << endl << "Enter ID: ";
                cin >> inputID;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Enter name: ";
                cin.get(inputName, NAME_SIZE);
                cout << "Enter salary: ";
                cin >> inputSalary;
                cout << "Enter percentage of quotas met: ";
                cin >> inputPercentQuota;
                fore = foreman(inputName, inputID, inputSalary, inputPercentQuota);
                break;
            case '0':
                break;
            default:
                cout << endl << "Incorrect input." << endl;
                cout << "Press any key to try again." << endl;
                _getch();
                break;
        }  
    } while(choice != '0');
    
    cout << "Press any key to end." << endl;
    _getch();
    return 0;
}

