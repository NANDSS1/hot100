/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/
#include<bits/stdc++.h>
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtracking(int n,int index,vector<int>& nums){
        //每到一层都收集一次path，path的大小等于nums.size()时返回
        //相对顺序不变的，所以要有个index
        ans.push_back(path);
        if(path.size() == n){
            return;
        }
        for(int i = index;i < n;i++){
            path.push_back(nums[i]);
            backtracking(n,i+1,nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums.size(),0,nums);
        return ans;
    }
};