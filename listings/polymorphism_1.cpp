#include <iostream>

using namespace std;

class ITouhou {
 public:
  ITouhou() { cout << "ITouhou constructed" << endl; }
  virtual ~ITouhou() { cout << "ITouhou destructed" << endl; }
  virtual string name() const = 0;
};

class Youkai : public ITouhou {
 public:
  Youkai() : ITouhou() { cout << "Youkai constructed" << endl; }
  virtual ~Youkai() { cout << "Youkai destructed" << endl; }
};

class IFlyable {
 public:
  IFlyable() { cout << "IFlyable constructed" << endl; }
  virtual ~IFlyable() { cout << "IFlyable destructed" << endl; }
  virtual void fly() { cout << "IFlyable::fly()" << endl; }
};

class Yuuka : public Youkai, public IFlyable {
 public:
  Yuuka() : Youkai(), IFlyable() { cout << "Yuuka constructed" << endl; }
  ~Yuuka() { cout << "Yuuka destructed" << endl; }
  string name() const { return "Yuuka"; }
  void fly() { cout << "Yuuka::fly()" << endl; }
};

int main() {
  ITouhou *y1 = new Yuuka();
  delete y1;

  cout << "=====" << endl;

  Youkai *y2 = new Yuuka();
  delete y2;

  cout << "=====" << endl;

  Yuuka *y3 = new Yuuka();
  y3->fly();
  delete y3;

  cout << "=====" << endl;

  IFlyable *y4 = new Yuuka();
  y4->fly();
  delete y4;

  return 0;
}
