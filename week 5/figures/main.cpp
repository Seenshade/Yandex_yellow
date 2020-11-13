#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class Figure{
public:
  virtual string Name() const = 0;
  virtual double Perimeter() const = 0;
  virtual double Area() const = 0;
};

class Rect : public Figure{
public:
  Rect(const int& w, const int& h)
  : width_(w)
  , height_(h)
  {};
  string Name() const override{
    return "RECT";
  }
  double Perimeter() const override {
    return 2*width_ + 2*height_;
  }
  double Area() const override {
    return width_*height_;
  }
private:
  const int width_;
  const int height_; 
};

class Triangle : public Figure{
public:
  Triangle(const int& a, const int& b, const int& c)
  : a_(a)
  , b_(b)
  , c_(c)
  {};
  string Name() const override{
    return "TRIANGLE";
  }
  double Perimeter() const override {
    return a_+b_+c_;
  }
  double Area() const override {
    double h_p = (static_cast<double>(a_+b_+c_))/2;
    return sqrt(h_p * (h_p-static_cast<double>(a_))*(h_p-static_cast<double>(b_))*(h_p-static_cast<double>(c_)));
  }
private:
  const int a_;
  const int b_;
  const int c_; 
};

class Circle : public Figure{
public:
  Circle(const int& r)
  : r_(r)
  {};
  string Name() const override{
    return "CIRCLE";
  }
  double Perimeter() const override {
    return 2*3.14*static_cast<double>(r_);
  }
  double Area() const override {
    return 3.14 * pow((static_cast<double>(r_)),2);
  }
private:
  const int r_;
};

shared_ptr<Figure> CreateFigure(istream& input){
  string str_figure;
  shared_ptr<Figure> f;
  input >> str_figure;
  if (str_figure == "RECT"){
    int a, b;
    input >> a >> b;
    f = make_shared<Rect>(a,b);
  } else if(str_figure == "TRIANGLE"){
    int a, b, c;
    input >> a >> b >> c;
    f = make_shared<Triangle>(a,b,c);
  } else if(str_figure == "CIRCLE"){
    int r;
    input >> r;
    f = make_shared<Circle>(r);
  }
  return f;
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
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