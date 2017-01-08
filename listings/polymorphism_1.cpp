#include <iostream>

using namespace std;

class ITouhou {
 public:
  ITouhou() { cout << "ITouhou (" << name() << ") constructed" << endl; }
  virtual ~ITouhou() { cout << "ITouhou destructed" << endl; }
  virtual string name() const { return "ITouhou"; };
};

class Youkai : public virtual ITouhou {
 public:
  Youkai() : ITouhou() { cout << "Youkai (" << name() << ") constructed" << endl; }
  virtual ~Youkai() { cout << "Youkai destructed" << endl; }
  virtual string name() const { return "Youkai"; };
};

class IFlyable: public virtual ITouhou {
 public:
  IFlyable() { cout << "IFlyable (" << name() <<") constructed" << endl; }
  virtual ~IFlyable() { cout << "IFlyable destructed" << endl; }
  virtual void fly() { cout << "IFlyable::fly()" << endl; }
  virtual string name() const { return "IFlyable"; }
};

class Yuuka : public Youkai, public IFlyable {
 public:
  Yuuka() : Youkai(), IFlyable()
    { cout << "Yuuka " << name() << " constructed" << endl; }
  virtual ~Yuuka() { cout << "Yuuka destructed" << endl; }
  virtual string name() const { return "Yuuka"; }
  virtual void fly() { cout << "Yuuka::fly()" << endl; }
};

class Reimu : public virtual ITouhou, public IFlyable
{
 public:
  Reimu() : ITouhou(), IFlyable()
    { cout << "Reimu (" << name() << ") constructed" << endl; }
  virtual ~Reimu() { cout << "Reimu destructed" << endl; }
  virtual string name() const { return "Reimu"; }
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

  cout << "=====" << endl;

  IFlyable *r1 = new Reimu();
  r1->fly();
  delete r1;

  return 0;
}
