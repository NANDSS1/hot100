class Solution {
public:
    int rootSum(TreeNode* root,long targetSum){//定了起点再定方向搜索
        if(!root) return 0;
        int ret = 0;
        if(root->val==targetSum) ret++; //中序遍历
        ret+=rootSum(root->left,targetSum-root->val);
        ret+=rootSum(root->right,targetSum-root->val);
        return ret;
    }
    
    int pathSum(TreeNode* root, long targetSum) {
        if(!root) return 0;
        int ret = 0;
        ret+=rootSum(root,targetSum);//当前结点作为起点
        ret+=pathSum(root->left,targetSum);//子结点作为起点
        ret+=pathSum(root->right,targetSum);//子结点作为起点
        return ret;
    }
};