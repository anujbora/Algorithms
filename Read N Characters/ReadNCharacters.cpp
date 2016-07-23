#include <iostream>
#include <algorithm>
using namespace std;


/* 
 *  API
 */

int read4(char buf[])
{
    int readBytes;

    // ....
    // Performs some operations
    // ....

    // Returns number of bytes read
    return readBytes;
}


/**
 * @param buf Destination buffer
 * @param n   Maximum number of characters to read
 * @return    The number of characters read
 */
int ReadNCharacters(char buf[], int n) 
{       
    char buffer[4];
    bool endOfFile = false;
    int readBytes = 0;
    
    while (readBytes < n && !endOfFile) 
    {
        int currReadBytes = read4(buffer);
        
        if (currReadBytes != 4) 
        {
            endOfFile = true;
        }

        int length = min(n - readBytes, currReadBytes);

        for (int i=0; i<length; i++) 
        {
            buf[readBytes + i] = buffer[i];
        }

        readBytes += length;
    }
    
    return readBytes;
}