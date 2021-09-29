#include <iostream>
#include <vector>
using namespace std;

template <typename type>
class FQueue
{
public:
    // Constructors and Destructor
    FQueue();
    FQueue(const FQueue &source);
    ~FQueue();

    // Getters and Accesors
    bool isFull() const;
    bool isEmpty() const;
    bool find(type q) const;
    int size() const;

    // Setters and Mutators
    void enqueue(const type element);
    type dequeue();

    // Print Methods
    void print() const;

private:
    vector<type> Queue;
};

// Constructors and Destructor

// Default Constructor
template <typename type>
FQueue<type>::FQueue()
{
    Queue.clear();
}

// Copy Constructor
template <typename type>
FQueue<type>::FQueue(const FQueue &source)
{
    for (int n = 0; n < source.size(); n++)
    {
        Queue.push_back(source.Queue.at(n));
    }
}

// Destructor
template <typename type>
FQueue<type>::~FQueue()
{
}

// Getters and Accesors

// Checks if the queue is full
template <typename type>
bool FQueue<type>::isFull() const
{
    return false;
}

// Checks if the queue is empty
template <typename type>
bool FQueue<type>::isEmpty() const
{
    return Queue.size() == 0 ? true : false;
}

// Gets size of queue
template <typename type>
int FQueue<type>::size() const
{
    return Queue.size();
}

// Finds an element and returns a boolean if it exists in the Queue
template <typename type>
bool FQueue<type>::find(type q) const
{
    for (int n = 0; n < Queue.size(); n++)
    {
        if (Queue.at(n) == q)
        {
            return true;
        }
    }
    return false;
}

// Setters and Mutators

// Adds an element to the end of the queue
template <typename type>
void FQueue<type>::enqueue(const type element)
{
    Queue.push_back(element);
}

// Removes an element from the front of the queue
template <typename type>
type FQueue<type>::dequeue()
{
    if (isEmpty())
    {
        cout << "Error: queue underflow" << endl;
    }
    else
    {
        type element = Queue.front();
        Queue.erase(Queue.begin());
        return element;
    }
}

// Print Methods

// Prints the queue
template <typename type>
void FQueue<type>::print() const
{
    for (int e = 0; e < Queue.size(); e++)
    {
        cout << Queue.at(e);
    }
    cout << endl;
}
