#include <iostream>
using namespace std;

class Truck;

class Car {
    int passengers;
    int speed;

    public:
    Car(int p, int s){passengers=p; speed=s;}
    friend int sp_greater(Car c, Truck t);

};

class Truck {
    int weight;
    int speed;

public:
    Truck(int w, int s){weight = w; speed = s;}
    friend int sp_greater(Truck t, Truck c);
};

int sp_greater(Truck t, Truck c) {
    return c.speed - t.speed;
}

int main(){
    int t;
    Car c1(6,55),c2(2,120);
}