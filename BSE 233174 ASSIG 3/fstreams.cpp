
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    string name;
    int rollnum;
    float marks;

public:
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollnum;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Name: " << name << " Roll Number: " << rollnum << " Marks " << marks << endl;
    }

    void writeToFile(fstream& file) {
        file << name << " " << rollnum << " " << marks << endl;
    }

    void readFromFile(fstream& file) {
        file >> name >> rollnum >> marks;
    }

    int getRollNumber() {
        return rollnum;
    }

    void modifyMarks(float new_marks) {
        marks = new_marks;
    }
};

int main() {
    Student students[5];

    
    fstream file("students.txt", ios::out);  
    if (!file) {
        cout << "Error: Could not create or open the file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < 5; ++i) {
        cout << "Enter details of student " << i + 1 << ":" << endl;
        students[i].input();
        students[i].writeToFile(file);
    }

    file.close();  

    file.open("students.txt", ios::in | ios::out);
    if (!file) {
        cout << "Error: Could not open the file for reading and writing." << endl;
        return 1;
    }

    cout << " Data of students from file ";
    for (int i = 0; i < 5; ++i) {
        students[i].readFromFile(file);
        students[i].display();
    }

    int roll_num_to_modify;
    float new_marks;
    cout << "\Enter the roll number of the student whose marks you want to modify ";
    cin >> roll_num_to_modify;
    cout << "Enter the new marks: ";
    cin >> new_marks;

    file.clear();  
    file.seekg(0); 

    for (int i = 0; i < 5; ++i) {
        long pos = file.tellg();
        students[i].readFromFile(file);

        if (students[i].getRollNumber() == roll_num_to_modify) {
            students[i].modifyMarks(new_marks);

            file.seekp(pos);
            students[i].writeToFile(file);

            break;
        }
    }

    file.close();  

    return 0;
}
