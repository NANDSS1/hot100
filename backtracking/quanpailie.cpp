#include<bits/stdc++.h>
using namespace std;
/*示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtracking(int n,vector<int>& nums,vector<bool>& used){
        if(path.size() == n){
            ans.push_back(path);
            return;
        }
        for(int i = 0;i < n;i++){
            if(used[i] == true) continue;
            //used[i]不为true时
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(n,nums,used);
            used[i] = false; 
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //加个used[i];
        //每层回溯收集元素都从第一个开始
        vector<bool> used(nums.size(),false);
        backtracking(nums.size(),nums,used);
        return ans;
    }
};