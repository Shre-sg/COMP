#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}








// Approach:

// The algorithm approach can be stated as:

// Create a map to store the inorder indexes.
// Call the function constructTree with all 7 parameters as shown above.
// In the recursive function, first check the base case, if (preStart,>preEnd || inStart> inEnd) 
//then return NULL.
// Construct a node (say root) with the root value( first element of preorder). 
// Find the index of the root, say elem from the hashmap.
// Find the number of elements ( say nElem) in the left subtree  = elem – inStart
//  Call recursively for the left subtree with correct values (shown in the above table) and
// store the answer received in root->left.
// Call recursively for the right subtree with correct values (shown in the above table) and 
//store the answer received in root->right.
// Return root
// Dry Run: To understand a detailed dry run of this approach, please watch the video attached below.





node * constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
 
  if (preStart > preEnd || inStart > inEnd) 
    return NULL;

  node * root = newNode(preorder[preStart]);
  int elem = mp[root -> data];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp);
  
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root;
}

node * buildTree(vector < int > & preorder, vector < int > & inorder) {
  
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}

int main() {

  vector<int> preorder{10,20,40,50,30,60};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(preorder, inorder);
  return 0;
}