#include <algorithm>
#include <string>
using namespace std;

bool LengthOfLastWord(string& s)
{
    int len = 0;
    int tail = s.size() - 1;

    while (tail >= 0 && s[tail] == ' ')
    {
        tail--;
    }
    
    while (tail >= 0 && s[tail] != ' ')
    {
        len++;
        tail--;
    }
    
    return len;
}  