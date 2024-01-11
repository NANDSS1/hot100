class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //二叉树的层序遍历，先把根节点放进队列
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> ans;
        while(!que.empty()){
            int size = que.size();
            vector<int> path;
            //一个for是一层
            for(int i = 0;i < size;i++){
                TreeNode* temp = que.front();
                que.pop();
                path.push_back(temp->val);  // 修改这里
                if(temp->left != nullptr) {
                    que.push(temp->left);
                }
                if(temp->right != nullptr){
                    que.push(temp->right);
                }
            }
            ans.push_back(path);
        }

        return ans;
    }
};
