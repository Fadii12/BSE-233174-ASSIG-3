#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;

public:
    Animal() : name() {
        cout << "Animal constructor called" << endl;
    }

    Animal(const string& n)  {
        name = n;
        cout << "Animal parameterized constructor called" << endl;
    }

    void setName(const string& n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void display() const {
        cout << "Name " << name << endl;
    }
};

class Mammal : public Animal {
protected:
    int legs;

public:
    Mammal() : Animal(), legs() {
        cout << "Mammal constructor called" << endl;
    }

    Mammal(const string& n, int l)  {
        Animal() = n;
        legs = l;
        cout << "Mammal parameterized constructor called" << endl;
    }

    void setLegs(int l) {
        legs = l;
    }

    int getLegs() const {
        return legs;
    }

    void display() const {
        Animal::display(); 
        cout << "Number of legs: " << legs << endl;
    }
};

class Dog : public Mammal {
public:
    Dog() : Mammal() {
        cout << "Dog constructor called" << endl;
    }

    Dog(const string& n, int l) : Mammal(n, l) {
        cout << "Dog parameterized constructor called" << endl;
    }

    void bark() const {
        cout << name << " says: Woof Woof!" << endl;
    }

    void display() const {
        Mammal::display(); 
        cout << "This is a dog!" << endl;
    }
};

int main() {
    Dog dog("Tommy", 4);

    dog.display();

    dog.bark();

    return 0;
}
