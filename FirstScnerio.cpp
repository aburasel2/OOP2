//
// Created by opi on 9/17/24.
//
#include <iostream>
using namespace std;
class Truck;
class Bike;

class Vehicle {
protected:
    int speed;

public:
    Vehicle(int conSpeed) {
        this->speed=conSpeed;

    }

    int getSpeed(){
        return speed;
    }



};

class Car : public Vehicle {
private:
    int dec;

public:
     Car(int speed, int dec) : Vehicle(speed) {
        this->dec = dec;
     }

    int getDec() {
         return dec;
     }

    friend int secondHS(Car c, Truck t, Bike b);
};

class Truck : public Vehicle {
private:
    int container;

public:
    Truck(int speed, int container) : Vehicle(speed) {
        this->container=container;
    }
    int getContainer() {
        return container;
    }
    friend int secondHS(Car c, Truck t, Bike b);
};

class Bike : public Vehicle {
private:
    int handle;

public:
    Bike(int speed, int handle) : Vehicle(speed) {
        this->handle=handle;
    }
    int getHandle() {
        return handle;
    }
    friend int secondHS(Car c, Truck t, Bike b);
};

int secondHS(Car c, Truck t, Bike b) {
    int first, second;

    if (c.getSpeed() > t.getSpeed() && c.getSpeed() > b.getSpeed()) {
        first=c.getSpeed();
        second = (t.getSpeed()>b.getSpeed()) ? t.getSpeed() : b.getSpeed();
    }
    else if (t.getSpeed() > c.getSpeed() && t.getSpeed() > b.getSpeed()) {
        first=t.getSpeed();
        second = (c.getSpeed()>b.getSpeed()) ? c.getSpeed() : b.getSpeed();
    }
    else {
        first=b.getSpeed();
        second = (c.getSpeed()>t.getSpeed()) ? c.getSpeed() : t.getSpeed();
    }

    return second;
}

int main() {
    Car car(200,2);
    Truck truck(150,3);
    Bike bike(50,3);


    cout<< "Second highest speed is: " <<secondHS(car,truck,bike);
}

