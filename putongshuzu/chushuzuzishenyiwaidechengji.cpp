/*
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

 

示例 1:

输入: nums = [1,2,3,4]
输出: [24,12,8,6]
示例 2:

输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //左缀积 右缀积
        int n = nums.size();
        vector<int> l(n,0),r(n,0);
        //l r表示i索引左边和右边的累积乘积，不含i
        //初始化 l 和 r
        l[0] = 1;
        r[r.size()-1] = 1;
        for(int i = 1;i < n;i++){
            l[i] = nums[i - 1]*l[i - 1];
        }
        for(int i = n-2;i >= 0;i--){
            r[i] = nums[i+1]*r[i+1];
        }
        vector<int> ans;
        for(int i = 0;i < n;i++){
            ans.push_back(l[i]*r[i]);
        }

        return ans;
    }
};