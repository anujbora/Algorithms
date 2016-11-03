#include <iostream>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity : O(log n)
 */

double Power(double x, int n)
{
    if (n == 0)
    {
      return 1;
    }

    if (n == 1)
    {
      return x;
    }

    if (n < 0)
    {
      return (1 / Power(x, -n));
    }

    double result = Power(x, n / 2);

    if (n % 2 == 0)
    {
      return result * result * x;
    }

    return result * result;
}
