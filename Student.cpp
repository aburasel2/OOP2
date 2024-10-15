#include<iostream>
#include<conio.h>

using namespace std;

class student {
    public:
    int id;
    double gpa;
    // function deleare;
    void display() {
        cout<<"ID: "<<id<< " "<< "GPA "<< " " << gpa << endl;
    }
//parameterised function
    void setValue(int x, double y) {
        id = x;
        gpa = y;
    }

};

int main() {
    student Rasel, sumona;

   // Rasel.id = 27;
    //Rasel.gpa = 3.44;
//use of parameter function
    Rasel.setValue(3027, 3.44);
    Rasel.display();
   // sumona.id = 102;
   // sumona.gpa = 3.22;
//use of parameter function
    sumona.setValue(567, 3.30);
    sumona.display();

}