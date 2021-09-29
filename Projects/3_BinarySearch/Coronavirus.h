#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class Coronavirus
{
public:
    // Constructors and Destructors
    Coronavirus();
    Coronavirus(const string county, const string state, const string jan, const string mar, const string jun);
    Coronavirus(const Coronavirus &source);
    ~Coronavirus();

    // Getters and Accesors
    string getState() const;
    string getCounty() const;
    int getJan() const;
    int getMar() const;
    int getJun() const;

    // Setters and Mutators
    void setState(const string state);
    void setCounty(const string county);
    void setJan(const float jan);
    void setMar(const float mar);
    void setJun(const float jun);

    // Other
    float calcPercentJanMar() const;
    float calcPercentJanJun() const;

    // Print methods
    void print(const float menuHRule) const;

private:
    string County;
    string State;
    // Number of cases measured sometime in their respecitve months
    float Jan;
    float Mar;
    float Jun;
};