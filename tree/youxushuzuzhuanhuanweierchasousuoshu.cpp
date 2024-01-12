class Solution {
    //本题利用前序遍历构造二叉树，需要首先找到mid结点

    //正常用中序遍历就可以把二叉搜索树转换成升序数组
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }

    TreeNode* helper(vector<int>& nums,0,nums.size()-1){
        
    }

};