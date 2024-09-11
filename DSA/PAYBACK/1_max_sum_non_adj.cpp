// Maximum sum of nodes in Binary tree such that no two are adjacent
// Last Updated : 09 Mar, 2023
// Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of selected nodes is maximum under a constraint that no two chosen nodes in the subset should be directly connected, that is, if we have taken a node in our sum then we can’t take any of its children in consideration and vice versa

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

int sumOfGrandChildren(Node *node, unordered_map<Node *, int> &memo);

int getMaxSumUtil(Node *node, unordered_map<Node *, int> &memo)
{
    if (!node)
        return 0;

    if (memo.count(node))
        return memo[node];

    int incl = node->data + sumOfGrandChildren(node, memo);
    int excl = getMaxSumUtil(node->left, memo) + getMaxSumUtil(node->right, memo);

    memo[node] = max(incl, excl);
    return memo[node];
}

int sumOfGrandChildren(Node *node, unordered_map<Node *, int> &memo)
{
    int sum = 0;

    if (node->left)
    {
        sum += getMaxSumUtil(node->left->left, memo);
        sum += getMaxSumUtil(node->left->right, memo);
    }

    if (node->right)
    {
        sum += getMaxSumUtil(node->right->left, memo);
        sum += getMaxSumUtil(node->right->right, memo);
    }

    return sum;
}

int getMaxSum(Node *root)
{
    unordered_map<Node *, int> memo;
    return getMaxSumUtil(root, memo);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);

    cout << getMaxSum(root) << endl;
    return 0;
}
