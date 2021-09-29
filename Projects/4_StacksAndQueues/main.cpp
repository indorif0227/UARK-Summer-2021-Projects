#include "FQueue.hpp"
#include "FStack.hpp"

// Prints the main menu and obtains user input
int printMenu()
{
    int hRule = 30;
    int choice = 0;

    // Print menu
    cout << string(hRule, '-') << endl
         << string(hRule / 3, ' ') << "Main Menu" << endl
         << string(hRule, '-') << endl
         << "1) Bracket Match" << endl
         << "2) Tagging System" << endl
         << "3) Quit" << endl
         << "Please select an option >> ";

    // User input
    cin >> choice;

    // Error checking
    while (choice < 1 || choice > 3)
    {
        cout << "Sorry, that is an invalid option. Please enter a choice from 1...3 >> ";
        cin >> choice;
    }

    return choice;
}

// Checks if all brackets have a match and are in the correct order using the stack
template <typename type>
void checkBrackets(const string query, FStack<type> Stack)
{
    // Clears the stack
    while (Stack.isEmpty() == false)
    {
        Stack.pop();
    }
    bool noBrackets = true;

    // Error checking for empty string case

    // Iterates through string and uses a switch statement to decide what to do with each character
    for (int position = 0; position < query.length(); position++)
    {
        switch (query[position])
        {
        case '{':
            Stack.push(query[position]);
            break;
        case '[':
            Stack.push(query[position]);
            break;
        case '(':
            Stack.push(query[position]);
            break;
        case '<':
            Stack.push(query[position]);
            break;
        case '}':
            if (Stack.top() == '{')
            {
                Stack.pop();
            }
            else
            {
                cout << "The brackets in this string do not appear in the correct order. Error Position: " << position + 1 << endl;
                return;
            }
            break;
        case '>':
            if (Stack.top() == '<')
            {
                Stack.pop();
            }
            else
            {
                cout << "The brackets in this string do not appear in the correct order. Error Position: " << position + 1 << endl;
                return;
            }
            break;
        case ')':
            if (Stack.top() == '(')
            {
                Stack.pop();
            }
            else
            {
                cout << "The brackets in this string do not appear in the correct order. Error Position: " << position + 1 << endl;
                return;
            }
            break;
        case ']':
            if (Stack.top() == '[')
            {
                Stack.pop();
            }
            else
            {
                cout << "The brackets in this string do not appear in the correct order. Error Position: " << position + 1 << endl;
                return;
            }
            break;
        default:
            break;
        }
        if (Stack.size() > 0)
        {
            noBrackets = false;
        }
    }

    // Returns results to user depending on the errors the function ran into
    if (query == "")
    {
        cout << "The string is empty." << endl;
    }
    else if (noBrackets)
    {
        cout << "There were no brackets found in your string." << endl;
    }
    else if (Stack.isEmpty())
    {
        cout << "Success, the brackets in your string are matching and in a suitable order." << endl;
    }
    else
    {
        cout << "The brackets in your string are in the correct order, however not all of your brackets are closed." << endl;
    }
}

// Uses a tagging system based on the Collatz conjecture
template <typename type>
void taggingSystem(const string query, FQueue<type> Queue)
{
    // Clears the queue
    while (Queue.isEmpty() == false)
    {
        Queue.dequeue();
    }
    // Copies the string into the character vector
    for (int n = 0; n < query.length(); n++)
    {
        // Returns an error if the character is not {a,b,c}
        if (query[n] != 'a' && query[n] != 'b' && query[n] != 'c')
        {
            cout << "Error: invalid entry. Please try again." << endl;
            return;
        }
        Queue.enqueue(query[n]);
    }

    // Prints intial Queue
    Queue.print();

    // Continues the Collatz sequence for 100 iterations
    for (int i = 0; i < 100; i++)
    {
        switch (Queue.dequeue())
        {
        case 'a':
            Queue.enqueue('b');
            Queue.enqueue('c');
            break;
        case 'b':
            Queue.enqueue('a');
            break;
        case 'c':
            Queue.enqueue('a');
            Queue.enqueue('a');
            Queue.enqueue('a');
            break;
        }
        Queue.print();
    }
    cout << "Sequence terminated after 100 iterations." << endl;
}

// Main Function
int main()
{
    FStack<char> Stack;
    FQueue<char> Queue;
    int choice = 0;
    string query = "none";

    while (choice != 3)
    {
        choice = printMenu();

        switch (choice)
        {
        case 1:
            cout << "Enter the string that you would like to check for matching brackets >> ";
            cin.ignore();
            getline(cin, query);
            checkBrackets(query, Stack);
            break;
        case 2:
            cout << "Tagging system rules: " << endl
                 << "| 'a' = 'bc' " << endl
                 << "| 'b' = 'a' " << endl
                 << "| 'c' = 'aaa' " << endl
                 << "Enter the string that you would like to run through the tagging system consisting of {a,b,c} >> ";
            cin.ignore();
            getline(cin, query);
            taggingSystem(query, Queue);
            break;
        case 3:
            cout << "Thank you for using Jessie's Bracket Checker/Tagging System!" << endl;
            break;
        }
    }
}