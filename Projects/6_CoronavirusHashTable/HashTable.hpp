#include "Node.hpp"

class HashTable
{
public:
    // Constructors and Destructors
    HashTable();
    HashTable(int size, int hashType);
    ~HashTable();

    // Getters and Setters
    void SetHashType(const int hashType);

    // Hash Table Methods
    void Insert(const string location, const int cases);
    bool Search(const string location);
    int Hash(const string location);
    void ReadFile(const string filename);
    void WriteFile(const string filename) const;
    void PrintCollisions() const;

    // Print Methods
    void Print() const;

private:
    int HashType = 0;
    int Size;
    int Collisions = 0;
    Node *Table;
};

//--------------------------------------------------------------//
//           Class method definitons for HashTable              //
//--------------------------------------------------------------//

// Constructors and Destructors
HashTable::HashTable()
{
    // Default size variable
    Size = 1000;

    Table = new Node[Size];
}

HashTable::HashTable(int size, int hashType)
{
    Size = size;
    HashType = hashType;

    Table = new Node[Size];
}

HashTable::~HashTable()
{
    delete[] Table;
}

// Hash Table Methods

void HashTable::SetHashType(const int hashType)
{
    HashType = hashType;
}

void HashTable::Insert(const string location, const int cases)
{
    // Calculate Key
    int key = Hash(location);

    // If linked list is empty, create a new entry
    if (Table[key].getKey() == -1)
    {
        Table[key].setLocation(location);
        Table[key].setCases(cases);
        Table[key].setKey(key);
    }
    // If linked list has one node
    else if (Table[key].getNext() == NULL)
    {
        Collisions++;
        // If entry already exists, add on cases
        if (Table[key].getLocation() == location)
        {
            Table[key].setCases(Table[key].getCases() + cases);
            return;
        }

        Table[key].setNext(new Node(location, key, cases));
    }
    // If linked list has more than one node
    else
    {
        // If entry exists, add on cases
        if (Table[key].getLocation() == location)
        {
            Table[key].setCases(Table[key].getCases() + cases);
            return;
        }

        Node *temp = Table[key].getNext();

        // Find the end of the list
        while (temp->getNext() != NULL)
        {
            // If entry already exists, add on cases
            if (temp->getLocation() == location)
            {
                temp->setCases(temp->getCases() + cases);
                return;
            }
            temp = temp->getNext();
            Collisions++;
        }

        // If entry already exists, add on cases
        if (temp->getLocation() == location)
        {
            temp->setCases(temp->getCases() + cases);

            return;
        }

        temp->setNext(new Node(location, key, cases));
    }
}

bool HashTable::Search(const string location)
{
    int found = false;
    int key = Hash(location);

    if (Table[key].getLocation() == location)
    {
        Table[key].print();
        found = true;
    }

    Node *temp = Table[key].getNext();
    while (temp != NULL)
    {
        if (temp->getLocation() == location)
        {
            temp->print();
            found = true;
        }
        temp = temp->getNext();
    }

    return found;
}

int HashTable::Hash(const string location)
{
    if (HashType < 1 || HashType > 3)
    {
        cout << "Error: Invalid Hash Type" << endl;
    }

    int key = 1;

    switch (HashType)
    {
    case 1:
        key = location[0] - 65;
        break;
    case 2:
        key = (location[1] * location[2] * location[0]) ;
        break;
    case 3:
        for (int index = 0; index < location.length(); index++)
        {
            key += location[index];
        }
        break;
    }
    return key % Size;
}

void HashTable::ReadFile( string filename)
{
    fstream infile;
    infile.open(filename);

    // Quit if file not found
    while (infile.fail())
    {
        cout << "Sorry, the file was not found in this directory, please try again >> ";
        getline(cin, filename);
        infile.open(filename);
    }

    string county;
    string state;
    string cases;

    while (getline(infile, county, ','))
    {
        getline(infile, state, ',');
        getline(infile, cases, '\n');

        Insert(county + ", " + state, stoi(cases));
    }

    infile.close();
}

void HashTable::WriteFile(const string filename) const
{
    ofstream outfile;
    outfile.open(filename);

    for (int index = 0; index < Size; index++)
    {
        if (Table[index].getKey() != -1)
        {
            outfile << Table[index].getLocation() << "," << Table[index].getCases() << endl;

            Node *temp = Table[index].getNext();
            while (temp != NULL)
            {
                outfile << temp->getLocation() << "," << temp->getCases() << endl;
                temp = temp->getNext();
            }
        }
    }
    outfile.close();
}

void HashTable::PrintCollisions() const
{
    cout << "Collisions: " << Collisions << endl;
}

// Print Methods
void HashTable::Print() const
{
    for (int index = 0; index < Size; index++)
    {
        if (Table[index].getKey() != -1)
        {
            // Print first node in array element
            Table[index].print();

            // Print rest of linked list
            Node *temp = Table[index].getNext();
            while (temp != NULL)
            {
                temp->print();
                temp = temp->getNext();
            }
        }
    }
    cout << endl;
}
