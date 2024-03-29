/*给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
示例 1：
l
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：

输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        for(int i = 1;i < nums.size();i++){
            if((nums[i] - nums[i-1])==1) dp[i] = dp[i-1]+1;
            else if(nums[i]==nums[i-1]) dp[i] = dp[i-1];
            //其他情况就不更新
        }

        int res = INT_MIN;
        for(const auto num:dp){
            res = max(num,res);
        }

        return res;
    }
};