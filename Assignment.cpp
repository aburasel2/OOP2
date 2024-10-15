#include<iostream>
using namespace std;

class Truck;
class Bike;

class Vehicle {
    private:
    int speed;

    public:
          Vehicle(int s) {
              speed = s;
          }

    int getSpeed(){
              return speed;
          }
};

class Car : public Vehicle {
            private:
            int deck;

    public:
    Car(int speed, int deck):Vehicle(speed) {
        this->deck = deck;
    }
    int getDeck() {
        return deck;
    }

    friend int secondHighestSpeed(Car C, Truck T, Bike B);
};


class Truck : public Vehicle {
        private:
            int container;
    public:
         Truck(int speed, int container):Vehicle(speed) {
             this->container = container;
         }

    int getContainer() {
             return container;
         }

    friend int secondHighestSpeed(Car C, Truck T, Bike B);
};

class Bike : public Vehicle {
    private:
    int handle;
    public:
    Bike(int speed, int handle):Vehicle(speed) {
        this->handle = handle;
    }

    int getHandle() {
        return handle;
    }
    friend int secondHighestSpeed(Car C, Truck T, Bike B);

};

int secondHighestSpeed(Car C, Truck T, Bike B) {
    int first, second;
    if(C.getSpeed()>T.getSpeed()&&C.getSpeed()<B.getSpeed()) {
        first=C.getSpeed();
        second=(T.getSpeed()>B.getSpeed()) ? T.getSpeed() : B.getSpeed();
    }
    else if()
}