#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class WordNode
{
public:
    // Constructors/Destructors
    WordNode();
    WordNode(const string english,const string french,const string example);
    WordNode(const WordNode &node);
    ~WordNode();

    // Mutator methods
    void setEnglish(const string english);
    void setFrench(const string french);
    void setExample(const string example);
    void setNext(WordNode *next);

    // Accessor methods
    string getEnglish() const;
    string getFrench() const;
    string getExample() const;
    WordNode *getNext() const;

    // Print methods
    void print() const;

private:
    //Private variable declarations
    string English;
    string French;
    string Example;
    WordNode *Next;
};