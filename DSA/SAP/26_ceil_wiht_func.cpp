#include <iostream>

// Function to calculate val based on given values of a and b
int calculateVal(int a, int b)
{
    // Calculate val based on the logic described
    int val = a / b;
    if (a % b != 0)
    {
        val += 1;
    }
    return val;
}

int main()
{
    // Example values for a and b
    int a = 10;
    int b = 3;

    // Calculate val using the function
    int val = calculateVal(a, b);

    // Output the values for demonstration
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
    std::cout << "a % b = " << (a % b) << std::endl;
    std::cout << "val = " << val << std::endl;

    return 0;
}
