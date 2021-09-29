#include <iostream>
using namespace std;

class DoggyDayCare
{
private:
	//Declare class variables
	string name;
	string breed;
	float energyLevel;
	float weight;
	float age;

public:
	//Constructors and destructor
	DoggyDayCare();
    DoggyDayCare(const DoggyDayCare & CopyMe);
	~DoggyDayCare();

	//Accessor methods
	string getName() const;
	string getBreed() const;
	float getEnergyLevel() const;
	float getWeight() const;
	float getAge() const;

	//Mutator methods
	void setName(const string n);
	void setBreed(const string b);
	void setEnergyLevel(float e);
	void setWeight(float w);
	void setAge(float a);
};
