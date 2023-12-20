#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

//The diameter of a tree (sometimes called the width) is the number of nodes on the longest path 
//between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that 
//form the ends of the longest path are shaded (note that there is more than one path in each 
//tree of length nine, but no path longer than nine nodes). 

// Example 1:
// Input:
//        1
//      /  \
//     2    3
// Output: 3

// Example 2:
// Input:
//          10
//         /   \
//       20    30
//     /   \ 
//    40   60
// Output: 4
// Your Task:
// You need to complete the function diameter() that takes root as parameter and returns the diameter.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= Number of nodes <= 10000
// 1 <= Data of a node <= 1000

int solve(Node * root,int &ans){ // uts the height of the tree of tree func,
        
    if(root == NULL)
        return 0;

    int left = solve(root->left,ans);
    int right = solve(root->right,ans);

    ans  = max(ans,left+right+1);  //only this counts the width of the treee

    return max(left,right)+1;
}

int diameter(Node* root) {
    int ans = 0;  ///stroes width

    int res = solve(root,ans);  ///stores the height

    return ans;
}

int main() {
    Node* root = new Node{1, new Node{2, new Node{4, nullptr, nullptr}, new Node{5, nullptr, nullptr}}, new Node{3, nullptr, nullptr}};
    cout << "Diameter of tree is " << diameter(root) << endl;
    return 0;
}
