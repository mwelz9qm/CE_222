#include <iostream>
using namespace std;

class Base
{
public:
~Base(){
cout << "Base Destructor" << endl;}
};

class Derived : public Base {
    private:
int * data;
public:
Derived() {
data = new int[10];
cout << "Derived Constructor Allocated Memory" << endl;}
~Derived() {
cout << "Derived Destructor" << endl;
delete data;
}
};




class petType
{
protected:
    string name;
public:
    petType(string n = "")
    { name = n;}
    virtual void print() const = 0;
};
class dogType : public petType
{
private:
    string breed;
public:
    dogType(string n = "", string b = "")

    {
        name = n;
        breed = b;
    }
    void print() const
    {
        cout << "Name: " << name << endl;
        cout << "Dog Breed: " << breed << endl;
    }
};


class catType : public petType
{
private:
    string breed;
    string hairType;
public:
    catType(string n = "", string b = "", string h = "")

    {
        name = n;
        breed = b;
        hairType = h;
    }
    void print() const
    {
        cout << "Name: " << name << endl;
        cout << "Cat Breed: " << breed << endl;
        cout << "Hair Type: " << hairType << endl;
    }
};
void callPrint(const petType &p)
{
    p.print();
}
int main() {
   // petType pet("Ralph");
    dogType dog("Ziggy", "Collie");
    dogType dog2("Bauer", "Bernese Mountain Dog");
    catType cat("Hazel", "Tabby", "Medium");
   // pet.print();
    dog.print();
    cout << "*****calling call print" << endl;
    //callPrint(pet);
    callPrint(dog);
    cout << "*****calling print on pointers" << endl;
   // petType *p;
   // p = &pet;
    petType *d = &dog;
   // p->print();
    d->print();

petType *pets[3];
    pets[0] = &dog;
    pets[1] = &cat;
    pets[2] = &dog2;
    cout << "******Printing pets" << endl;
    for (int i = 0; i < 3; i++) {
        pets[i]->print();
        cout << "-----" << endl;
    }

Base * p = new Derived();
delete p;


    return 0;
}