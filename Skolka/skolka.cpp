#include <iostream>
#include <string>
using namespace std;

class Child {
private:
    int id;
    string name;
    int age;
public:
    Child(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }

    int GetID() { return id; }
    string GetName() { return name; }
    int GetAge() { return age; }
};

class Teacher {
private:
    int id;
    string name;
public:
    Teacher(int i, string n) {
        id = i;
        name = n;
    }

    int GetID() { return id; }
    string GetName() { return name; }
};

class Kindergarten {
private:
    Child* children[100];
    int childCount;
    Teacher* teachers[10];
    int teacherCount;
public:
    Kindergarten() {
        childCount = 0;
        teacherCount = 0;
    }

    void AddChild(Child* c) {
        if (childCount < 100) {
            children[childCount++] = c;
        }
    }

    void AddTeacher(Teacher* t) {
        if (teacherCount < 10) {
            teachers[teacherCount++] = t;
        }
    }

    void ShowChildren() {
        cout << "Děti ve školce:" << endl;
        for (int i = 0; i < childCount; i++) {
            cout << "- " << children[i]->GetName() << " (věk: " << children[i]->GetAge() << ")" << endl;
        }
    }

    void ShowTeachers() {
        cout << "Učitelé ve školce:" << endl;
        for (int i = 0; i < teacherCount; i++) {
            cout << "- " << teachers[i]->GetName() << endl;
        }
    }
};

int main() {
    Kindergarten skolicka;

    Child* pepa = new Child(1, "Pepa", 4);
    Child* eliska = new Child(2, "Eliška", 5);
    skolicka.AddChild(pepa);
    skolicka.AddChild(eliska);

    Teacher* paniJana = new Teacher(1, "Paní Jana");
    skolicka.AddTeacher(paniJana);

    skolicka.ShowTeachers();
    skolicka.ShowChildren();

    cout << "\nENTER pro ukončení..." << endl;
    cin.get();
    return 0;
}