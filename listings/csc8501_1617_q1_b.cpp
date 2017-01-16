#include <iostream>

using namespace std;

void f1(void * d, int s)
{
  if (s == sizeof(double))
  {
    double * p;
    p = (double *) d;
    ++*p;
  }
  else if (s == sizeof(int))
  {
    int * p;
    p = (int *) d;
    ++*p;
  }
}

int main()
{
  double v1[] = {25, 75, 100};
  int v2[] = {72, 76, 98};
  cout << v1 << ' ' << v2 << endl;

  double *p1 = v1;
  int *p2 = v2;

  f1(&v1, sizeof(p1));
  f1(&v2, sizeof(p2));

  cout << v1 << ' ' << v2 << endl;
}
