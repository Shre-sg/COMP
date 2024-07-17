#include <iostream>
#include <vector>
using namespace std;

// 204. Count Primes
// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0

// Constraints:

// 0 <= n <= 5 * 106

// SEIVIE ERTHROSIS METTHOD
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> prime(n, true);
        int count = 0;
        for (int i = 2; i * i < n; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
                count++;
        }
        return count;
    }
};

int main()
{
    Solution solution;

    // Test cases
    cout << "Number of primes less than 10: " << solution.countPrimes(10) << endl;   // Expected output: 4
    cout << "Number of primes less than 20: " << solution.countPrimes(20) << endl;   // Expected output: 8
    cout << "Number of primes less than 30: " << solution.countPrimes(30) << endl;   // Expected output: 10
    cout << "Number of primes less than 50: " << solution.countPrimes(50) << endl;   // Expected output: 15
    cout << "Number of primes less than 100: " << solution.countPrimes(100) << endl; // Expected output: 25

    return 0;
}
