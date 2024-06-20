#include <iostream>
#include <vector>
#include <algorithm>


// 1552. Magnetic Force Between Two Balls

// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.

 

// Example 1:


// Input: position = [1,2,3,4,7], m = 3
// Output: 3
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
// Example 2:

// Input: position = [5,4,3,2,1,1000000000], m = 2
// Output: 999999999
// Explanation: We can use baskets 1 and 1000000000.
 

// Constraints:

// n == position.length
// 2 <= n <= 105
// 1 <= position[i] <= 109
// All integers in position are distinct.
// 2 <= m <= position.length


class Solution {
public:
    int maxDistance(std::vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        
        int minF = 1;
        int maxF = (position[position.size()-1] - position[0]);
        int ans = 1;
        
        while (minF <= maxF) {
            int midF = minF + (maxF - minF) / 2;
            if (canWePlace(position, midF, m)) {
                ans = midF;
                minF = midF + 1;
            } else {
                maxF = midF - 1;
            }
        }
        return ans;
    }

private:
    bool canWePlace(const std::vector<int>& arr, int force, int balls) {
        int countBalls = 1;
        int lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int cur = arr[i];
            if (cur - lastPlaced >= force) {
                countBalls++;
                lastPlaced = cur;
            }
            if (countBalls >= balls) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;

    Solution solution;
    int result = solution.maxDistance(position, m);
    
    std::cout << "The maximum minimum force is: " << result << std::endl;
    
    return 0;
}
