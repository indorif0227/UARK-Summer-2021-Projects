#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node
{
public:
    // Constructors and Destructors
    Node();
    Node(const string county, const int key, const int cases);
    ~Node();

    // Getters and Accessors
    string getLocation() const;
    int getKey() const;
    int getCases() const;
    Node *getNext() const;

    // Setters and Mutators
    void setLocation(const string county);
    void setKey(const int key);
    void setCases(const int cases);
    void setNext(Node *next);

    // Print Methods
    void print();

private:
    string Location;
    int Key;
    int Cases;
    Node *Next;
};

//--------------------------------------------------------------//
//             Class method definitons for Node                 //
//--------------------------------------------------------------//

// Constructors and Destructors
Node::Node()
{
    Location = "none";
    Key = -1;
    Cases = -1;
    Next = NULL;
}

Node::Node(const string location, const int key, const int cases)
{
    Location = location;
    Key = key;
    Cases = cases;
    Next = NULL;
}

Node::~Node()
{
}

// Getters and Accessors
string Node::getLocation() const
{
    return Location;
}

int Node::getKey() const
{
    return Key;
}

int Node::getCases() const
{
    return Cases;
}

Node *Node::getNext() const
{
    return Next;
}

// Setters and Mutators
void Node::setLocation(const string location)
{
    Location = location;
}

void Node::setCases(const int cases)
{
    Cases = cases;
}

void Node::setKey(const int key)
{
    Key = key;
}

void Node::setNext(Node *next)
{
    Next = next;
}

// Print Methods
void Node::print()
{
    int hRule = 50;
    cout << string(hRule, '-') << endl
         << "| Location: " << Location << endl
         << "| Cases: " << Cases << endl
         << "| Hash Key: " << Key << endl;
}
