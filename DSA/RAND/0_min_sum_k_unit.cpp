#include <iostream>

// 2310. Sum of Numbers With Units Digit K

// Given two integers num and k, consider a set of positive integers with the following properties:

// The units digit of each integer is k.
// The sum of the integers is num.
// Return the minimum possible size of such a set, or -1 if no such set exists.

// Note:

// The set can contain multiple instances of the same integer, and the sum of an empty set is considered 0.
// The units digit of a number is the rightmost digit of the number.

// Example 1:

// Input: num = 58, k = 9
// Output: 2
// Explanation:
// One valid set is [9,49], as the sum is 58 and each integer has a units digit of 9.
// Another valid set is [19,39].
// It can be shown that 2 is the minimum possible size of a valid set.
// Example 2:

// Input: num = 37, k = 2
// Output: -1
// Explanation: It is not possible to obtain a sum of 37 using only integers that have a units digit of 2.
// Example 3:

// Input: num = 0, k = 7
// Output: 0
// Explanation: The sum of an empty set is considered 0.

// Constraints:

// 0 <= num <= 3000
// 0 <= k <= 9

class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        int i = 1;
        if (num == 0)
            return 0;
        if (k == 0 && num % 10 != 0)
            return -1;
        num = num - k;
        while (num >= 0 && num % 10 != 0)
        {
            num = num - k;
            i = i + 1;
        }
        if (num < 0)
            return -1;
        else
            return i;
    }
};

int main()
{
    Solution solution;
    int num, k;
    std::cout << "Enter the value of num: ";
    std::cin >> num;
    std::cout << "Enter the value of k: ";
    std::cin >> k;
    int result = solution.minimumNumbers(num, k);
    if (result == -1)
        std::cout << "It's not possible to reach a number divisible by 10." << std::endl;
    else
        std::cout << "Minimum number of steps required: " << result << std::endl;
    return 0;
}

// Certainly! Let's break down the mathematics behind the minimumNumbers function.

// The function aims to find the minimum number of steps required to reduce a given number num to a number divisible by 10 by subtracting k at each step.

// Initial Checks:

// The function checks if num is already 0. If it is, it returns 0 immediately because no steps are needed.
// It then checks if k is 0 and num is not already divisible by 10. If this condition is met, it returns -1 because it's impossible to reach a number divisible by 10 by subtracting 0.
// Subtraction Loop:

// The function subtracts k from num.
// It enters a loop where it continues subtracting k from num until num becomes negative or divisible by 10.
// The loop also counts the number of steps taken in the variable i.
// Result Evaluation:

// If num becomes negative during the loop, it means it's not possible to reach a number divisible by 10, so the function returns -1.
// Otherwise, it returns the count i of steps taken.
// Now, let's analyze why this algorithm works mathematically:

// We are given a starting number num, and we want to reach a number that is divisible by 10.
// We subtract k from num repeatedly until we reach a number that is divisible by 10 or until num becomes negative.
// At each step, k is subtracted, so the resulting number will be of the form num - k*x, where x is the number of steps taken.
// We want to find the minimum number of steps x such that (num - k*x) is divisible by 10.
// This problem can be seen as finding the smallest non-negative integer x such that (num - k*x) is divisible by 10.

// If (num - k*x) is already divisible by 10, then we've found the solution, and x is the minimum number of steps.
// If (num - k*x) is not divisible by 10, we continue subtracting k until we reach a number that is divisible by 10 or until num becomes negative.
// Therefore, the algorithm essentially iterates by subtracting k from num until num becomes divisible by 10 or until it becomes negative, keeping track of the number of steps taken.