#include<bits/stdc++.h>
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //层序遍历
        if(root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = que.front();
                que.pop();
                if(i == (size-1))ans.push_back(temp->val);
                if(temp->left!=nullptr)que.push(temp->left);
                if(temp->right!=nullptr)que.push(temp->right);
            }
        }
        return ans;
    }
};