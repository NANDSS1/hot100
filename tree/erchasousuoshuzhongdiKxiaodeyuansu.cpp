class Solution {
public:
    int count = 0;
    int val = -1;
    void helper(TreeNode* node, int k) {
        if (node == nullptr) return;//count只是遍历的个数
        helper(node->left, k);
        count++;//count放这个位置就行了，实际遍历到要开始操作的节点的时候才赋值
        if (count == k) {
            val = node->val;
            return;
            //你的代码应该在 count 等于 k 时立刻返回，以防止继续遍历右子树.上一层也会赋值
        }
        helper(node->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return val;
    }
};