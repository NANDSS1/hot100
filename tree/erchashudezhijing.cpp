
#include<bits/stdc++.h>
using namespace std;

/*
只考虑了通过根节点的情况，但是最后不一定通过根节点~
class Solution {
public:
    int ans = 0;
    void maxDepth(TreeNode* node,int depth){
        if(node == nullptr){
            return;
        }
        //中
        ans = max(ans,depth);
        maxDepth(node->left, depth+1);
        maxDepth(node->right, depth+1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //计算左子树的最大深度和右子树的最大深度
        ans = 0;
        maxDepth(node->left,1);
        int left = ans;
        ans = 0
        maxDepth(node->right,1);
        int right = ans;

        return left+right;
    }
};
*/
