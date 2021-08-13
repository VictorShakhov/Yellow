#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <typeinfo>

using namespace std;

class People
{
public:
    People(const string &_name, const string &_type)
        : Name(_name),
        Type(_type)
    {
    }

    virtual void Walk(const string &destination) const{
        Print(" walks to: ", destination);
    }

    const string Name;
    const string Type;

protected:
    void Print(const string &source, const string &target = "") const
    {
        cout << Type << ": " << Name << source << target << endl;
    }
};

class Student : public People
{
public:
    Student(const string &_name, const string &_favouriteSong)
        : People(_name,"Student"),
          FavouriteSong(_favouriteSong)
    {
    }

    void Walk(const string &destination) const override
    {
        Print(" walks to: ", destination);
        Print(" sings a song: ", FavouriteSong);
    }

    void Learn()
    {
        Print(" learns");
    }

    void SingSong()
    {
        Print(" sings a song: ", FavouriteSong);
    }

private:
    const string FavouriteSong;
};

class Teacher : public People
{
public:
    Teacher(const string &_name, const string &_subject)
        : People(_name,"Teacher"),
          Subject(_subject)
    {
    }

    void Teach()
    {
        Print(" teaches: ", Subject);
    }

private:
    const string Subject;
};

class Policeman : public People
{
public:
    Policeman(const string &_name)
        : People(_name,"Policeman")
    {
    }

    void Check(const People &p) const
    {
        cout << "Policeman: " << Name << " checks " << p.Type << ". " << p.Type << "'s name is: " << p.Name << endl;
    }
};

void VisitPlaces(const People &human, const vector<string> &places)
{
    for (const auto &p : places)
    {
        human.Walk(p);
    }
}

int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    VisitPlaces(p, {"Aksay", "Bikin"});
    VisitPlaces(s, {"Chita", "Dubovka"});
    t.Teach();
    s.Learn();
    s.SingSong();
    p.Check(s);
    p.Check(t);
    return 0;
}