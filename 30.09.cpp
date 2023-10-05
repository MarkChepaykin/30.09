#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Human {
    string name;

public:
    
    Human() {}

    Human(const string& n) : name(n) {}
    
    Human(const Human& other) : name (other.name) {}

    void print() const {
        cout << "Name: " << name << "\n";
    }

    ~Human()
    {

    }
};

class Flat {
    vector<Human> humans;
public:

    void addHuman(const Human& h) {
        humans.push_back(h);
    }

    void printHumans() const {
        for (const Human& h : humans) {
            h.print();
        }
    }
    ~Flat()
    {

    }
};

class House {
    vector<Flat> flats;
public:

    House (int number) : flats(number) {}

    void addHumanToFlat(int number, const Human& h) {
        if (number >= 0 && number < flats.size()) {
            flats[number].addHuman(h);
        }
    }


    void printAll() const {
        for (const Flat& f : flats) {
            f.printHumans();
        }
    }

    ~House()
    {

    }
};

int main()
{
    House h(3); 
    h.addHumanToFlat(0, Human("Mark"));
    h.addHumanToFlat(1, Human("Bark"));
    h.addHumanToFlat(2, Human("Kark"));

    h.printAll();
}
