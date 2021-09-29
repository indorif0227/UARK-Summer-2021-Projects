#include "DoggyDayCare.h"

/*****************************************************
|Name:DoggyDayCare
|Parameters:none
|Return values:none
|Purpose:Constructor; initializes all the class variables
*****************************************************/
DoggyDayCare::DoggyDayCare()
{
    name = "none";
    breed = "none";
    energyLevel = -1;
    weight = -1;
    age = -1;
}

/*****************************************************
|Name:DoggyDayCare
|Parameters:DoggyDayCare copyMe - Passes the object that is being copied from to the function
|Return values:none
|Purpose:Copy Constructor
*****************************************************/

DoggyDayCare::DoggyDayCare(const DoggyDayCare &copyMe)
{
    name = copyMe.name;
    breed = copyMe.breed;
    energyLevel = copyMe.energyLevel;
    weight = copyMe.weight;
    age = copyMe.age;
}

/*****************************************************
|Name:~DoggyDayCare
|Parameters:none
|Return values:none
|Purpose:Destructor
*****************************************************/
DoggyDayCare::~DoggyDayCare()
{
}

/*****************************************************
|Name:getName
|Parameters:none
|Return values:string - name of dog
|Purpose:Get name of the dog
*****************************************************/
string DoggyDayCare::getName() const
{
    return name;
}

/*****************************************************
|Name:getBreed
|Parameters:none
|Return values:string - breed of dog
|Purpose:Get breed of the dog
*****************************************************/
string DoggyDayCare::getBreed() const
{
    return breed;
}

/*****************************************************
|Name:getEnergyLevel
|Parameters:none
|Return values:float - energy level of dog
|Purpose:Get energy level of dog
*****************************************************/
float DoggyDayCare::getEnergyLevel() const
{
    return energyLevel;
}

/*****************************************************
|Name:getWeight
|Parameters:none
|Return values:float -  weight of dog
|Purpose:Get weight of dog
*****************************************************/
float DoggyDayCare::getWeight() const
{
    return weight;
}

/*****************************************************
|Name:getAge
|Parameters:none
|Return values:float - age of dog
|Purpose:Get age of dog
*****************************************************/
float DoggyDayCare::getAge() const
{
    return age;
}

/*****************************************************
|Name:setName
|Parameters:string n - name
|Return values:none
|Purpose:Set name of dog
*****************************************************/
void DoggyDayCare::setName(const string n)
{
    name = n;
}

/*****************************************************
|Name:setBreed
|Parameters:string b - breed
|Return values:none
|Purpose:Set breed of dog
*****************************************************/
void DoggyDayCare::setBreed(const string b)
{
    breed = b;
}

/*****************************************************
|Name:setEnergyLevel
|Parameters:float e - energy level
|Return values:none
|Purpose:Set energy level of dog
*****************************************************/
void DoggyDayCare::setEnergyLevel(const float e)
{
    energyLevel = e;
}

/*****************************************************
|Name:setWeight
|Parameters:float w - weight
|Return values:none
|Purpose:Set weight of dog
*****************************************************/
void DoggyDayCare::setWeight(const float w)
{
    weight = w;
}

/*****************************************************
|Name:setAge
|Parameters:float a - age
|Return values:none
|Purpose:Set age of dog
*****************************************************/
void DoggyDayCare::setAge(const float a)
{
    age = a;
}
