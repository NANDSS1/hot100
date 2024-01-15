class Solution {
public:
    vector<TreeNode*> vec;
    void helper(TreeNode* node){
        //前序遍历 中左右
        if(node == nullptr) return;
        vec.push_back(node);
        helper(node->left);
        helper(node->right);
    }
    void flatten(TreeNode* root) {
        //链表的顺序与二叉树先序遍历相同
        helper(root);
        for(int i = 0;i < vec.size()-1;i++){
            vec[i]->left = nullptr;
            vce[i]->right = vec[i+1];
        }
        vec.back()->left = nullptr;
        vec.back()->right = nullptr;
    }
};