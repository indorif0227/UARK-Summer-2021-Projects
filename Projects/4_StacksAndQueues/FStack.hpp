#include <iostream>
#include <vector>
using namespace std;

template <typename type>
class FStack
{
public:
    // Constructors and Destructor
    FStack();
    FStack(const FStack &source);
    ~FStack();

    // Getters and Accesors
    bool isFull() const;
    bool isEmpty() const;
    type top() const;
    int size() const;

    // Setters and Mutators
    void push(const type element);
    type pop();

    // Print Methods
    void print() const;

private:
    vector<type> Stack;
    
};

// Constructors and Destructor

// Defualt Constructor
template <typename type>
FStack<type>::FStack()
{
    // Clears vector
    Stack.clear();
}

// Copy Constructor
template <typename type>
FStack<type>::FStack(const FStack &source)
{
    for (int n = 0; n < source.size(); n++)
    {
        Stack.push_back(source.Stack.at(n));
    }
}

// Destructor
template <typename type>
FStack<type>::~FStack()
{
}

// Getters and Accesors

// Checks if stack is full
template <typename type>
bool FStack<type>::isFull() const
{
    return false;
}

// Checks if stack is empty
template <typename type>
bool FStack<type>::isEmpty() const
{
    return Stack.size() == 0 ? true : false;
}

// Returns the top element of the stack; returns 0 if stack is empty
template <typename type>
type FStack<type>::top() const
{
    if (isEmpty())
    {
        cout << "Error retreiving top; stack is empty." << endl;
    }
    else
    {
        return Stack.back();
    }
}

// Returns stack size
template <typename type>
int FStack<type>::size() const
{
    return Stack.size();
}

// Setters and Mutators

// Pushes an element to the top of the stack
template <typename type>
void FStack<type>::push(const type element)
{
    Stack.push_back(element);
}

// Removes an element from the top of the stack
template <typename type>
type FStack<type>::pop()
{
    if (isEmpty())
    {
        cout << "Error: stack underflow" << endl;
    }
    else
    {
        type element = Stack.back();
        Stack.pop_back();
        return element;
    }
}

// Print Methods
template <typename type>
void FStack<type>::print() const
{
    for (int e = 0; e < Stack.size(); e++)
    {
        cout << Stack.at(e) << " ";
    }
    cout << endl;
}