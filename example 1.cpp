#include<iostream>

using namespace std;

class Truck;

class Car{
    private:
        double speed;

    public:
        Car(double speed){
            this->speed = speed;
        }

        // Friend Function
        friend double sp_greater(Car c, Truck t);

        double getSpeed(){
            return this->speed;
        }

        void setSpeed(double speed){
            this->speed = speed;
        }
};

class Truck{
    private:
        double speed;

    public:
        Truck(double speed){
            this->speed = speed;
        }

        // Friend Function
        friend double sp_greater(Car c, Truck t);
        double getSpeed(){
            return this->speed;
        }

        void setSpeed(double speed){
            this->speed = speed;
        }
};

double sp_greater(Car c, Truck t){
    return (c.speed - t.speed);
}

int main(){
    Car car(10.89);
    Truck truck(15.89);

    double diff = sp_greater(car, truck);

    if(diff >= 0){
        cout << "The car is faster than the truck by " << diff << " units." << endl;
    }
    else{
        cout << "The car is slower than the truck by " << diff << " units." << endl;
    }


    return 0;
}
