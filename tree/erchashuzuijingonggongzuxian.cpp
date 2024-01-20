class Solution {
private:
    TreeNode* node1;
    TreeNode* node2;
    TreeNode* ans = nullptr;

public:
    bool helper(TreeNode* node){
        if(node == nullptr) return false;
        //后序遍历,先搜到最底部，然后往上返回
        bool leftFlag = traversal(node->left);//左边搜到了
        bool rightFlag = traversal(node->right);//右边搜到了
        if(leftFlag == true && rightFlag == true|| node == node1 || node == node2){
            ans = node;//公共祖先是本身也不要紧，公共祖先先被下层的那个赋值了，到上层也会被替换掉的。
            return true;//给上面说搜到
        }
        return leftFlag || rightFlag;//只有搜到一个就给上面说搜到
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        node1 = p;
        node2 = q;

    }
};