#include <iostream>

class Solution
{
public:
    double myPow(double x, int n)
    {

        double ans = 1.0; // Initialise answer with base value of 1.0

        long long nn = n; // Duplicate of the power(n)
        if (nn < 0)
            nn *= -1; // If power is -ve make it +ve

        while (nn > 0)
        { // Loop runs till power is greater than 0

            if (nn % 2 == 0)
            {              // Checks if power is even
                x = x * x; // Square the value x
                nn /= 2;   // Divide the power in half
            }
            else
            {             // If power is odd
                ans *= x; // Multiply x to the answer
                nn--;     // Decrease the power by 1 thus making it even
            }
        }
        if (n < 0)
            ans = 1 / ans; // If power is negative divide 1 by the answer
        return ans;        // Return the answer
    }
};

int main()
{
    Solution sol;
    double base = 2.0;
    int exponent = 10;

    std::cout << "Power of " << base << " raised to " << exponent << " is: " << sol.myPow(base, exponent) << std::endl;

    return 0;
}
