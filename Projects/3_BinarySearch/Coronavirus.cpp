#include "Coronavirus.h"

//-------------------------------------------------//
//          Constructors and Destructors           //
//-------------------------------------------------//

Coronavirus::Coronavirus()
{
    State = "none";
    County = "none";
    Jan = -1;
    Mar = -1;
    Jun = -1;
}

Coronavirus::Coronavirus(const string county, const string state, const string jan, const string mar, const string jun)
{
    County = county;
    State = state;
    Jan = stof(jan);
    Mar = stof(mar);
    Jun = stof(jun);
}

Coronavirus::Coronavirus(const Coronavirus &source)
{
    County = source.County;
    State = source.State;
    Jan = source.Jan;
    Mar = source.Mar;
    Jun = source.Jun;
}

Coronavirus::~Coronavirus()
{
}

//-------------------------------------------------//
//               Getters and Accesors              //
//-------------------------------------------------//
string Coronavirus::getState() const
{
    return State;
}

string Coronavirus::getCounty() const
{
    return County;
}

int Coronavirus::getJan() const
{
    return Jan;
}

int Coronavirus::getMar() const
{
    return Mar;
}

int Coronavirus::getJun() const
{
    return Jun;
}
//-------------------------------------------------//
//             Setters and Mutators                //
//-------------------------------------------------//
void Coronavirus::setState(const string state)
{
    State = state;
}

void Coronavirus::setCounty(const string county)
{
    County = county;
}

void Coronavirus::setJan(const float jan)
{
    Jan = jan;
}

void Coronavirus::setMar(const float mar)
{
    Mar = mar;
}

void Coronavirus::setJun(const float jun)
{
    Jun = jun;
}

//-------------------------------------------------//
//                     Other                       //
//-------------------------------------------------//

float Coronavirus::calcPercentJanMar() const
{
    return (((Mar / Jan) - 1) * 100.0);
}

float Coronavirus::calcPercentJanJun() const
{
    return (((Jun / Jan) - 1) * 100.0);
}

//-------------------------------------------------//
//                 Print Methods                   //
//-------------------------------------------------//

void Coronavirus::print(const float menuHRule) const
{
    float printHRule = menuHRule / 2;

    cout << string(printHRule, '-') << endl
         << "|County: " << County << endl
         << "|State: " << State << endl
         << fixed << setprecision(0)
         << "|Cases from January: " << Jan << endl
         << "|Cases from March: " << Mar << endl
         << "|Cases from June: " << Jun << endl
         << fixed << setprecision(2)
         << "|Percent change in cases from January to March: " << calcPercentJanMar() << "%" << endl
         << "|Percent change in cases from January to June: " << calcPercentJanJun() << "%" << endl
         << string(printHRule, '-') << endl;
}
