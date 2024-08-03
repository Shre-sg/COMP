#include <iostream>
#include <bits/stdc++.h>

// There are n processes to be executed, and the process has a size of processSize[i] Also, there are m processors of different size capacity. The capacity of the processor is capacity[i]. A processor can process a task of size less than or equal to its capacity in 1 second, but it cannot execute processes whose size is greater than its capacity,

// Complete the getMinimumTime' function below.
// The function is expected to return an INTEGER.
// The function accepts following parameters:
// INTEGER ARRAY processSize
// INTEGER ARRAY capacity
// A processor can execute multiple processes one after the other. but needs to pause for 1 second after completing its current one. Multiple processors can work on different processes simultaneously.

// Find the minimum time to execute the processes or return -1 if there is no way to execute all the processes.

// Example

// It is given that n=3, processSize = [2, 5, 3], m3 and capacity = 16, 2,41

// The optimal way to assign processes is to give the first processor the second process, the second processor the first process, and the third processor the third process. All of them complete their processes in 1 second.

// Therefore, the minimum time required is 1 second
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the minimum time required to execute all processes
int getMinimumTime(vector<int> &processSize, vector<int> &capacity)
{
    // Sort process sizes and processor capacities in ascending order
    sort(processSize.begin(), processSize.end());
    sort(capacity.begin(), capacity.end());

    int p = 0;     // Index for processors
    int j = 0;     // Index for processes
    int count = 0; // Count of time units

    // If the largest process cannot fit in the largest processor, return -1
    if (processSize[processSize.size() - 1] > capacity[capacity.size() - 1])
    {
        return -1;
    }

    // Loop through all processors
    while (j < processSize.size())
    {
        // Assign process to processor if it fits
        if (processSize[j] <= capacity[p])
        {
            p++;
            j++;
        }
        else
        {
            p++;
        }

        // If all processors have been used, increment time and reset processor index
        if (p == capacity.size())
        {
            count++;
            p = 0;
        }
    }

    // Increment count for the last set of processes (if not empty)
    if (p > 0)
    {
        count++;
    }

    return count;
}

int main()
{
    vector<int> processSize = {2, 5, 3}; // Sizes of processes
    vector<int> capacity = {16, 2, 41};  // Capacities of processors

    // Compute the minimum time required to execute all processes
    int result = getMinimumTime(processSize, capacity);

    // Output the result
    cout << "Minimum time required: " << result << endl; // Expected output: 1

    return 0;
}
