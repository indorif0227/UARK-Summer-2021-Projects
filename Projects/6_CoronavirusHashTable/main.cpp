#include "HashTable.hpp"

int PrintMenu()
{
    int hRule = 50;
    int choice = 0;

    cout << string(hRule, '-') << endl
         << string(hRule / 4, ' ') << "Coronavirus Database V2" << endl
         << string(hRule, '-') << endl
         << "| (1) Hash #1" << endl
         << "| (2) Hash #2" << endl
         << "| (3) Hash #3" << endl
         << "| (4) Search Table" << endl
         << "| (5) Quit" << endl
         << "| Please enter your choice here >> ";

    cin >> choice;

    while (choice < 1 || choice > 5)
    {
        cout << "| Sorry, that is an invalid choice. Please try again >> ";
        cin >> choice;
    }

    return choice;
}

int main()
{
    bool quit = false;
    int tableID;
    string filename;
    string query;

    cout << "| Please enter the file you would like to open >> ";
    getline(cin, filename);

    HashTable CoronavirusHash1(27, 1);
    CoronavirusHash1.ReadFile(filename);
    
    HashTable CoronavirusHash2(500, 2);
    CoronavirusHash2.ReadFile(filename);

    HashTable CoronavirusHash3(1000, 3);
    CoronavirusHash3.ReadFile(filename);
    
    cout << "| Creating Hash Tables..." << endl;

    CoronavirusHash1.WriteFile("HashTable-Hash1.txt");
    CoronavirusHash2.WriteFile("HashTable-Hash2.txt");
    CoronavirusHash3.WriteFile("HashTable-Hash3.txt");

    while (!quit)
    {
        switch (PrintMenu())
        {
        case 1:
            CoronavirusHash1.Print();
            CoronavirusHash1.PrintCollisions();
            break;
        case 2:
            CoronavirusHash2.Print();
            CoronavirusHash2.PrintCollisions();
            break;
        case 3:
            CoronavirusHash3.Print();
            CoronavirusHash3.PrintCollisions();
            break;
        case 4:

            cout << "| Please enter the ID of the hash table that you would like to search >> ";
            cin >> tableID;
            cin.ignore();

            while (tableID < 1 || tableID > 3)
            {
                cout << "| Sorry, that is an invalid table ID, please try again >> ";
                cin >> tableID;
                cin.ignore();
            }

            cout << "| Enter the county and state abbreviation here (Example County, EX) >> ";
            getline(cin, query);

            switch (tableID)
            {
            case 1:
                if (CoronavirusHash1.Search(query))
                {
                    cout << "| Match Found." << endl;
                }
                else
                {
                    cout << "| Sorry, that county does not exist in this database." << endl;
                }
                break;
            case 2:
                if (CoronavirusHash2.Search(query))
                {
                    cout << "| Match Found." << endl;
                }
                else
                {
                    cout << "| Sorry, that county does not exist in this database." << endl;
                }
                break;
            case 3:
                if (CoronavirusHash3.Search(query))
                {
                    cout << "| Match Found." << endl;
                }
                else
                {
                    cout << "| Sorry, that county does not exist in this database." << endl;
                }
                break;
            }
            break;
        case 5:
            quit = true;
            break;
        }
    }
    cout << "| Thank you for using Jessie's Coronavirus Database V2!" << endl;
    return 0;
}