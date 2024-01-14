class Solution {
    //本题利用前序遍历构造二叉树，需要首先找到mid结点

    //正常用中序遍历就可以把二叉搜索树转换成升序数组
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }

    TreeNode* helper(vector<int>& nums,int left,int right){
        //分治思想
        if(left > right){
            return nullptr;
        }
        //中序遍历
        int mid = (left + right)/2;
        //建立根节点
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);//左子树
        root->right = helper(nums, mid + 1, right);//右子树
        return root;
    }

};