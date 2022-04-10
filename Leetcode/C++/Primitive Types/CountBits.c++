// Write a program to count the number of bits that are set to 1 in an integer

#include <iostream>
using namespace std;

// O(1) computation per bit
// Best case : O(1), when the input is 0
// Worst case: O(n), when the input is 111...111
short CountBits(unsigned int x) {
    short num_bits = 0;
    while (x) {
        num_bits += x & 1;
        x >>= 1;
    }

    return num_bits;
}

int main()
{
    cout << CountBits(3);
}