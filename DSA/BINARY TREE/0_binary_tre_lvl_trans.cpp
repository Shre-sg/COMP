#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

//Defining the Node class
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    //Constructor
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Given a binary tree, find its level order traversal.
// Level order traversal of a tree is breadth-first traversal for the tree.


// Example 1:

// Input:
//     1
//   /   \ 
//  3     2
// Output:1 3 2
// Example 2:

// Input:
//         10
//      /      \
//     20       30
//   /   \
//  40   60
// Output:10 20 30 40 60

// Your Task:
// You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)


// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 105




//Your Solution class
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
     vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> rst;    //to store ans
      queue<Node*> qu;    //  r---> Q U E <---f
      
      qu.push(node);
      
      while(!qu.empty()){
          
          Node* node = qu.front();
          rst.push_back(node->data);     //adding out ans
          
          qu.pop();       ///then pop it 
          
          if(node->left){
              qu.push(node->left);
          }
          
          if(node->right){
              qu.push(node->right);
          }
      }
      
      return rst;
    }
};

//Main code
int main()
{
    //Creating a tree object
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    //Creating a solution object
    Solution sol;

    //Calling the levelOrder function and storing the result in a vector
    vector<int> result = sol.levelOrder(root);

    //Printing the result
    cout << "The level order traversal of the tree is: " << endl;
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
