#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> ans;
    void helper(TreeNode* node){
        //中序遍历，前中后
        if(node == nullptr) return;
        helper(node->left);
        ans.push_back(node->val);
        helper(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //递归
        helper(root);
        return ans;
    }
};