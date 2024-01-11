
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

class Solution {
public:
    int ans = INT_MIN;
    int depth(TreeNode* root){
        if(!root) return 0;
        //应该是后续遍历
        //当前结点收集子节点的结果
        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(1+left+right,ans);//这里是算的路径结点上的个数

        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans-1;
    }
};
