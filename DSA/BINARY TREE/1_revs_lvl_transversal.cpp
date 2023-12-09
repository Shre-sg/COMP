#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Given a binary tree of size N, find its reverse level order traversal. ie- the traversal
// must begin from the last level.

// Example 1:
// Input :
//         1
//       /   \
//      3     2

// Output: 3 2 1
// Explanation:
// Traversing level 1 : 3 2
// Traversing level 0 : 1

// Example 2:
// Input :
//        10
//       /  \
//      20   30
//     / \ 
//    40  60

// Output: 40 60 20 30 10
// Explanation:
// Traversing level 2 : 40 60
// Traversing level 1 : 20 30
// Traversing level 0 : 10

// Your Task: 
// You dont need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)




vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        ans.push_back(temp->data);

        if(temp->right){                  ///only  difff
            q.push(temp->right);
        }
        if(temp->left){                    ///only difff
            q.push(temp->left);
        }
    }
    reverse(ans.begin(),ans.end());   ///this also neww
    return ans;
}

int main() {
    Node* root = new Node{1, new Node{2, new Node{4, nullptr, nullptr}, new Node{5, nullptr, nullptr}}, new Node{3, nullptr, nullptr}};
    vector<int> result = reverseLevelOrder(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
