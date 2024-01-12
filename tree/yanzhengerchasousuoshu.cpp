class Solution {
public:
    vector<int> vec;
    void helper(TreeNode* node){
        if(node == nullptr) return ;

        helper(node->left);
        vec.push_back(node->val);
        helper(node->right);
    }

    bool isValidBST(TreeNode* root) {
        //中序遍历就能把二叉搜索树转换为升序数组
        //左 中 右
        helper(root);
        
        for(int i = 1;i < vec.size();i++){
            if(nums[i] < nums[i-1]) return false;//他这里要严格递增
        }

        return true;
    }
};