// The parity of a binary word is 1 if the number of 1s in the word is odd; 
// otherwise it is 0. For example, the parity of 1011 is 1, 1001 is 0.
// Write a function to compute the parity of a very large number of 64-bit words
// Hint: Use a look up table

#include <iostream>
using namespace std;

// Iteratively tests the value of each bit whle tracking the number of 1s seen so far
// O(n)
short BruteForceParity(unsigned long x) {
    short result = 0;
    while (x) {
        // XOR: 0 for same bits, 1 for different bits
        result ^= (x & 1);
        x >>= 1;
    }
    // result is 0 if the number of 1s is even: every pair of the XOR operators are the same
    // result is 1 if the number of 1s is odd : one pair of the XOR operators arent the same, returning 1
    return result;
} 

short BruteForceImprovedParity(unsigned long x) {
    short result = 0;
    while (x) {
        result ^= 1;
        // Turns off the right most set bit of x
        x &= (x - 1);
    }
    // While loop will run odd number of times if the number of 1s in x is odd, otherwise even number
    return result;
} 

// A 2-bit words look up table example
// Index is 00, 01, 10, 11
long precomputed_parity[4] = {0, 1, 1, 0};

// Compute result with looking up the cache
// Time complexity : function of the size of the keys used to index the lookup table
// O(n/L), where L be the width of the words for which we cache the results, and n the input word size, assuming shifting takes O(1)
// Does not include initialization of the lookup table
short LookUpTableParity(unsigned long x) {
    const int kWordSize = 2;
    const int kBitMask = 0x0003;

    // For instance, x = 11101010
    // For the first two bit, we right shift by 6 => 00000011
    // For the next two bits, we right shift by 4 => 00001110. We mask to extract the last two bits (& with 00000011)
    // For the next two bits, we right shift by 2 => 00111010. We mask (& with 00000011) to extract the last two bits
    // For the last two bits, we just extract with mask.
    return precomputed_parity[x >> (3 * kWordSize)] ^
           precomputed_parity[(x >> (2 * kWordSize) & kBitMask)] ^
           precomputed_parity[(x >> kWordSize) & kBitMask] ^
           precomputed_parity[x & kBitMask];
}

// XOR of a group of bits is its parity
// XOR is associative and commutative, which the order we perform the XORs does not change the result.
// O(log n), ******** needs explanation ******** 
short AssociativityParity(unsigned long x) {

    // For intance, the parity of 11010111 is the same as the parity 1101 ^ 0111 => 1010
    // which in turn is the same as the parity of 10 ^ 10 => 00
    // which in turn is the same as the parity of 0 ^ 0 => 0

    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
}

int main()
{
    // 0000 1011
    int x = 2;
    cout << BruteForceImprovedParity(10) << endl;
    cout << LookUpTableParity(16) << endl;
    cout << AssociativityParity(16) << endl;
}