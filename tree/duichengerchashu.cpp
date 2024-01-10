#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(TreeNode* left,TreeNode* right){
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right == nullptr) return true;//到底了
        else if(left->val != right->val) return false;
        
        bool inside = isValid(left->right,right->left);
        bool outside = isValid(left->left, right->right);

        return inside&&outside;
    }
    bool isSymmetric(TreeNode* root) {
        //从上到下遍历
        if(root == nullptr) return false;
        return isValid(root->left, root->right);
    }
};