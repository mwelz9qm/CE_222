#pragma once
#include<string>
using namespace std;

//interfacefor personType
class personType
{ 
    protected:
        string firstName;
        string lastName;

    public:

        void printInfo() const;
        void setName(string first, string last); //setter
        string getFirstName() const; //getters
        string getLastName() const;
        personType(string first = "Jane", string last = "Doe"); //constructor with default parameters

};

//interface for dateType

class dateType
{
    protected:
        int month;
        int day;
        int year;
    public:
        dateType(int m = 1, int d = 1, int y = 2000); //constructor with default parameters
        //getters
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        void printDate() const;
        void setDate(int m, int d, int y); //setter
};

//a class partly composed of dateType and personType objects
//interface for personalInfo

class personalInfo
{public:
    void setPersonalInfo(string first, string last, int m, int d, int y, string add); //setter
    void printPersonalInfo() const;
    string getAddress()const;
    //constructor with default parameters
    personalInfo(string first = "Jane", string last = "Doe", int m = 1, int d = 1, int y = 2000, string add = "123 Fake St");

protected:
    personType name;
    dateType bDay;
    string address;
};