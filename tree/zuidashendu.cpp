#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int ans = 0;
    void helper(TreeNode* node, int depth){
        if(node == nullptr) return;
        ans = max(ans, depth);
        helper(node->left, depth + 1);
        helper(node->right, depth + 1);
    }
public:
    int maxDepth(TreeNode* root) {
        helper(root, 1);
        return ans;
    }
};