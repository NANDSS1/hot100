//前序遍历

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(TreeNode* node){
        if(node == nullptr) return;
        swap(node->left,node->right);
        helper(node->left);
        helper(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};