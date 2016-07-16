#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int UniqueDigitNumbers(int n) 
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 10;
    }
    int base = 9;
    int count = 10;
    int i = 2;
    while(i <= n)
    {
        base = base * (9 - i + 2);
        count = count + base;
        i++;
    }

    return count;
}