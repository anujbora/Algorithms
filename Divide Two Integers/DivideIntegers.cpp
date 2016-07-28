#include <iostream>
#include <algorithm>
using namespace std;

/**
 *  Solution by jianchao.li.fighter 
 *  (https://discuss.leetcode.com/user/jianchao-li-fighter)
 */

/**
 *  Time Complexity : O((log n)^2); where n is the dividend
 *  Space Complexity : O(1)
 */

int DivideIntegers(int& dividend, int& divisor) 
{
    if (dividend == 0)
    {
        return 0;
    }

    if (dividend == INT_MIN && divisor == -1)
    {
        return 0;
    }

    /**
     *  If both dividend and divisor are negative or positive, sign of result 
     *  is positive. Else, negative.
     */
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    int result = 0;
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);

    /**
     *  Subtract divisor from divident till dividend >= divisor
     */
    while (dvd >= dvs)
    {
        long long temp = dvs;
        long long multiple = 1;

        while (dvd >= (temp << 1))
        {
            temp = temp << 1;
            multiple = multiple << 1;
        }

        dvd = dvd - temp;
        result = result + multiple;
    }

    if (sign == 1)
    {
        return result;
    }
    return -result;
}