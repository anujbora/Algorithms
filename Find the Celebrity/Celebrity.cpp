#include <iostream>
#include <algorithm>
using namespace std;

bool knows(int a, int b)
{
    /*
     *   API Implementation which returns true if a knows b
     */
}

int Celebrity(int n) 
{
    int candidate = 0;

    for (int i = 1; i < n; i++)
    {
        if (knows(candidate, i))
        {
            candidate = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != candidate)
        {
            if(knows(candidate, i) || !knows(i, candidate))
            {
                return -1;
            }
        }
    }

    return candidate;
}