#include "WordNode.h"

class Dictionary
{
public:
    // Constructors/Destructors
    Dictionary();
    Dictionary(const Dictionary &dictionary);
    ~Dictionary();

    // Mutator methods
    void insertNodeSorted(const string english, const string french, const string example);
    void deleteNode(const string english);
    void deleteDictionary(); // Can also be in the destructor
    void setHead(WordNode *head);
    void setTail(WordNode *tail);
    bool readFile(const string filename);
    void writeFile(const string filename);

    // Accessor methods
    int length() const;
    WordNode *getHead() const;
    WordNode *getTail() const;
    WordNode *searchFrench(const string french) const;
    WordNode *searchEnglish(const string english) const;

    // Print methods
    void print() const;

private:
    //Private variable declarations
    WordNode *Head;
    WordNode *Tail;
};
