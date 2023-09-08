#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vehicle
{
private:
    string make, model;
    int year;

public:
    void inputData()
    {
        cout << "Enter Company Name: ";
        cin >> make;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Year: ";
        cin >> year;
    }

    void display()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    void saveToFile(ofstream &file)
    {
        file << "Make: " << make << endl;
        file << "Model: " << model << endl;
        file << "Year: " << year << endl;
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    void inputData()
    {
        Vehicle::inputData();

        cout << "Enter Number of Doors: ";
        cin >> numDoors;
    }

    void display()
    {
        Vehicle::display();
        cout << "Number of Doors: " << numDoors << endl;
    }

    void saveToFile(ofstream &file)
    {
        Vehicle::saveToFile(file);
        file << "Number of Doors: " << numDoors << endl;
    }
};

class ToyotaCar : public Car
{
private:
    string trimLevel;

public:
    void inputData()
    {
        Car::inputData();

        cout << "Enter Trim Level: ";
        cin >> trimLevel;
    }

    void display()
    {
        Car::display();
        cout << "Trim Level: " << trimLevel << endl;
    }

    void saveToFile(ofstream &file)
    {
        Car::saveToFile(file);
        file << "Trim Level: " << trimLevel << endl;
    }
};

int main()
{
    ToyotaCar myCar;

    cout << "-------Input Car Info---------" << endl;
    myCar.inputData();

    cout << "-------Output Car Info--------" << endl;
    myCar.display();

    ofstream outputFile("car_info.txt");
    if (outputFile.is_open())
    {
        myCar.saveToFile(outputFile);
        outputFile.close();
        cout << "Car information saved to car_info.txt" << endl;
    }
    else
    {
        cout << "Error opening file for writing." << endl;
    }

    return 0;
}