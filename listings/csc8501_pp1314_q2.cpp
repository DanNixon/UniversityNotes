#include <iostream>

using namespace std;

int main()
{
  int list[10];
  int *p;

  p = list;
  for (int x = 1; x <= 10; x++)
  {
    *(p) = x; // The original line would have caused an invalid memory access
              // (element before start of array)
    p++;
    cout << &p << endl; // This outputs the address of the pointer variable p
  }

  for (int i = 0; i < 10; i++)
    cout << list[i] << endl;

  return 0;
}
