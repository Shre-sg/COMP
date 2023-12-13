#include <iostream>
#include <map>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    // Add any other necessary members
};




//algo :
// WE WILL CONVERT TREE INTO STRING THEN STORE IT N MAP IF MAP HAS ONLY ONE FREQ THEN OTS NOT DUPLICATE

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
 map<string, int>mp;
 
 string solve(Node* root){
        if(!root) 
            return "$";   //RETURN RANDOM 
        
        string s="";   //STORES THE STRING THAT ADDS TO THE MAP
        if(!root->right and !root->left){  //IF IT HAS LEFT NODE ITS BASE CASE
            s+=to_string(root->data);
            return s;
        }
        
        s+=to_string(root->data); //COVERTING IT INTO STR THEN ADDED TO S
        s+='/';  
        s+=solve(root->left);
        s+='/';                  //THESE VALES IS ADDED TO STR TO SEPARATE ONE ROOT ELE FROM OTHER
        s+=solve(root->right);   ///12 ONE ELE , WE DONT WANT TO CONFUSE OF 1 2 OR SEPARTE IR LEFT AND RIGHT
        
        mp[s]++;    //ADDED TO MAP
        return s;
    }

    int dupSub(Node *root) {
        
        solve(root);
        
        for(auto it:mp)   ///CHECKING IT HAS DUPLICATE IN MAP IF FREQ IS 2 OR MORE
            if(it.second>=2) 
                return true;
        
        return false;
    }
};

int main() {
    // Create a sample binary tree
    Solution sol;
    Node* root = new Node{
        1,
        new Node{2, nullptr, nullptr},
        new Node{3,
                 new Node{4, nullptr, nullptr},
                 new Node{2,
                          new Node{4, nullptr, nullptr},
                          new Node{4, nullptr, nullptr}}}};
                          
    // Test whether the binary tree has duplicate subtrees
    if (sol.dupSub(root)) {
        cout << "The binary tree has duplicate subtrees.\n";
    } else {
        cout << "The binary tree does not have duplicate subtrees.\n";
    }

    // TODO: Free the allocated memory for the tree nodes (not shown in this simple example)

    return 0;
}
