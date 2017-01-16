#include <iostream>

using namespace std;

int main()
{
  char a[] = {1, 2, 3, 4, 5};
  char b[] = {6, 7, 8, 9, 10};

  char *ptr1 = (char*) (&a + 1);
  char *ptr2 = (char*) (a + 1);

  cout << (int)*(ptr1 - 1) << ' ' << (int)*(ptr2 - 1) << endl;
  cout << (int)a[0] << ' ' << &a << endl;
}
