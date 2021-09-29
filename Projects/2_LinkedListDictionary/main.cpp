#include "Dictionary.h"

// Horizontal rule length for the main menu
const int HRULE_LENGTH = 35;

//===============================================================================
// getChoice function that prints the program's main menu, then obtains and
// returns the value of the user's choice
//===============================================================================
int getChoice()
{
    //Variable Declarations
    int choice;

    // Prints menu and prompts the user for their choice
    cout << string(HRULE_LENGTH, '-') << endl
         << string(HRULE_LENGTH / 7, ' ') << "English->French Dictionary" << endl
         << string(HRULE_LENGTH, '-') << endl
         << "(1) Print Dictionary" << endl
         << "(2) Search" << endl
         << "(3) Example Sentence" << endl
         << "(4) Add Entry" << endl
         << "(5) Remove Entry " << endl
         << "(6) Save & Quit" << endl
         << "Please select an option from 1...5 from the ones provided above >> ";

    // Store the user's input, error check, and then return it
    cin >> choice;

    while (choice < 1 || choice > 6)
    {
        cout << "Sorry, that is not a valid option. Please enter a value from 1...5 >> ";
        cin >> choice;
    }

    return choice;
}

int main()
{
    // Variable Declarations
    bool quit = false;
    //For read and write file methods
    string filename = "none";
    //For the two search methods
    string search = "none";
    WordNode *result = NULL;
    //For the Add/Remove entry options
    string english = "none";
    string french = "none";
    string example = "none";

    Dictionary French;

    // Ask user for input file containing dictionary entries and import
    cout << "Please enter the name of the CSV file that you would like to link to this program >> ";
    cin >> filename;

    while (!French.readFile(filename))
    {
        cout << "Sorry, that file was not found in this directory. Please try again >> ";
        cin >> filename;
    }

    // Continues looping until the user chooses option 6
    while (!quit)
    {
        switch (getChoice())
        {
        case 1:
            // Prints the entire dictionary
            French.print();
            break;
        case 2:
            cout << "Please enter the English word you would like to translate >> ";
            cin >> search;

            result = French.searchEnglish(search);

            // Returns an error if not found, otherwise outputs the results
            if (result == NULL)
            {
                cout << "Sorry, that word could not be found in the dictionary. Please try another search query." << endl;
            }
            else
            {
                cout << result->getEnglish() << " -----> " << result->getFrench() << endl;
            }
            break;
        case 3:
            cout << "Please enter the French word you would like to see an example sentence for >> ";
            cin >> search;

            // Searches for the french word and stores the location
            result = French.searchFrench(search);

            // Returns an error if not found, otherwise outputs the results
            if (result == NULL)
            {
                cout << "Sorry, that word could not be found in the dictionary. Please try another search query." << endl;
            }
            else
            {
                cout << result->getFrench() << " -----> " << result->getExample() << endl;
            }
            break;
        case 4:
            cout << "Please enter an English word that you would like to add to the dictionary >> ";
            // Clears the input buffer so that this getline doesn't pick up the leftover characters in the input stream
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getline(cin, english);

            result = French.searchEnglish(english);

            // Returns an error if the word already exists, and if not, prompts the user for more information
            if (result == NULL)
            {
                cout << "Next, enter the French translation >> ";
                getline(cin, french);
                cout << "Finally, enter the example sentence you would like to use for this word pair >> ";
                getline(cin, example);

                French.insertNodeSorted(english, french, example);

                cout << english << " has been added to the Dictionary!" << endl;
            }
            else
            {
                cout << "It seems that word already exists in this dictionary, so it cannot be added at this time." << endl;
            }

            break;
        case 5:
            cout << "Please enter the English word that you would like to remove from the dictionary >> ";
            // Clears the input buffer so that this getline doesn't pick up the leftover characters in the input stream
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getline(cin, english);

            result = French.searchEnglish(english);

            if (result == NULL)
            {
                cout << "Sorry, that word was not found in the dictionary, so it cannot be deleted." << endl;
            }
            else
            {
                French.deleteNode(english);
                cout << english << " has been succesfully deleted!" << endl;
            }

            break;
        case 6:
            French.writeFile(filename);
            cout << "File saved!" << endl;
            quit = true;
            break;
        }
    }

    return 0;
}
