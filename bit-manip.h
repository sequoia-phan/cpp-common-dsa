#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

unsigned int extractBits(unsigned int num, unsigned int pos, unsigned int k)
{
    unsigned int shifted = num >> pos;
    unsigned int mask = (1 << k) - 1;

    return shifted & mask;
}

unsigned int bitwise_or(unsigned int num, unsigned int bit_position)
{
    // Create a mask with only the 5th bit set to 1
    unsigned int mask = 1 << bit_position;

    // Set the bit using OR
    num = num | mask;
    return num;
}

int count_set_bits(int n)
{
    int count = 0;

    // return till n becomes 0
    while (n)
    {
        // turn off/reset the rightmost set bit
        n &= (n - 1);

        // increment the count of set bits
        count++;
    }
    return count;
}
/**
 *  time complexity: O(log2n), where 2 is base and n is the given number.
 *  auxiliary space: O(1).
 */

#endif