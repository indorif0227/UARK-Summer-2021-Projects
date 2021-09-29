#include "Dictionary.h"

const int HRULE_LENGTH = 35;

//-----------------------Dictionary Method Definitions-------------------------//

//===============================================================================
// Default constructor for the Dictionary class
//===============================================================================
Dictionary::Dictionary()
{
    Head = NULL;
    Tail = NULL;
}

//===============================================================================
// Copy constructor for the Dictionary class
//===============================================================================
Dictionary::Dictionary(const Dictionary &dictionary)
{
    WordNode *tempSource = dictionary.getHead();
    while (tempSource != NULL)
    {
        insertNodeSorted(tempSource->getEnglish(), tempSource->getFrench(), tempSource->getExample());
        tempSource = tempSource->getNext();
    }
}

//===============================================================================
// Destructor for the Dictionary class
//===============================================================================
Dictionary::~Dictionary()
{
    // Deletes all the nodes in order from head to tail and deallocates memory
    WordNode *current = Head;
    WordNode *previous = Head;

    while (current != NULL)
    {
        previous = current;
        current = current->getNext();
        delete previous;
    }
}

//===============================================================================
// Inserts a node in sorted order into the linked list
//===============================================================================
void Dictionary::insertNodeSorted(const string english, const string french, const string example)
{
    WordNode *current = Head;
    WordNode *previous = Head;

    // Walks through to find where the new entry should go
    while (current != NULL && english.compare(current->getEnglish()) > 0)
    {
        previous = current;
        current = current->getNext();
    }

    // If the list is empty, insert at the head
    if (previous == current)
    {
        WordNode *temp = new WordNode;
        temp->setEnglish(english);
        temp->setFrench(french);
        temp->setExample(example);
        temp->setNext(Head);
        Head = temp;
    }

    // Else create a new node in the middle of the list
    else
    {
        previous->setNext(new WordNode);
        previous = previous->getNext();
        previous->setEnglish(english);
        previous->setFrench(french);
        previous->setExample(example);
        previous->setNext(current);

        Tail = Head;
        for (int n = 0; n < length() - 1; n++)
        {
            Tail = Tail->getNext();
        }
    }
}

//===============================================================================
// Deletes a node from the linked list and reassigns pointers
//===============================================================================
void Dictionary::deleteNode(const string english)
{
    WordNode *current = Head;
    WordNode *previous = Head;

    while (current->getEnglish() != english && current != NULL)
    {
        previous = current;
        current = current->getNext();
    }

    if (current != NULL)
    {
        previous->setNext(current->getNext());
        delete current;
    }

    Tail = Head;
    for (int n = 0; n < length() - 1; n++)
    {
        Tail = Tail->getNext();
    }
}

//===============================================================================
// length returns the number of nodes currently present in the linked list
//===============================================================================
int Dictionary::length() const
{
    //Variable declarations
    WordNode *temp = Head;
    int length = 0;

    //Walks the list and counts the number of nodes
    while (temp != NULL)
    {
        length++;
        temp = temp->getNext();
    }
    return length;
}

//===============================================================================
// Searches for an English word and returns its pointer
//===============================================================================
WordNode *Dictionary::searchEnglish(const string english) const
{
    WordNode *temp = Head;
    while (temp->getEnglish() != english)
    {
        if (temp->getNext() == NULL)
        {
            return NULL;
        }
        temp = temp->getNext();
    }
    return temp;
}

//===============================================================================
// Searches for a French word and returns its pointer
//===============================================================================
WordNode *Dictionary::searchFrench(const string french) const
{
    WordNode *temp = Head;
    while (temp->getFrench() != french)
    {
        if (temp->getNext() == NULL)
        {
            return NULL;
        }
        temp = temp->getNext();
    }
    return temp;
}

//===============================================================================
// Reads file and populates the dictionary in sorted order
//===============================================================================

