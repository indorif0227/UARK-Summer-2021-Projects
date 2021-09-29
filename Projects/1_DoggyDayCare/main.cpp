#include "DoggyDayCare.h"
#include <iostream>
#include <fstream>

using namespace std;

const int HRULE_LENGTH = 35;

// Hardcoded ASCII file and array size becase the instructions don't specify user input for these
const int MAX_DOGS = 20;

/*****************************************************
|Name:printMenu
|Parameters:none
|Return values:none
|Purpose:Prints the main menu
*****************************************************/
void printMenu()
{
    cout << string(HRULE_LENGTH, '-') << endl
         << string(HRULE_LENGTH / 3 + 2, ' ') << "Main Menu" << endl
         << string(HRULE_LENGTH, '-') << endl
         << "(1) Import dogs from ASCII file" << endl
         << "(2) Enroll new dog manually" << endl
         << "(3) Search for playmate" << endl
         << "(4) View all dogs" << endl
         << "(5) Save & quit" << endl;
}

/*****************************************************
|Name:getChoice
|Parameters:none
|Return values:none
|Purpose:Prompts user for the choice
*****************************************************/
int getChoice()
{
    int choice;
    cout << endl
         << "Please select a choice from 1...5 >> ";
    cin >> choice;
    cout << endl;

    while (choice < 1 || choice > 5)
    {
        cout << "Sorry, that is an invalid choice. Please enter a value from 1...5 >> ";
        cin >> choice;
        cout << endl;
    }

    return choice;
}

/*****************************************************
|Name:readFile
|Parameters:string filename - location of ASCII file with dog information
|           DoggyDayCare array[] - array containing infromation about all of the dogs in the daycare
|Return values:none
|Purpose:Read the input file and populate the dog object array
*****************************************************/
void readFile(string filename, DoggyDayCare array[])
{
    //Ask user for the name of the file that hey want to read in
    cout << "Please enter the ASCII file containing the dogs that you would like to enroll in the daycare >> ";
    cin >> filename;
    cout << endl;

    // Initilalize and open file
    ifstream infile;
    infile.open(filename);

    // Error message if file fails to open
    if (infile.fail())
    {
        cout << "The file was not found in this directory. Please try again." << endl;
        return;
    }

    // Temp variable to hold values read from the file so that they can be assigned to the class objects
    string temp = "none";
    int index;

    // Search for the first empty index
    for (index = 0; index < MAX_DOGS; index++)
    {
        if (array[index].getAge() == -1)
        {
            break;
        }
    }

    // Read and store values from csv file into the Dog objects; loop until input stream is empty
    while (getline(infile, temp, ','))
    {
        //Checks if the daycare is already full
        if (array[MAX_DOGS - 1].getEnergyLevel() != -1)
        {
            cout << "Sorry, the daycare is currently full, there will not be any new admissions as of this time. You are free to stay and find a playmate, or can quit using option 5." << endl
                 << endl;
            return;
        }

        array[index].setName(temp);

        getline(infile, temp, ',');
        array[index].setAge(stof(temp));

        getline(infile, temp, ',');
        array[index].setBreed(temp);

        getline(infile, temp, ',');
        array[index].setWeight(stof(temp));

        getline(infile, temp, '\n');
        array[index].setEnergyLevel(stof(temp));

        index++;
    }
    infile.close();
}

/*****************************************************
|Name:addDog
|Parameters:DoggyDayCare array[] - array containing infromation about all of the dogs in the daycare
|Return values:none
|Purpose:Add a dog object to the daycare
*****************************************************/
void addDog(DoggyDayCare array[])
{
    // Checks if the daycare is already full
    if (array[19].getAge() != -1)
    {
        cout << "Sorry, the daycare is currently full, there will not be any new admissions as of this time. You are free to stay and find a playmate, or can quit using option 5." << endl;
        return;
    }

    // Variable Declarations
    int index;
    string temp;

    // Search for the first empty index
    for (index = 0; index < MAX_DOGS; index++)
    {
        if (array[index].getAge() == -1)
        {
            break;
        }
    }

    // Asking the user for information on their dog and storing it at that empty index
    cout << "What is the name of your dog? >> ";
    cin >> temp;
    array[index].setName(temp);
    //---------------------------------------
    cout << "How old is your dog? >> ";
    cin >> temp;

    // Error Checking
    while (stof(temp) <= 0)
    {
        cout << "Sorry, that is not a valid age. Please enter a non-negative value >> ";
        cin >> temp;
        cout << endl;
    }


    array[index].setAge(stof(temp));
    //---------------------------------------
    cout << "What breed is your dog? >> ";
    cin >> temp;
    array[index].setBreed(temp);
    //---------------------------------------
    cout << "How much does your dog weigh? >> ";
    cin >> temp;

    // Error Checking
    while (stof(temp) <= 0)
    {
        cout << "Sorry, that is not a valid weight. Please enter a non-negative value >> ";
        cin >> temp;
        cout << endl;
    }

    array[index].setWeight(stof(temp));
    //---------------------------------------
    cout << "How energetic is your dog? (from 1...10) >> ";
    cin >> temp;

    // Error Checking
    while (stof(temp) < 1 || stof(temp) > 10)
    {
        cout << "Sorry, that is not a valid energy level. Please enter a value from 1...10 >> ";
        cin >> temp;
        cout << endl;
    }

    array[index].setEnergyLevel(stof(temp));
    //---------------------------------------

    // User feedback
    cout << "Congragulations, " << array[index].getName() << " has been succesfully added to the daycare!" << endl
         << endl;
}

