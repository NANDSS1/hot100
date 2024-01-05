/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp应该就能做
        int n = nums.size();
        vector<int> dp(n,0);//dp表示以索引i结尾的最大的连续子数组和
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i = 1;i < nums.size();i++){
            dp[i] = max(nums[i],nums[i]+dp[i-1]);//和前一个元素连续在一起，还在只选自己
            ans = max(ans,dp[i]);
        }

        return ans;
        //不是返回最后一个元素，是返回最大值
    }
}; 