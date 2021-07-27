#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string name) : Name(name) {}

    const string Name;
};

class Dog : public Animal {
public:
    Dog(const string& name) : Animal(name) {}

    void Bark() const {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {
    Dog dog("Stark");
    dog.Bark();
    return 0;
}
