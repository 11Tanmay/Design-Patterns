#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void createVehicle() = 0;
};

class Car : public Vehicle
{
public:
    void createVehicle()
    {
        cout << "Car Created";
    }
};

class Bike : public Vehicle
{
public:
    void createVehicle()
    {
        cout << "Bike Created";
    }
};

class VehicleFactory
{
public:
    static Vehicle *createVehicle(string vehicle_type)
    {
        if (vehicle_type == "car")
        {
            return new Car();
        }
        else if (vehicle_type == "bike")
        {
            return new Bike();
        }
        else
        {
            return nullptr;
        }
    }
};

int32_t main()
{
    while (true)
    {
        string vehicle_type;
        cin >> vehicle_type;

        Vehicle *vehicle = VehicleFactory::createVehicle(vehicle_type);
        vehicle->createVehicle();
    }

    return 0;
}
