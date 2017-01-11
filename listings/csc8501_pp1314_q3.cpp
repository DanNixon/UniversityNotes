#include <iostream>

class TwlvTime
{
  public:
    TwlvTime(int hours, int seconds)
      : hours(hours), seconds(seconds)
    {
    }

    TwlvTime operator+(const TwlvTime& t)
    {
      TwlvTime time(*this);
      time.hours += t.hours;
      time.seconds += t.seconds;
      return time;
    }

  public:
    int hours;
    int seconds;
};

int main()
{
  TwlvTime t1(4, 37);
  TwlvTime t2(2, 12);

  TwlvTime t3 = t1 + t2;

  std::cout << t3.hours << ":" << t3.seconds << '\n';

  return 0;
}
