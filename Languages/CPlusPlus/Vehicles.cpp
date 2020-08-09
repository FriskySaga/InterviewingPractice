// Kevin Tran
// Polymorphism Practice
// g++ -std=c++11 vehicles.cpp
// ./a.out

#include <iostream>
#include <vector>
#include <string>

class Vehicle
{

// private variables are only available to methods in the class
protected:
	std::string color;
	int wheels;
	std::string make;

	// A static variable shares the same value with every object in the class
	static int numOfVehicles;

// Public variables can be accessed by anything with access to the object
public:
	std::string getColor() {
        return color;
    }

	int getWheels() {
        return wheels;
    }
	
    std::string getMake() {
        return make;
    }
	
    void setColor(std::string color) {
        this -> color = color;
    }
	
    void setWheels(int wheels) {
        this -> wheels = wheels;
    }
	
    void setMake(std::string make) {
        this -> make = make;
    }

	// Declared as a prototype
	void setAll(std::string, int, std::string);

	// Declare the constructor
	Vehicle(std::string, int, std::string);

	// Declare the deconstructor
	~Vehicle();

	// An overloaded constructor called when no data is passed
	Vehicle();

	// protected members are available to members of the same class and
	// sub classes

	// Static methods aren't attached to an object and can only access
	// static member variables
	static int getNumOfVehicles() {
        return numOfVehicles;
    }

	// This method will be overwritten later
	void toString();

};

int Vehicle::numOfVehicles = 0;

// Define the protoype method setAll
void Vehicle::setAll(std::string color, int wheels, std::string make){
	// This is used to refer to an object created of this class type
	this -> color = color;
	this -> wheels = wheels;
	this -> make = make;
	Vehicle::numOfVehicles++;

}

// A constructor is called when an object is created
Vehicle::Vehicle(std::string color, int wheels, std::string make) {
	this -> color = color;
	this -> wheels = wheels;
	this -> make = make;

}

// The destructor is called when an object is destroyed
Vehicle::~Vehicle() {

	std::cout << "Vehicle " << this -> make << " destroyed." << std::endl;

}

// A constructor called when no attributes are passed
Vehicle::Vehicle() {
	numOfVehicles++;
}

// This method prints object info to screen and will be overwritten
void Vehicle::toString(){
	std::cout << this -> make << " has a " << this -> color << " color and has "
		<< this -> wheels << " wheels." << std::endl;
}

// We can inherit the variables and methods of other classes
class Bicycle : public Vehicle {
private:
	bool helmet = true;
public:
	void getHelmet() {
        std::cout << helmet << std::endl;
    }

	// Declare the constructor
	Bicycle(std::string, int, std::string, bool);

	// Declare the default constructor and call the default superclass
	// constructor
	Bicycle() : Vehicle(){};

	// Overwrite toString
	void toString();
};

// Bicycle constructor passes the right attributes to the superclass
// constructor and then handles the attribute bark that remains
Bicycle::Bicycle(std::string color, int wheels, std::string make, bool helmet) : Vehicle(color, wheels, make) {
	this -> helmet = helmet;
}

// toString method overwritten
void Bicycle::toString(){

	// Because the attributes were private in Animal they must be retrieved
	// by called the get methods
	std::cout << this -> make << " has a " << this -> color << " color and has "
		<< this -> wheels << " wheel and comes with a " << helmet << " helmet." << std::endl;
}


// This is where execution begins. Attributes can be sent to main
int main() {
	// ---------- CLASSES & OBJECTS ----------
	// Classes are the blueprints for modeling real world objects
	// Real world objects have attributes, classes have members / variables
	// Real world objects have abilities, classes have methods / functions
	// Classes believe in hiding data (encapsulation) from outside code

	// Declare a Vehicle type object
	Vehicle corolla;

	// Set the values for the Animal
	corolla.setColor("Burgundy Red");
	corolla.setWheels(4);
	corolla.setMake("Toyota");

	// Get the values for the Vehicle
	std::cout << corolla.getMake() << " has a " << corolla.getColor() << " color and has "
		<< corolla.getWheels() << " wheels." << std::endl;

    // Declare a vehicle type object
    Vehicle altima;

	altima.setAll("Electric Black", 4, "Nissan");

	// Get the values for the Vehicle
    std::cout << altima.getMake() << " has a " << altima.getColor() << " color and has "
		<< altima.getWheels() << " wheels." << std::endl;

	// Creating an object using the constructor
	Vehicle semi("Retro Red", 18, "Ford");

	// Get the values for the Vehicle
    std::cout << semi.getMake() << " has a " << semi.getColor() << " color and has "
		<< semi.getWheels() << " wheels." << std::endl;

	// Demonstrate the inheriting class Bicycle
	Bicycle trailingBlaze("Neon Green", 2, "Wal-Mart", true);

	// static methods are called by using the class name and the scope operator
	std::cout << "Number of Vehicles: " << Vehicle::getNumOfVehicles() << std::endl;

	trailingBlaze.getHelmet();

	// Test the toString method that will be overwritten
	semi.toString();
	trailingBlaze.toString();

	// We can call the superclass version of a method with the class name
	// and the scope operator
	trailingBlaze.Vehicle::toString();

	// When a function finishes it must return an integer value
	// Zero means that the function ended with success
	return 0;
}

// Takeaways:
// Object-oriented programming is a paradigm centered around objects rather than actions and data rather than logic.
// Polymorphism is presenting the same interface for different data types.
// Abstract classes cannot be instantiated.
// Interfaces are collections of abstract methods.
// Inheritance is a mechanism wherein a new class is derived from an existing class.
// In this program, we used polymorphism to create subclasses from our superclass Vehicle. Each subclass implements the methods defined in Vehicle differently.
