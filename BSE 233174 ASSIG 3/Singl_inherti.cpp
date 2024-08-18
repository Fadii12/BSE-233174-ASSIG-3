#include <iostream>
#include <string>

using namespace std;

class Shape {
private:
    string color;

public:
    Shape() : color() {
        cout << "Shape constructor called" << endl;
    }

    Shape(const string& c)  {
        color = c;
        cout << "Shape parameterized constructor called" << endl;
    }

    void setColor(const string& c) {
        color = c;
    }

    string getColor() const {
        return color;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double breadth;

public:
    Rectangle() : Shape(), length(), breadth() {
        cout << "Rectangle constructor called" << endl;
    }

    Rectangle(const string& color, double l, double b)  {
        Shape() = color;
        length = l,
            breadth = b;
        cout << "Rectangle parameterized constructor called" << endl;
    }

    void setLength(double l) {
        length = l;
    }

    void setBreadth(double b) {
        breadth = b;
    }

    double getLength() const {
        return length;
    }

    double getBreadth() const {
        return breadth;
    }

    double calculateArea() const {
        return length * breadth;
    }

    double calculatePerimeter() const {
        return 2 * (length + breadth);
    }

    void displayValues() const {
        cout << "Color: " << getColor() << endl;
        cout << "Length: " << getLength() << endl;
        cout << "Breadth: " << getBreadth() << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    Rectangle rect("Yellow", 10.0, 7.0);

    rect.displayValues();

    return 0;
}

