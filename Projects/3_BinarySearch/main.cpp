#include "Coronavirus.h"

// File was specified in advance
const string filename = "covid-data.txt";

// Reads coivd-data.txt file and stores data into a vector of Coronavirus objects
void readFile(string filename, vector<Coronavirus> &data)
{
    // Create temporary variables to hold data so that it can be used in the alternate object constructor
    string state;
    string county;
    string jan;
    string mar;
    string jun;

    ifstream infile;
    infile.open(filename);

    // Error checking in case file fails to open
    if (infile.fail())
    {
        cout << "The file was not found in the current directory. Please try again." << endl;
        return;
    }

    // Iterates through and adds objects to the array
    while (getline(infile, state, ','))
    {
        getline(infile, county, ',');
        getline(infile, jan, ',');
        getline(infile, mar, ',');
        getline(infile, jun, '\n');

        data.push_back(Coronavirus(state, county, jan, mar, jun));
    }

    infile.close();
}

int search(vector<Coronavirus> &data, const string county, const string state, const int upperBound, const int lowerBound)
{
    // Set current position to the midpoint of the upper and lower bounds
    int midpoint = (upperBound + lowerBound) / 2;
    // Create match variables to make if statments easier to read
    int matchCounty = data.at(midpoint).getCounty().compare(county);
    int matchState = data.at(midpoint).getState().compare(state);

    if (lowerBound == upperBound - 1)
    {
        return -1;
    }
    // If match, return relevant information
    if (matchCounty == 0 && matchState == 0)
    {
        // cout << "Match found at " << midpoint << "." << endl;
        return midpoint;
    }
    // Else if passed, set upper bound equal to current midpoint
    else if (matchCounty > 0)
    {
        // cout << "Passed; Position = " << midpoint << endl;
        return search(data, county, state, midpoint, lowerBound);
    }
    // Else if not reached, set lower bound equal to current midpoint
    else if (matchCounty < 0)
    {
        // cout << "Not reached; Position = " << midpoint << endl;
        return search(data, county, state, upperBound, midpoint);
    }
    // Else if county name found, but not full match, iterate through the counties until matchState is true
    else if (matchCounty == 0 && matchState > 0)
    {
        return search(data, county, state, upperBound - 1, lowerBound - 1);
    }
    else if (matchCounty == 0 && matchState < 0)
    {
        return search(data, county, state, upperBound + 1, lowerBound + 1);
    }
}

// Increments a counter variable in the main function for every county that had a smaller percent increase of cases during the mask mandate
void countMaskMandate(vector<Coronavirus> data, int &counties, int position)
{
    if (data.at(position).calcPercentJanMar() < data.at(position).calcPercentJanJun())
    {
        counties++;
    }
    position++;
    if (position == data.size())
    {
        return;
    }
    countMaskMandate(data, counties, position);
}

int main()
{
    bool quit = false;
    float menuHRule = 109.0;
    int result = -1;
    int maskMandateCounties = 0;
    string county = "none";
    string state = "none";

    // Creates an empty object vector to store data
    vector<Coronavirus> Data;

    // Reads in all the data from the provided file
    readFile(filename, Data);

    while (!quit)
    {

        // User prompt and input
        cout << string(menuHRule, '=') << endl
             << "||   _____                                  _                  _____        _        _                     ||" << endl
             << "||  / ____|                                (_)                |  __ \\      | |      | |                    ||" << endl
             << "|| | |     ___  _ __ ___  _ __   __ ___   ___ _ __ _   _ ___  | |  | | __ _| |_ __ _| |__   __ _ ___  ___  ||" << endl
             << "|| | |    / _ \\| '__/ _ \\| '_ \\ / _` \\ \\ / / | '__| | | / __| | |  | |/ _` | __/ _` | '_ \\ / _` / __|/ _ \\ ||" << endl
             << "|| | |___| (_) | | | (_) | | | | (_| |\\ V /| | |  | |_| \\__ \\ | |__| | (_| | || (_| | |_) | (_| \\__ \\  __/ ||" << endl
             << "||  \\_____\\___/|_|  \\___/|_| |_|\\__,_| \\_/ |_|_|   \\__,_|___/ |_____/ \\__,_|\\__\\__,_|_.__/ \\__,_|___/\\___| ||" << endl
             << string(menuHRule, '=') << endl
             << "Please enter the county you would like to search for (e.g. Example County) >> ";

        getline(cin, county);

        cout << "Please enter the two letter state code associated with that county (e.g. EX) >> ";

        getline(cin, state);

        // Search for the given state and county, then return relevant information

        result = search(Data, county, state, Data.size() - 1, 0);
        cout << "Searching for " << county << "," << state << "..." << endl;

        // Calculates the number of counties in which the mask mandate was an effective measure
        maskMandateCounties = 0;
        countMaskMandate(Data, maskMandateCounties, 0);

        // Error message if County was not found in the database
        if (result == -1)
        {
            cout << "Sorry, the County could not be found. Please try again." << endl;
        }
        else
        {
            // Prints results and the percentange increases in cases in 3 month periods
            Data.at(result).print(menuHRule);
        }

        string choice;
        cout << "Would you like to continue?(Y/N) >> ";
        getline(cin, choice);

        while (choice != "Y" && choice != "N" && choice != "y" && choice != "n")
        {
            cout << "Sorry that is not a valid choice. Try again >> ";
            getline(cin, choice);
        }

        if (choice == "Y" || choice == "y")
        {
        }
        else if (choice == "N" || choice == "n")
        {
            cout << "Total number of counties with lower reported cases while the mask mandate was in effect: " << maskMandateCounties << " out of " << Data.size() << endl;
            quit = true;
        }
    }
    return 0;
}