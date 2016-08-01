#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
class Iterator 
{
private:
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator 
{
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) 
    {
        // Initialize any member here.
        // You should only use the Iterator interface methods.
        if (Iterator::hasNext())
        {
            next_num = Iterator::next();
            next_num_valid = true;
        }
        
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() 
    {
        return next_num;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() 
    {
        int curr = next_num;
        
        if(Iterator::hasNext())
        {
            next_num = Iterator::next();
            next_num_valid = true;
        }
        else
        {
             next_num_valid = false;
        }
        return curr;
    }

    bool hasNext() const 
    {
        return next_num_valid;
    }

private:
    int next_num;
    bool next_num_valid;
};