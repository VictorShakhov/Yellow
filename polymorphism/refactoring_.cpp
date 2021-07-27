#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Profession
{
public:
    Profession(string& name, string profession) : name_(name), profession_(profession) {};
    virtual void Learn()
    {
        cout << profession_ << " " << name_ << " dont learn!" << endl;
    };
    virtual void Walk(string destination) = 0;
    virtual void Teach()
    {
        cout << profession_ << " " << name_ << " dont teach!" << endl;
    };
    virtual void Check(Profession& p)
    {
        cout << profession_ << " " << name_ << " dont check!" << endl;
    };
    void PrintWalk(string destination)
    {
        cout << profession_ << ": " << name_ << " walks to: " << destination << endl;
    };
    const string name_;
    const string profession_;
};

class Student : public Profession
{
public:

    Student(string name, string favouriteSong) : Profession(name, "Student"), FavouriteSong(favouriteSong) {}

    virtual void Learn()
    {
        cout << profession_ << ": " << name_ << " learns" << endl;
    }

    void Walk(string destination)
    {
        PrintWalk(destination);
        SingSong();
    }

    void SingSong()
    {
        cout << profession_ << ": " << name_ << " sings a song: " << FavouriteSong << endl;
    }

public:
    const string FavouriteSong;
};


class Teacher : public Profession
{
public:

    Teacher(string name, string subject) : Profession(name, "Teacher"), Subject(subject) {}

    virtual void Teach()
    {
        cout << profession_ << ": " << name_ << " teaches: " << Subject << endl;
    }

    virtual void Walk(string destination)
    {
        PrintWalk(destination);
    }

public:
    const string Subject;
};


class Policeman : public Profession {
public:
    Policeman(string name) : Profession(name, "Policeman") {}

    void Check(Profession& t)
    {
        cout << profession_ << ": " << name_ << " checks " << t.profession_ << ". " << t.profession_ << "'s name is: " << t.name_ << endl;
    }

    virtual void Walk(string destination)
    {
        PrintWalk(destination);
    }
};

void VisitPlaces(Profession& profession, vector<string> places)
{
    for (auto p : places) {
        profession.Walk(p);
    }
}

int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
    s.Check(t);
    t.Learn();
    s.Learn();
    t.Teach();
    p.Learn();
    p.Teach();

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}