/*****************************************************
|Name:printAllDogs
|Parameters:DoggyDayCare array[] - array containing infromation about all of the dogs in the daycare
|Return values:none
|Purpose:Print all dogs currently in the daycare
*****************************************************/
void printAllDogs(DoggyDayCare array[])
{
    int index = 0;

    while (array[index].getAge() != -1)
    {
        cout << string(HRULE_LENGTH, '-') << endl
             << "|Name: " << array[index].getName() << endl
             << "|Age: " << array[index].getAge() << endl
             << "|Breed: " << array[index].getBreed() << endl
             << "|Weight: " << array[index].getWeight() << endl
             << "|Energy Level: " << array[index].getEnergyLevel() << endl;

        // Breaks the loop if the daycare is full so that it doesn't throw an error
        if (index >= MAX_DOGS - 1)
        {
            break;
        }
        index++;
    }
    if (index == 0)
    {
        cout << "Sorry, there are no dogs enrolled in the daycare as of this time." << endl
             << endl;
    }
}

/*****************************************************
|Name:findPlaymate
|Parameters:DoggyDayCare array[] - array containing infromation about all of the dogs in the daycare
|Return values:none
|Purpose:Find a playmate based a user-given energy level
*****************************************************/
void findPlaymate(DoggyDayCare array[])
{
    // Variable declarations
    float baseEnergyLevel;
    int matchCount = 0;

    cout << "What is the energy level of your dog? >> ";
    cin >> baseEnergyLevel;
    cout << endl;

    // Basic error checking
    while (baseEnergyLevel < 1 || baseEnergyLevel > 10)
    {
        cout << "Sorry, that is not a valid energy level. Please enter a value from 1...10 >> ";
        cin >> baseEnergyLevel;
        cout << endl;
    }

    // Decides what to do based on the energy level of each dog in the array
    for (int index = 0; index < MAX_DOGS; index++)
    {
        if (array[index].getEnergyLevel() >= baseEnergyLevel - 1 && array[index].getEnergyLevel() <= baseEnergyLevel + 1)
        {
            cout << string(HRULE_LENGTH, '-') << endl
                 << "|Name: " << array[index].getName() << endl
                 << "|Age: " << array[index].getAge() << endl
                 << "|Breed: " << array[index].getBreed() << endl
                 << "|Weight: " << array[index].getWeight() << endl
                 << "|Energy Level: " << array[index].getEnergyLevel() << endl;
            matchCount++;
        }
        else if (array[index].getEnergyLevel() == -1)
        {
            break;
        }
    }

    // Message if no dogs with suitable energy levels were found
    if (matchCount == 0)
    {
        cout << "We apologize; there are no dogs matching your desired energy level in our daycare at this time. However, more dogs will be enrolling so check back soon!" << endl
             << endl;
    }
    else
    {
        cout << endl
             << "There is/are " << matchCount << " dog(s) in our daycare which have suitable energy levels for a playdate with your dog. They are listed above." << endl
             << endl;
    }
}

/*****************************************************
|Name:writeFile
|Parameters:string filename - location of ASCII file with dog information
|           DoggyDayCare array[] - array containing infromation about all of the dogs in the daycare
|Return values:none
|Purpose:Write the dogs saved in the database to the ASCII file
*****************************************************/
void writeFile(string filename, DoggyDayCare array[])
{
    //Ask user for the name of the file that hey want to read in
    cout << "Please enter the name of the file where you would like the dogs to be stored >> ";
    cin >> filename;
    cout << endl;

    // Open output file
    ofstream outfile;
    outfile.open(filename);

    // If it fails, ask again
    while (outfile.fail())
    {
        cout << "The file was not found in this directory. Please try again. >> ";
        cin >> filename;
        outfile.open(filename);
    }

    //  Output data to the ASCII file
    int index = 0;
    while (array[index].getAge() != -1 && index != MAX_DOGS)
    {
        outfile << array[index].getName() << ","
                << array[index].getAge() << ","
                << array[index].getBreed() << ","
                << array[index].getWeight() << ","
                << array[index].getEnergyLevel() << "\n";
        index++;
    }
    outfile.close();
}

//Main function
int main()
{
    // Creates an array of objects called Dogs using the MAX_DOGS constant
    DoggyDayCare Dogs[MAX_DOGS];
    string filename = "none";

    // Only ends the program once the user has decided to quit(Choice 5)
    int choice = -1;
    while (choice != 5)
    {
        // Prints main menu, asks for user input, and then executes their choice
        printMenu();
        choice = getChoice();
        switch (choice)
        {
        case 1:
            // Reads from ASCII file and stores values in array objects
            readFile(filename, Dogs);
            break;
        case 2:
            // Allows the user to manually input information for a dog
            addDog(Dogs);
            break;
        case 3:
            // Prompts a user for an energy level and searches the daycare for dogs with similar values ±1
            findPlaymate(Dogs);
            break;
        case 4:
            printAllDogs(Dogs);
            break;
        case 5:
            // Overwrites the ASCII with the infromation of enrolled dogs in the system
            writeFile(filename, Dogs);
            cout << "Thank you for coming to Jessie's Doggy Daycare!" << endl;
            break;
        }
    }
    return 0;
}