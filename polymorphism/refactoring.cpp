#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
    Human(const string& type_, const string& name_) : type(type_), name(name_) {};

    virtual void Walk(const string& destination) const {
        PrintName();
        cout << " walks to: " << destination << endl;
    }

    void PrintName() const {
        cout << type << ": " << name;
    }

    const string type;
    const string name;
};


class Student : public Human {
public:

    Student(const string& name, const string& favourite_song_) : Human("Student", name), favourite_song(favourite_song_) {}

    void Learn() const {
        cout << "Student: " << name << " learns" << endl;
    }

    void Walk(const string& destination) const {
        Human::Walk(destination);
        SingSong();        
    }

    void SingSong() const {
        PrintName();
        cout << " sings a song: " << favourite_song << endl;
    }

private:
    const string favourite_song;
};


class Teacher : public Human {
public:

    Teacher(const string& name, const string& subject_) : Human("Teacher", name), subject(subject_) {
    }

    void Teach() const{
        PrintName();
        cout << " teaches: " << subject << endl;
    }

private:
    const string subject;
};


class Policeman : public Human {
public:
    Policeman(const string& name) : Human("Policeman", name) {
    }

    void Check(Human h) {
        PrintName();
        cout << " checks " << h.type << ". " << h.type << "'s name is: " << h.name << endl;
    }
};

template<typename T>
void VisitPlaces(T t, vector<string> places) {
    for (auto p : places) {
        t.Walk(p);
    }
}

int main() {
    Student s("Ann", "We will rock you");
    Teacher t("Jim", "Math");
    Policeman p("Bob");

    s.Learn();
    s.SingSong();
    t.Teach();
    p.Check(s);
    p.Check(t);
    VisitPlaces(s, {"Moscow", "London"});
    VisitPlaces(t, {"Moscow", "London"});
    VisitPlaces(p, {"Moscow", "London"});
    return 0;
}
