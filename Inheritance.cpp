#include <iostream>

using namespace std;

class Person {
    public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student:public Person {
    public:
     int id;

    void display2() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }


};

int main() {
    Student s;
    s.name = "John";
    s.age = 18;
    s.id = 3027;
    s.display2();
}