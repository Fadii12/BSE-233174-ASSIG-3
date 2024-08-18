#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    string address;

public:
    Person() : name(), address() {
        cout << "Person constructor called" << endl;
    }

    Person(const string& n, const string& a)  {
        name = n; address = a;
        cout << "Person parameterized constructor called" << endl;
    }

    void setName(const string& n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setAddress(const string& a) {
        address = a;
    }

    string getAddress() const {
        return address;
    }
};

class Employee {
protected:
    string employeeID;
    double salary;

public:
    Employee() : employeeID(), salary() {
        cout << "Employee constructor called" << endl;
    }

    Employee(const string& id, double sal)  {
        employeeID = id;
        salary = sal;
        cout << "Employee parameterized constructor called" << endl;
    }

    void setEmployeeID(const string& id) {
        employeeID = id;
    }

    string getEmployeeID() const {
        return employeeID;
    }

    void setSalary(double sal) {
        salary = sal;
    }

    double getSalary() const {
        return salary;
    }
};

class Teacher : public Person, public Employee {
private:
    string subject;

public:
    Teacher() : Person(), Employee(), subject() {
        cout << "Teacher constructor called" << endl;
    }

    Teacher(const string& n, const string& a, const string& id, double sal, const string& sub)
        : Person(n, a), Employee(id, sal), subject(sub) {
        cout << "Teacher parameterized constructor called" << endl;
    }

    void setSubject(const string& sub) {
        subject = sub;
    }

    string getSubject() const {
        return subject;
    }

    void displayInfo() const {
        cout << "Name " << getName() << endl;
        cout << "Address " << getAddress() << endl;
        cout << "Employee ID " << getEmployeeID() << endl;
        cout << "Salary " << getSalary()<<" RS " << endl;
        cout << "Subject " << getSubject() << endl;
    }
};

int main() {
    Teacher teacher("Arif Hosein", "ST MARY  Main St,Rawalpindi", "BS 234", 50000, "english");

    teacher.displayInfo();

    return 0;
}
