#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(int a_, int b_, int c_) {
        a = a_;
        b = b_;
        c = c_;
    }

    string Name() const override {
        return "TRIANGLE";
    }

    double Perimeter() const override {
        return a + b + c;
    }

    double Area() const override {
        double p = Perimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
private:
    int a;
    int b;
    int c;
};

class Rect : public Figure {
public:
    Rect(int a_, int b_) {
        a = a_;
        b = b_;
    }

    string Name() const override {
        return "RECT";
    }

    double Perimeter() const override {
        return 2 * (a + b);
    }

    double Area() const override {
        return a * b;
    }
private:
    int a;
    int b;
};

class Circle : public Figure {
public:
    Circle(int r_) {
        r = r_;
    }

    string Name() const override{
        return "CIRCLE";
    }

    double Perimeter() const override {
        return 2 * pi * r;
    }

    double Area() const override {
        return pi * r * r;
    }
private:
    int r;
    double pi = 3.14;
};


shared_ptr<Figure> CreateFigure(istringstream& is) {
    string figure_type;
    int a, b, c, r;
    is >> figure_type;
    if(figure_type == "TRIANGLE") {
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    } else if(figure_type == "RECT") {
        is >> a >> b;
        return make_shared<Rect>(a, b);
    } else if(figure_type == "CIRCLE") {
        is >> r;
        return make_shared<Circle>(r);
    }
    return shared_ptr<Figure>();
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
