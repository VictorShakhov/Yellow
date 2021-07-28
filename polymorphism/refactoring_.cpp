#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <typeinfo>

using namespace std;

template <typename T>
string GetType(const T &object)
{
    string type = typeid(object).name();
    return string(type.begin() + 1, type.end());
}

class People
{
public:
    People(const string &_name)
        : Name(_name)
    {
    }

    string GetName() const
    {
        return Name;
    }

    virtual void Walk(const string &destination) const = 0;

    virtual void Check(const People &p) const {};

protected:
    void Print(const string &source, const string &target = "") const
    {
        cout << GetType(*this) << ": " << Name << source << target << endl;
    }
    const string Name;
};

class Student : public People
{
public:
    Student(const string &_name, const string &_favouriteSong)
        : People(_name),
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
        : People(_name),
          Subject(_subject)
    {
    }

    void Walk(const string &destination) const override
    {
        Print(" walks to: ", destination);
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
        : People(_name)
    {
    }

    void Walk(const string &destination) const override
    {
        Print(" walks to: ", destination);
    }

    void Check(const People &p) const
    {
        string type = GetType(p);
        cout << "Policeman: " << Name << " checks " << type << ". " << type << "'s name is: " << p.GetName() << endl;
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
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}