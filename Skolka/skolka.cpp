#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Child {
private:
    string name;
    int id;
    int age;
    string className;
public:
    Child(int i, string n, int a, string cls)
        : id(i), name(n), age(a), className(cls) {}

    int GetID() { return id; }
    string GetName() { return name; }
    int GetAge() { return age; }
    string GetClass() { return className; }

    void SetAge(int newAge) { age = newAge; }
    void SetClass(string newClass) { className = newClass; }

    void Print() {
        cout << "Dítě #" << id << ": " << name << ", " << age << " let, třída " << className << endl;
    }
};

class Teacher {
private:
    string name;
    string className;
public:
    Teacher(string n, string cls)
        : name(n), className(cls) {}

    string GetClass() { return className; }

    void Print() {
        cout << "Učitel: " << name << ", vede třídu " << className << endl;
    }
};

class Kindergarten {
private:
    vector<Child*> children;
    vector<Teacher*> teachers;
public:
    ~Kindergarten() {
        for (auto c : children) delete c;
        for (auto t : teachers) delete t;
    }

    void AddChild(int id, string name, int age, string className) {
        children.push_back(new Child(id, name, age, className));
    }

    void AddTeacher(string name, string className) {
        teachers.push_back(new Teacher(name, className));
    }

    void MoveChildToClass(int id, string newClass) {
        for (auto c : children) {
            if (c->GetID() == id) {
                c->SetClass(newClass);
                cout << "Dítě " << c->GetName() << " přesunuto do třídy " << newClass << endl;
            }
        }
    }

    void BirthdayAll() {
        for (auto c : children) {
            c->SetAge(c->GetAge() + 1);
        }
        cout << "Všichni oslavili narozeniny!" << endl;
    }

    void PrintAll() {
        cout << "\n=== DĚTI ===" << endl;
        for (auto c : children) c->Print();
        cout << "\n=== UČITELÉ ===" << endl;
        for (auto t : teachers) t->Print();
    }
};

int main() {
    Kindergarten skolka;

    skolka.AddChild(1, "Anička", 4, "Motýlci");
    skolka.AddChild(2, "Tomáš", 5, "Berušky");
    skolka.AddChild(3, "Kája", 3, "Motýlci");

    skolka.AddTeacher("Paní Nováková", "Motýlci");
    skolka.AddTeacher("Pan Nový", "Berušky");

    skolka.PrintAll();

    skolka.BirthdayAll();
    skolka.MoveChildToClass(3, "Berušky");

    skolka.PrintAll();

    return 0;
}