bool Dictionary::readFile(const string filename)
{
    bool found = false;
    //Creating the input stream object and opening the file

    ifstream infile;

    infile.open(filename);

    if (infile.fail())
    {
        infile.close();
        return found;
    }

    //Declarations of temp variables that will be used to read information into the Dictionary object
    string english;
    string french;
    string example;

    while (getline(infile, english, ','))
    {
        getline(infile, french, ',');
        getline(infile, example, '\n');

        insertNodeSorted(english, french, example);
    }

    infile.close();

    found = true;
    cout << filename << " succesfully imported!" << endl;

    return found;
}

//===============================================================================
// Writes the data stored in the dictionary object back to the orignal file
//===============================================================================

void Dictionary::writeFile(const string filename)
{
    ofstream outfile;
    outfile.open(filename);

    WordNode *temp = Head;

    while (temp != NULL)
    {
        outfile << temp->getEnglish() << ','
                << temp->getFrench() << ','
                << temp->getExample() << '\n';

        temp = temp->getNext();
    }

    outfile.close();
}

//===============================================================================
// Prints the entire dictionary
//===============================================================================
void Dictionary::print() const
{
    cout << endl
         << length() << " entries found." << endl;
    WordNode *temp = Head;
    while (temp != NULL)
    {
        temp->print();
        temp = temp->getNext();
    }
}

//===============================================================================
// Sets the Head pointer
//===============================================================================
void Dictionary::setHead(WordNode *head)
{
    Head = head;
}

//===============================================================================
// Sets the Tail pointer
//===============================================================================
void Dictionary::setTail(WordNode *tail)
{
    Tail = tail;
}

//===============================================================================
// Returns the Head pointer
//===============================================================================
WordNode *Dictionary::getHead() const
{
    return Head;
}

//===============================================================================
// Returns the Tail pointer
//===============================================================================
WordNode *Dictionary::getTail() const
{
    return Tail;
}

//------------------------WordNode Method Definitions--------------------------//

//===============================================================================
// Default constructor for the WordNode class
//===============================================================================
WordNode::WordNode()
{
    English = "none";
    French = "none";
    Example = "none";
    Next = NULL;
}

//===============================================================================
// Secondary constructor for the WordNode class
//===============================================================================
WordNode::WordNode(const string english, const string french, const string example)
{
    English = english;
    French = french;
    Example = example;
    Next = NULL;
}

//===============================================================================
// Copy constructor for the WordNode class
//===============================================================================
WordNode::WordNode(const WordNode &node)
{
    English = node.English;
    French = node.French;
    Example = node.Example;
    Next = NULL;
}

//===============================================================================
// Dsetructor for the WordNode class
//===============================================================================

WordNode::~WordNode()
{
}

//===============================================================================
// setEnglish modifies the private English string
//===============================================================================
void WordNode::setEnglish(const string english)
{
    English = english;
}

//===============================================================================
// setFrench modifies the private French string
//===============================================================================
void WordNode::setFrench(const string french)
{
    French = french;
}

//===============================================================================
// setExample modifies the private Example string
//===============================================================================
void WordNode::setExample(const string example)
{
    Example = example;
}

//===============================================================================
// setNext modifies the private Next object pointer
//===============================================================================
void WordNode::setNext(WordNode *next)
{
    Next = next;
}

//===============================================================================
// getEnglish returns the private English string
//===============================================================================
string WordNode::getEnglish() const
{
    return English;
}

//===============================================================================
// getFrench returns the private French string
//===============================================================================
string WordNode::getFrench() const
{
    return French;
}

//===============================================================================
// getExample returns the private Example string
//===============================================================================
string WordNode::getExample() const
{
    return Example;
}

//===============================================================================
// getNext returns the private Next object pointer
//===============================================================================
WordNode *WordNode::getNext() const
{
    return Next;
}

//===============================================================================
// print outputs the data from this particular node to the terminal
//===============================================================================
void WordNode::print() const
{
    cout
        << string(HRULE_LENGTH, '-') << endl
        << "English: " << English << endl
        << "French: " << French << endl
        << "Example Sentence: " << Example << endl;
}
